#version 330 core


uniform vec4 ortho_size;

uniform vec2 spriteSize;
uniform mat3 model;

in vec2 vertexPosition;

out vec2 uv;

const float near = 0.00000f, far = 1000.f;

#define PI_6 0.52359877559
#define PI_4 0.78539816339

void main() {
    float left = screenSize.x;
    float right = screenSize.y;
    float bottom = screenSize.z;
    float top = screenSize.w;

    mat4 proj = mat4(
    vec4(2. / (right - left), 0., 0., 0.),
    vec4(0., 2. / (top - bottom), 0., 0.),
    vec4(0., 0., -2. / (far - near), 0.),
    vec4(-(right+left)/(right - left), -(top+bottom)/(top-bottom), -(far+near)/(far-near), 1.)
    );

    uv = vertexPosition + vec2(.5);

    vec4 pos = vec4(model * vec3(vertexPosition * spriteSize, 1.), 1.);
    pos = proj * view * pos;
    //    pos.y =  - pos.y;
    //    pos.z = 0. - pos.z -1.;

    gl_Position = pos;
}