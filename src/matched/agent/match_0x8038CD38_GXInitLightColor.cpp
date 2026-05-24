// 0x8038CD38 GXInitLightColor (12 B)
// FLAGS: -fno-schedule-insns
// Pattern: lwz r0,0x0(r4); stw r0,0xc(r3); blr

struct GXLightObj {
    char _pad[0xC];
    int m_color; // 0xC
};

struct GXColor {
    int rgba; // packed RGBA
};

void GXInitLightColor(GXLightObj* light, GXColor* color) {
    light->m_color = color->rgba;
}
