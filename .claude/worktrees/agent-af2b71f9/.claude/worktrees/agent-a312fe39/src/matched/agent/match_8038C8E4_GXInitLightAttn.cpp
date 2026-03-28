// 0x8038C8E4 (28 bytes) - GXInitLightAttn
typedef struct GXLightObj {
    char pad[16];
    float a0, a1, a2; // 0x10, 0x14, 0x18
    float k0, k1, k2; // 0x1C, 0x20, 0x24
} GXLightObj;
void GXInitLightAttn(GXLightObj* l, float a0, float a1, float a2, float k0, float k1, float k2) {
    l->a0 = a0; l->a1 = a1; l->a2 = a2;
    l->k0 = k0; l->k1 = k1; l->k2 = k2;
}
