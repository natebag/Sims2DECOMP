// 0x8017E638 UIReflow::Tween_YScale(float) (128B) — family match with Tween_XScale
extern "C" int Sprintf(char* buf, char* fmt, ...);
extern char gStrBegin_YScale[];
extern char gStrEnd_YScale[];
extern char gFmtFloat[];
extern const float gYScaleMul[3];

struct UIReflow {
    void AddToBlock(char*);
    void Tween_YScale(float val);
};

void UIReflow::Tween_YScale(float val) {
    AddToBlock(gStrBegin_YScale);
    char buf[128];
    int r = Sprintf(buf, gFmtFloat, val * gYScaleMul[0]);
    AddToBlock(buf);
    AddToBlock(gStrEnd_YScale);
}
