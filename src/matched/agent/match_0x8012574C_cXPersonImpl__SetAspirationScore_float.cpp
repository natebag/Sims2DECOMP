// 0x8012574C cXPersonImpl::SetAspirationScore(float) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32706; lwz 8,0x4(3); lfs f0,-12972(9); lis 11,-32706; lwz 10,0x4(8); lis 9,-32706; fdivs f12,f1,f0; lfs f13,-12968(11); lfs f1,-12964(9); li 4,0; lha 3,0x70(10); lwz 0,0x74(10); add 3,8,3; mtspr 8,0; fmsubs f1,f12,f13,f1; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_8012574C() {}
