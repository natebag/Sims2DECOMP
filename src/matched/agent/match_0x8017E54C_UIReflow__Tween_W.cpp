// 0x8017E54C UIReflow::Tween_W(unsigned int) (108B) — family match with Tween_X
extern "C" int Sprintf(char* buf, char* fmt, ...);
extern char gStrBegin_W[];
extern char gStrEnd_W[];
extern char gFmtInt[];

struct UIReflow {
    void AddToBlock(char*);
    void Tween_W(unsigned int val);
};

void UIReflow::Tween_W(unsigned int val) {
    AddToBlock(gStrBegin_W);
    char buf[128];
    int r = Sprintf(buf, gFmtInt, val);
    AddToBlock(buf);
    AddToBlock(gStrEnd_W);
}
