// 0x800B463C CTilePt::CTilePt(int, (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="extsb 0,4; stb 4,0x0(3); cmpw 0,4; stb 5,0x1(3); beq 0f; li 0,0; stb 0,0x0(3); 0:; lbz 0,0x1(3); extsb 0,0; cmpw 0,5; beq 1f; li 0,0; stb 0,0x1(3); 1:; stb 6,0x2(3)"
extern "C" void f_800B463C() {}
