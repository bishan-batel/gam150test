#version 330 core


uniform vec3 model;

in vec2 a_Pos;

out vec2 vertexUV;


void main() {
    vertexUV = a_Pos + vec2(.5);
    gl_Position = vec4((a_Pos + model.xy) / (2 + model.z), model.z, 1.);
}