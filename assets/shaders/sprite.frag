#version 330 core

uniform sampler2D tex;

out vec4 fragColor;
in vec2 uv;

void main() {
    fragColor = texture(tex, uv);
}