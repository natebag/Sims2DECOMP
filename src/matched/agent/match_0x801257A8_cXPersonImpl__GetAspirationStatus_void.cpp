// 0x801257A8 cXPersonImpl::GetAspirationStatus(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,0x4(3); lwz 9,0x4(11); lha 3,0x88(9); lwz 0,0x8c(9); add 3,11,3; mtspr 8,0; blrl; lis 9,-32706; lfs f0,-12960(9); fcmpu 0,f1,f0; cror 3,2,0; bns 0f; li 3,0; b 2f; 0:; lis 9,-32706; lfs f0,-12956(9); fcmpu 0,f1,f0; cror 3,2,0; bso 1f; lis 9,-32706; li 3,2; lfs f0,-12952(9); fcmpu 0,f1,f0; cror 3,2,0; bso 2f; li 3,3; b 2f; 1:; li 3,1; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_801257A8() {}
