// 0x8038C910 (28 bytes) - GXGetLightAttnA
typedef struct GXLightObj {
    char pad[16];
    float a0, a1, a2; // 0x10, 0x14, 0x18
} GXLightObj;
void GXGetLightAttnA(GXLightObj* l, float* a0, float* a1, float* a2) {
    *a0 = l->a0;
    *a1 = l->a1;
    *a2 = l->a2;
}
