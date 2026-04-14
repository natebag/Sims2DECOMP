// 0x8017E474 UIReflow::Tween_Z(unsigned int) (108B) — family match with Tween_X
extern "C" int Sprintf(char* buf, char* fmt, ...);
extern char gStrBegin_Z[];
extern char gStrEnd_Z[];
extern char gFmtInt[];

struct UIReflow {
    void AddToBlock(char*);
    void Tween_Z(unsigned int val);
};

void UIReflow::Tween_Z(unsigned int val) {
    AddToBlock(gStrBegin_Z);
    char buf[128];
    int r = Sprintf(buf, gFmtInt, val);
    AddToBlock(buf);
    AddToBlock(gStrEnd_Z);
}
