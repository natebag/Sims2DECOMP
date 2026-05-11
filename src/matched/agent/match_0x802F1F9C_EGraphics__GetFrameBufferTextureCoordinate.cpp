// 0x802F1F9C EGraphics::GetFrameBufferTextureCoordinate(EVec2) (24B)
// Pure identity copy — returns argument unchanged.
// SN ProDG cc1plus needs explicit copy ctor; implicit copy gives "invalid use of void expression".

struct EVec2 {
    float x;
    float y;
    EVec2() {}
    EVec2(const EVec2& o) : x(o.x), y(o.y) {}
};

struct EGraphics {
    EVec2 GetFrameBufferTextureCoordinate(EVec2 v);
};

EVec2 EGraphics::GetFrameBufferTextureCoordinate(EVec2 v) {
    return v;
}
