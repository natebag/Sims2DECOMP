// 0x8017E838 UIReflow::Tween_ColorOnlyOverride(unsigned int) (124B)
// Pattern: Tween w/ two opening AddToBlock calls before Sprintf
extern "C" int Sprintf(char* buf, char* fmt, ...);
extern char gStrBegin_Color[];
extern char gStrPre_Color[];
extern char gStrEnd_Color[];
extern char gFmtIntColor[];

struct UIReflow {
    void AddToBlock(char*);
    void Tween_ColorOnlyOverride(unsigned int val);
};

void UIReflow::Tween_ColorOnlyOverride(unsigned int val) {
    AddToBlock(gStrBegin_Color);
    AddToBlock(gStrPre_Color);
    char buf[128];
    int r = Sprintf(buf, gFmtIntColor, val);
    AddToBlock(buf);
    AddToBlock(gStrEnd_Color);
}
