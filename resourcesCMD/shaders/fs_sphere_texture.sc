uniform sampler2D s_sphereMap;

varying vec2      v_texcoord0;

void main()
{
    vec2 coord;
    coord.x = v_texcoord0.x;
    coord.y = 1.0 - v_texcoord0.y;
    vec4 color;
    color.w = 1.0;
    color.xyz = texture2D(s_sphereMap, coord).xyz;
    gl_FragColor = color;
}