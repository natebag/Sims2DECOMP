// 0x8017EBB0 UIReflow::Reflow_Visibility(bool) (120B)
// Pattern: bool->int + Sprintf(buf, fmt, val) + AddToBlock trio
extern "C" int Sprintf(char* buf, char* fmt, ...);
extern char gStrBegin_Vis[];
extern char gStrEnd_Vis[];
extern char gFmtIntVis[];

struct UIReflow {
    void AddToBlock(char*);
    void Reflow_Visibility(bool v);
};

void UIReflow::Reflow_Visibility(bool v) {
    AddToBlock(gStrBegin_Vis);
    int val = v ? 1 : 0;
    char buf[128];
    int r = Sprintf(buf, gFmtIntVis, val);
    AddToBlock(buf);
    AddToBlock(gStrEnd_Vis);
}
