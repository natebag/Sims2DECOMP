// COMPILER: mwcc
// 0x803741D0 C_MTXPerspective (208B) — Dolphin SDK mtx/mtx44.c
//
// Builds a 4x4 perspective projection matrix from a vertical FOV (degrees),
// aspect ratio and near/far planes. MWCC GC-1.2.5n.

typedef float Mtx44[4][4];

extern "C" float tanf(float);

extern "C" void C_MTXPerspective(Mtx44 m, float fovY, float aspect, float n, float f) {
    float angle;
    float cot;
    float tmp;

    angle = fovY * 0.5f;
    angle = angle * 0.01745329252f;
    cot = 1.0f / tanf(angle);

    m[0][0] = cot / aspect;
    m[0][1] = 0.0f;
    m[0][2] = 0.0f;
    m[0][3] = 0.0f;

    m[1][0] = 0.0f;
    m[1][1] = cot;
    m[1][2] = 0.0f;
    m[1][3] = 0.0f;

    tmp = 1.0f / (f - n);
    m[2][0] = 0.0f;
    m[2][1] = 0.0f;
    m[2][2] = -n * tmp;
    m[2][3] = -(f * n) * tmp;

    m[3][0] = 0.0f;
    m[3][1] = 0.0f;
    m[3][2] = -1.0f;
    m[3][3] = 0.0f;
}
