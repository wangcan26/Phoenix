attribute vec3 a_position;
attribute vec2 a_texcoord0;
uniform   mat4 u_viewProj;

varying   vec2 v_texcoord0;

void main()
{
    gl_Position = u_viewProj*vec4(a_position, 1.0);
    v_texcoord0 = a_texcoord0;
}