// 0x8007EF9C DlgWrapper::SetButtonContext(char (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 31,0xac(3); mr 3,4; cmpwi 3,0; stw 3,0x38(31); beq 0f; bl _s8007EF9C_0; 0:; stw 3,0x3c(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8007EF9C_0();
extern "C" void f_8007EF9C() {}
