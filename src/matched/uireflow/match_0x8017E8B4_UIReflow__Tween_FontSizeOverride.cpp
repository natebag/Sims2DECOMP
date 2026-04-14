// 0x8017E8B4 UIReflow::Tween_FontSizeOverride(unsigned int) (108B) — family match with Tween_X
extern "C" int Sprintf(char* buf, char* fmt, ...);
extern char gStrBegin_FontSize[];
extern char gStrEnd_FontSize[];
extern char gFmtInt[];

struct UIReflow {
    void AddToBlock(char*);
    void Tween_FontSizeOverride(unsigned int val);
};

void UIReflow::Tween_FontSizeOverride(unsigned int val) {
    AddToBlock(gStrBegin_FontSize);
    char buf[128];
    int r = Sprintf(buf, gFmtInt, val);
    AddToBlock(buf);
    AddToBlock(gStrEnd_FontSize);
}
