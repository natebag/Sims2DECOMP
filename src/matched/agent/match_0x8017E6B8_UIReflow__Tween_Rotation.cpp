// 0x8017E6B8 UIReflow::Tween_Rotation(float) (116B)
// Pattern: Tween float-variant passthrough (no scale)
extern "C" int Sprintf(char* buf, char* fmt, ...);
extern char gStrBegin_Rot[];
extern char gStrEnd_Rot[];
extern char gFmtFloatRot[];

struct UIReflow {
    void AddToBlock(char*);
    void Tween_Rotation(float val);
};

void UIReflow::Tween_Rotation(float val) {
    AddToBlock(gStrBegin_Rot);
    char buf[128];
    int r = Sprintf(buf, gFmtFloatRot, val);
    AddToBlock(buf);
    AddToBlock(gStrEnd_Rot);
}
