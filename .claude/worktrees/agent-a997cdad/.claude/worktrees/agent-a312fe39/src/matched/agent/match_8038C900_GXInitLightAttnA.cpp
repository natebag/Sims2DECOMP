// 0x8038C900 (16 bytes) - GXInitLightAttnA
// stfs f1, 16(r3); stfs f2, 20(r3); stfs f3, 24(r3); blr

typedef struct GXLightObj {
    char pad[16]; // 0x00-0x0F
    float a0, a1, a2; // 0x10, 0x14, 0x18
} GXLightObj;

void GXInitLightAttnA(GXLightObj* light, float a0, float a1, float a2) {
    light->a0 = a0;
    light->a1 = a1;
    light->a2 = a2;
}
