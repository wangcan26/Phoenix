attribute vec3 a_position;
attribute vec2 a_texcoord0;
uniform   mat4 u_proj;
uniform   mat4 u_view;

varying   vec3  v_worldPos;

void main()
{
    v_worldPos = a_position;
    mat4 rotView = mat4(mat3(u_view));
    vec4 clipPos = u_proj*rotView*vec4(v_worldPos, 1.0);
    gl_Position = clipPos.xyzw;
}