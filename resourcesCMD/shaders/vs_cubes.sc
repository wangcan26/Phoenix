attribute vec4 a_color0;
attribute vec3 a_position;
varying   vec4 v_color0;
uniform   mat4 u_modelViewProj;
void main()
{
    vec4 tmpvar_1;
    tmpvar_1.w = 1.0;
    tmpvar_1.xyz = a_position;
    gl_Position = (u_modelViewProj*tmpvar_1);
    v_color0 = a_color0;
}