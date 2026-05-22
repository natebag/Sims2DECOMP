// 0x8007E990 DlgWrapper::SetBodyPosY(float) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,0xac(3); lwz 10,0x64(11); lwz 9,0x1c(10); lha 3,0x58(9); lwz 0,0x5c(9); add 3,10,3; mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_8007E990() {}
