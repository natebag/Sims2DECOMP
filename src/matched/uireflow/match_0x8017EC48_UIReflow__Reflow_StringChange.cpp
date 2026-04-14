// 0x8017EC48 UIReflow::Reflow_StringChange(char*) (84B)
// Pattern: 3x AddToBlock with middle arg from input
extern char gStrBegin_StrChg[];
extern char gStrEnd_StrChg[];

struct UIReflow {
    void AddToBlock(char*);
    void Reflow_StringChange(char* s);
};

void UIReflow::Reflow_StringChange(char* s) {
    AddToBlock(gStrBegin_StrChg);
    AddToBlock(s);
    AddToBlock(gStrEnd_StrChg);
}
