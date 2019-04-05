#extension GL_EXT_shader_texture_lod : require
uniform sampler2D s_hdrMap;
varying vec2      v_texcoord0;

#define PI 3.14159265359

vec3 uv2SphereNormal(vec2 uv)
{
    float phi = PI*(1.0-uv.y);
    float theta = 2.0*PI*(uv.x) - 0.5*PI;
    vec3 normal;

    float r = sin(phi);
    normal.y = cos(phi);
    normal.x = r*cos(theta);
    normal.z = r*sin(theta);

    return normal;
}

vec2 sphereNormal2UV(vec3 normal)
{
    return vec2(1.0-(atan(normal.x, normal.z) / PI + 1.0) * 0.5, acos(normal.y) / PI);
}

float DistributionGGX(vec3 N, vec3 H, float roughness)
{
    float a = roughness*roughness;
    float a2 = a*a;
    float NdotH = max(dot(N, H), 0.0);
    float NdotH2 = NdotH*NdotH;

    float nom   = a2;
    float denom = (NdotH2 * (a2 - 1.0) + 1.0);
    denom = PI * denom * denom;

    return nom / denom;
}


float VanDerCorpus(int n, int base)
{
    float invBase = 1.0 / float(base);
    float denom   = 1.0;
    float result  = 0.0;

    for(int i = 0; i < 32; ++i)
    {
        if(n > 0)
        {
            denom   = mod(float(n), 2.0);
            result += denom * invBase;
            invBase = invBase / 2.0;
            n       = int(float(n) / 2.0);
        }
    }

    return result;
}

vec2 Hammersley(int i, int N)
{
    return vec2(float(i)/float(N), VanDerCorpus(i, 2));
}

vec3 ImportanceSampleGGX(vec2 Xi, vec3 N, float roughness)
{
    float a = roughness*roughness;
    float phi = 2.0*PI*Xi.x;
    float cosTheta = sqrt((1.0-Xi.y)/(1.0 + (a*a - 1.0)*Xi.y));
    float sinTheta = sqrt(1.0 - cosTheta*cosTheta);

    vec3 H;
    H.x = cos(phi)*sinTheta;
    H.y = sin(phi)*sinTheta;
    H.z = cosTheta;

    //from tangent-space H vector to world-space sample vector
    vec3 up = abs(N.z) < 0.999 ? vec3(0.0, 0.0, 1.0):vec3(1.0, 0.0, 0.0);
    vec3 tangent = normalize(cross(up, N));
    vec3 bitangent = cross(N, tangent);

    vec3 sampleVec = tangent*H.x + bitangent*H.y + N*H.z;
    return normalize(sampleVec);
}

void main()
{
    float l_roughness = 0.2;
    vec2 uv = v_texcoord0;
    //convert uv to sphere normal
    vec3 N = uv2SphereNormal(uv);

    vec3 R = N;
    vec3 V = R;
    const int SAMPLE_COUNT = 2048;
    vec3  prefilteredColor = vec3(0.0);
    float totalWeight = 0.0;

    for(int i = 0; i < SAMPLE_COUNT; ++i)
    {
        vec2 Xi = Hammersley(i, SAMPLE_COUNT);
        vec3 H = ImportanceSampleGGX(Xi, N, l_roughness);
        vec3 L = normalize(2.0*dot(V, H)*H - V);

        float NdotL = max(dot(N, L), 0.0);

        if(NdotL > 0.0)
        {
            float D = DistributionGGX(N, H,  l_roughness);
            float NdotH = max(dot(N, H), 0.0);
            float HdotV = max(dot(H, V), 0.0);
            float pdf = D * NdotH /(4.0*HdotV) + 0.0001;

            //Compute miplevel
            float resolution_w = 3600.0;
            float resolution_h = 1800.0;
            float saTexel = 4.0*PI/(resolution_w*resolution_h);
            float saSample = 1.0/(float(SAMPLE_COUNT)*pdf + 0.0001);

            float mipLevel = l_roughness == 0.0 ? 0.0: 0.5*log2(saSample/saTexel);


            //Covert L to uv
            vec2 sampleUV = sphereNormal2UV(L);

            vec3 texColor = texture2DLodEXT(s_hdrMap, sampleUV, mipLevel).rgb;

            prefilteredColor +=  texColor* NdotL;
            totalWeight += NdotL;
        }
    }

    prefilteredColor = prefilteredColor/totalWeight;
    //Apply Gamma
    //vec3 color;
    //color = pow(prefilteredColor, vec3(1.0/2.2));

    gl_FragColor = vec4(prefilteredColor, 1.0);
}