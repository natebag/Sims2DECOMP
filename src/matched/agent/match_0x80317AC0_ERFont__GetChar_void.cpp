// 0x80317AC0 ERFont::GetChar(void (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 5,0; beq 0f; add 0,6,6; lhzx 3,4,0; blr; 0:; lbzx 3,4,6"
extern "C" int f_80317AC0() {}
