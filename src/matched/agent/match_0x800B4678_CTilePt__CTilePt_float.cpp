// 0x800B4678 CTilePt::CTilePt(float, (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); fctiwz f0,f1; mr 11,9; stfd f0,0x8(1); fctiwz f0,f2; lwz 9,0xc(1); stfd f0,0x8(1); extsb 0,9; stb 9,0x0(3); lwz 11,0xc(1); cmpw 0,9; stb 11,0x1(3); beq 0f; li 0,0; stb 0,0x0(3); 0:; lbz 0,0x1(3); extsb 0,0; cmpw 0,11; beq 1f; li 0,0; stb 0,0x1(3); 1:; stb 4,0x2(3); addi 1,1,16"
extern "C" void f_800B4678() {}
