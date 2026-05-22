// 0x8030497C EController::ResumeMotors(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 9,3; lwz 11,0x208(9); lfs f4,0x1f8(9); lha 3,0x50(11); lwz 0,0x54(11); add 3,9,3; lfs f1,0x1ec(9); lfs f2,0x1f0(9); mtspr 8,0; lfs f3,0x1f4(9); blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_8030497C() {}
