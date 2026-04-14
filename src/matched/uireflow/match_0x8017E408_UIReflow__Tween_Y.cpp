// 0x8017E408 UIReflow::Tween_Y(int) (108B) — family match with Tween_X
extern "C" int Sprintf(char* buf, char* fmt, ...);
extern char gStrBegin_Y[];
extern char gStrEnd_Y[];
extern char gFmtInt[];

struct UIReflow {
    void AddToBlock(char*);
    void Tween_Y(int val);
};

void UIReflow::Tween_Y(int val) {
    AddToBlock(gStrBegin_Y);
    char buf[128];
    int r = Sprintf(buf, gFmtInt, val);
    AddToBlock(buf);
    AddToBlock(gStrEnd_Y);
}
