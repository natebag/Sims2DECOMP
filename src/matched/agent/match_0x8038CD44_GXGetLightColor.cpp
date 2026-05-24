// 0x8038CD44 GXGetLightColor (12 B)
// FLAGS: -fno-schedule-insns
// Pattern: lwz r0,0xc(r3); stw r0,0x0(r4); blr

struct GXLightObj {
    char _pad[0xC];
    int m_color; // 0xC
};

struct GXColor {
    int rgba; // packed RGBA
};

void GXGetLightColor(GXLightObj* light, GXColor* outColor) {
    outColor->rgba = light->m_color;
}
