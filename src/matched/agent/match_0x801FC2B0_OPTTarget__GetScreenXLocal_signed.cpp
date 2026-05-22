// 0x801FC2B0 OPTTarget::GetScreenXLocal(signed (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mr. 4,4; blt 0f; xoris 0,4,32768; stw 0,0xc(1); lis 11,17200; lis 10,-32704; lis 8,-32704; stw 11,0x8(1); lis 7,-32704; lfd f0,-20792(10); lfd f1,0x8(1); lfs f12,-20784(8); fsub f1,f1,f0; lfs f13,-20780(7); frsp f1,f1; fdivs f1,f1,f12; fmadds f1,f1,f13,f13; b 1f; 0:; addi 0,4,25; xoris 0,0,32768; lis 8,17200; stw 0,0xc(1); lis 9,-32704; lfd f0,-20792(9); lis 10,-32704; stw 8,0x8(1); lis 9,-32704; lfs f12,-20784(10); lfd f1,0x8(1); lfs f13,-20780(9); fsub f1,f1,f0; frsp f1,f1; fdivs f1,f1,f12; fmuls f1,f1,f13; 1:; addi 1,1,16"
extern "C" void f_801FC2B0() {}
