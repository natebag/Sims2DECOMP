// 0x801110C0 ObjSelector::GetHasGraphics(void) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x38(3); lha 0,0x14(9); cmpwi 0,0; beq 0f; li 3,1; blr; 0:; lha 0,0x8(9); li 3,1; cmpwi 0,0; bnelr; li 3,0"
extern "C" int f_801110C0() {}
