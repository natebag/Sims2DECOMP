// 0x801CF2CC O2TTarget::GetScreenYLocal(signed (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mr. 4,4; blt 0f; xoris 0,4,32768; stw 0,0xc(1); lis 11,17200; lis 10,-32705; lis 8,-32705; stw 11,0x8(1); lis 7,-32705; lfd f0,0x3ed0(10); lfd f1,0x8(1); lfs f12,0x3ed8(8); fsub f1,f1,f0; lfs f13,0x3edc(7); frsp f1,f1; fdivs f1,f1,f12; fmadds f1,f1,f13,f13; b 1f; 0:; addi 0,4,25; xoris 0,0,32768; lis 8,17200; stw 0,0xc(1); lis 9,-32705; lfd f0,0x3ed0(9); lis 10,-32705; stw 8,0x8(1); lis 9,-32705; lfs f12,0x3ed8(10); lfd f1,0x8(1); lfs f13,0x3edc(9); fsub f1,f1,f0; frsp f1,f1; fdivs f1,f1,f12; fmuls f1,f1,f13; 1:; addi 1,1,16"
extern "C" void f_801CF2CC() {}
