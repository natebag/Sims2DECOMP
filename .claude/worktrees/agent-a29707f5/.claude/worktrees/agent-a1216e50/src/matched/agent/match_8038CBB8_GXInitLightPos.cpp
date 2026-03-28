// 0x8038CBB8 (16 bytes) - GXInitLightPos
// stfs f1, 40(r3); stfs f2, 44(r3); stfs f3, 48(r3); blr

typedef struct GXLightObj {
    char pad[40]; // 0x00-0x27
    float px, py, pz; // 0x28, 0x2C, 0x30
} GXLightObj;

void GXInitLightPos(GXLightObj* light, float x, float y, float z) {
    light->px = x;
    light->py = y;
    light->pz = z;
}
