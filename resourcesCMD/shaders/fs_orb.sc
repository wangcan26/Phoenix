uniform sampler2D s_albedo;

varying vec2      v_texcoord0;

void main()
{
    vec2 coord;
    coord.x = v_texcoord0.x;
    coord.y = v_texcoord0.y;
    vec4 color;
    color.w = 1.0;
    color.xyz = texture2D(s_albedo, coord).xyz;
    gl_FragColor = color;
}