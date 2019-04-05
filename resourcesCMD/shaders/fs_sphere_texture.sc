uniform sampler2D s_sphereMap;

varying vec2      v_texcoord0;

void main()
{
    vec2 coord;
    coord.x = v_texcoord0.x;
    coord.y = 1.0 - v_texcoord0.y;
    vec3 color;
    color = texture2D(s_sphereMap, coord).xyz;
    color = color/(color + vec3(1.0));
    color = pow(color, vec3(1.0/2.2));

    gl_FragColor = vec4(color, 1.0);
}