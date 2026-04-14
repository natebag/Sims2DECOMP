// 0x8017ECFC UIReflow::Reflow_SwfAnimation(char*) (84B) — family match with Reflow_StringChange
extern char gStrBegin_SwfAnim[];
extern char gStrEnd_SwfAnim[];

struct UIReflow {
    void AddToBlock(char*);
    void Reflow_SwfAnimation(char* s);
};

void UIReflow::Reflow_SwfAnimation(char* s) {
    AddToBlock(gStrBegin_SwfAnim);
    AddToBlock(s);
    AddToBlock(gStrEnd_SwfAnim);
}
