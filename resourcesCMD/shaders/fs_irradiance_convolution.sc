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



void main()
{
    vec2 uv = v_texcoord0;
    //convert uv to sphere normal
    vec3 normal = uv2SphereNormal(uv);

    vec3 irradiance = vec3(0.0);
    //tangent space calculation from origin point
    vec3 up = vec3(0.0, 1.0, 0.0);
    vec3 right = cross(up, normal);
    up = cross(normal, right);

    float sampleDelta = 0.0125;
    float nrSamples = 0.0;
    for(float phi = 0.0; phi < 2.0*PI; phi += sampleDelta)
    {
        for(float theta = 0.0; theta < 0.5*PI; theta += sampleDelta)
        {
            //spherical to castesian (in tangent space)
            vec3 tangentSample = vec3(sin(theta)*cos(phi), sin(theta)*sin(phi), cos(theta));
            //tanget space to world
            vec3 sampleVec = tangentSample.x * right + tangentSample.y * up + tangentSample.z * normal;
            //convert sphere normal to uv
            vec2 sampleUV = sphereNormal2UV(sampleVec);

            irradiance += texture2D(s_hdrMap, sampleUV).rgb * cos(theta)*sin(theta);
            nrSamples++;
        }
    }

    irradiance = PI*irradiance*(1.0/float(nrSamples));

    gl_FragColor = vec4(irradiance, 1.0);
}