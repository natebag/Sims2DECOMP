// 0x801256EC cXPersonImpl::GetAspirationScore(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,0x4(3); li 4,0; lwz 9,0x4(11); lha 3,0x58(9); lwz 0,0x5c(9); add 3,11,3; mtspr 8,0; blrl; lis 9,-32706; lis 11,-32706; lfs f13,-12984(9); lis 10,-32706; lfs f12,-12980(11); fadds f1,f1,f13; lfs f0,-12976(10); fdivs f1,f1,f12; fmuls f1,f1,f0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_801256EC() {}
