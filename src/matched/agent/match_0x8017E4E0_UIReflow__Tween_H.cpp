// 0x8017E4E0 UIReflow::Tween_H(unsigned int) (108B) — family match with Tween_X
extern "C" int Sprintf(char* buf, char* fmt, ...);
extern char gStrBegin_H[];
extern char gStrEnd_H[];
extern char gFmtInt[];

struct UIReflow {
    void AddToBlock(char*);
    void Tween_H(unsigned int val);
};

void UIReflow::Tween_H(unsigned int val) {
    AddToBlock(gStrBegin_H);
    char buf[128];
    int r = Sprintf(buf, gFmtInt, val);
    AddToBlock(buf);
    AddToBlock(gStrEnd_H);
}
