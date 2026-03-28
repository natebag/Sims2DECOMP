// 0x8038CBC8 (28 bytes) - GXGetLightPos
typedef struct GXLightObj {
    char pad[40];
    float px, py, pz; // 0x28, 0x2C, 0x30
} GXLightObj;
void GXGetLightPos(GXLightObj* l, float* x, float* y, float* z) {
    *x = l->px;
    *y = l->py;
    *z = l->pz;
}
