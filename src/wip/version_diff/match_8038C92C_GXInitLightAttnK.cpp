// 0x8038C92C (16 bytes) - GXInitLightAttnK
// stfs f1, 28(r3); stfs f2, 32(r3); stfs f3, 36(r3); blr

typedef struct GXLightObj {
    char pad[28]; // 0x00-0x1B
    float k0, k1, k2; // 0x1C, 0x20, 0x24
} GXLightObj;

void GXInitLightAttnK(GXLightObj* light, float k0, float k1, float k2) {
    light->k0 = k0;
    light->k1 = k1;
    light->k2 = k2;
}
