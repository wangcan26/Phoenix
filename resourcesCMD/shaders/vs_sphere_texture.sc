attribute vec3 a_position;
attribute vec2 a_texcoord0;
uniform   mat4 u_modelViewProj;

varying   vec2 v_texcoord0;

void main()
{
    vec4 tmpvar_1;
    tmpvar_1.w = 1.0;
    tmpvar_1.xyz = a_position;
    gl_Position = (u_modelViewProj*tmpvar_1);
    v_texcoord0 = a_texcoord0;
}