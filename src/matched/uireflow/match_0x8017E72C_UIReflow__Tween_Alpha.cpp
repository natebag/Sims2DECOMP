// 0x8017E72C UIReflow::Tween_Alpha(unsigned int) (124B)
// Pattern: Tween with magic-divide percentage (val * 100 / 255)
extern "C" int Sprintf(char* buf, char* fmt, ...);
extern char gStrBegin_Alpha[];
extern char gStrEnd_Alpha[];
extern char gFmtIntAlpha[];

struct UIReflow {
    void AddToBlock(char*);
    void Tween_Alpha(unsigned int val);
};

void UIReflow::Tween_Alpha(unsigned int val) {
    AddToBlock(gStrBegin_Alpha);
    char buf[128];
    int r = Sprintf(buf, gFmtIntAlpha, (val * 100) / 255);
    AddToBlock(buf);
    AddToBlock(gStrEnd_Alpha);
}
