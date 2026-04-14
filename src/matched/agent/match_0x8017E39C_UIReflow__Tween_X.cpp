// 0x8017E39C UIReflow::Tween_X(int) (108B)
// Pattern: Tween integer-variant — AddToBlock(begin) + Sprintf(buf, fmt, val) + AddToBlock(buf) + AddToBlock(end)
// Key trick: capture Sprintf return value to force correct scheduler order
extern "C" int Sprintf(char* buf, char* fmt, ...);
extern char gStrBegin_X[];
extern char gStrEnd_X[];
extern char gFmtInt[];

struct UIReflow {
    void AddToBlock(char*);
    void Tween_X(int val);
};

void UIReflow::Tween_X(int val) {
    AddToBlock(gStrBegin_X);
    char buf[128];
    int r = Sprintf(buf, gFmtInt, val);
    AddToBlock(buf);
    AddToBlock(gStrEnd_X);
}
