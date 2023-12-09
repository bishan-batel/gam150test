#version 330 core

uniform sampler2D tex;

out vec4 fragColor;
in vec2 vertexUV;

void main() {
    //    vec4 col =  texture(tex, vertexUV);
    //    fragColor = col * col.a;
    //    fragColor = vec4(vec3(col.a), 1.f);

    vec4 col =  texture(tex, vertexUV);
    if (col.a < 0.01f) {
        discard;
    }

    fragColor = col;
}