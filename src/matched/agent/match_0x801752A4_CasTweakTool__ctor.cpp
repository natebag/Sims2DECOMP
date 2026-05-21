// 0x801752A4 CasTweakTool::CasTweakTool(void) (40B)
//
// vtable store at +272 + 2 empty 4-iter bdnz loops. Same `empty-bdnz-loop`
// pattern as InstanceData @ 0x803C1510 — GCC emits empty `for` loops as
// `mtctr; bdnz self` without optimization elision.
//
// PURE source-only crack.

extern char CasTweakTool_vt[];

class CasTweakTool {
public:
    CasTweakTool();
};

CasTweakTool::CasTweakTool() {
    *(int*)((char*)this + 272) = (int)CasTweakTool_vt;
    int i;
    for (i = 0; i < 4; i++) ;
    for (i = 0; i < 4; i++) ;
}
