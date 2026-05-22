// 0x803045F4 EController::VibrateAll(float, (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stmw 30,0x8(1); stw 0,0x1c(1); mr 31,3; fmr f31,f2; lwz 9,0x208(31); li 30,0; lha 3,0x28(9); lwz 0,0x2c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; lwz 9,0x208(31); fmr f1,f31; lha 3,0x38(9); lwz 0,0x3c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; li 30,1; 0:; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x8(1); lfd f31,0x10(1); addi 1,1,24"
extern "C" void f_803045F4() {}
