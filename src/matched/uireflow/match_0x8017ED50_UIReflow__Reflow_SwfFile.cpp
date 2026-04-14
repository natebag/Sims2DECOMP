// 0x8017ED50 UIReflow::Reflow_SwfFile(char*) (84B) — family match with Reflow_StringChange
extern char gStrBegin_SwfFile[];
extern char gStrEnd_SwfFile[];

struct UIReflow {
    void AddToBlock(char*);
    void Reflow_SwfFile(char* s);
};

void UIReflow::Reflow_SwfFile(char* s) {
    AddToBlock(gStrBegin_SwfFile);
    AddToBlock(s);
    AddToBlock(gStrEnd_SwfFile);
}
