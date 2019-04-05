varying vec3 v_worldPos;
uniform samplerCube s_cubeMap;

void main()
{
    vec3 envColor = textureCube(s_cubeMap, v_worldPos).rgb;
    //HDR tonemap and gamma correct
    envColor = envColor/(envColor + vec3(1.0));
    envColor = pow(envColor, vec3(1.0/2.2));
    gl_FragColor = vec4(envColor, 1.0);
}