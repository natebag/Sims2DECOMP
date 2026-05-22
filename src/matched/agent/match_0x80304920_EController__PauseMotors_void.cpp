// 0x80304920 EController::PauseMotors(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 7,0x1dc(3); addi 9,3,476; lwz 0,0x4(9); addi 11,3,492; lwz 8,0xc(9); lwz 10,0x8(9); stw 7,0x1ec(3); stw 8,0xc(11); stw 0,0x4(11); stw 10,0x8(11); lwz 9,0x208(3); lha 0,0x78(9); lwz 9,0x7c(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_80304920() {}
