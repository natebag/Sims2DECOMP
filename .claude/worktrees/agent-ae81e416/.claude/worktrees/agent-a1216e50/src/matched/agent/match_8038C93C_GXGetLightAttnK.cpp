// 0x8038C93C (28 bytes) - GXGetLightAttnK
typedef struct GXLightObj {
    char pad[28];
    float k0, k1, k2; // 0x1C, 0x20, 0x24
} GXLightObj;
void GXGetLightAttnK(GXLightObj* l, float* k0, float* k1, float* k2) {
    *k0 = l->k0;
    *k1 = l->k1;
    *k2 = l->k2;
}
