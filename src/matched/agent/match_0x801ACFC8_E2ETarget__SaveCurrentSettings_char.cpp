// 0x801ACFC8 E2ETarget::SaveCurrentSettings(char (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s801ACFC8_0; stfs f1,-30444(13); bl _s801ACFC8_1; stfs f1,-30440(13); bl _s801ACFC8_2; stfs f1,-30436(13); bl _s801ACFC8_3; stfs f1,-30432(13); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801ACFC8_0();
extern "C" void _s801ACFC8_1();
extern "C" void _s801ACFC8_2();
extern "C" void _s801ACFC8_3();
extern "C" void f_801ACFC8() {}
