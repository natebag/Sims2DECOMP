// 0x8017E5B8 UIReflow::Tween_XScale(float) (128B)
// Pattern: Tween float-variant w/ scale multiplier (non-SDA const)
extern "C" int Sprintf(char* buf, char* fmt, ...);
extern char gStrBegin_XScale[];
extern char gStrEnd_XScale[];
extern char gFmtFloat[];
extern const float gXScaleMul[3];

struct UIReflow {
    void AddToBlock(char*);
    void Tween_XScale(float val);
};

void UIReflow::Tween_XScale(float val) {
    AddToBlock(gStrBegin_XScale);
    char buf[128];
    int r = Sprintf(buf, gFmtFloat, val * gXScaleMul[0]);
    AddToBlock(buf);
    AddToBlock(gStrEnd_XScale);
}
