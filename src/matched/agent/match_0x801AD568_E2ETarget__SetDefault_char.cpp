// 0x801AD568 E2ETarget::SetDefault(char (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s801AD568_0; bl _s801AD568_1; stfs f1,-30444(13); bl _s801AD568_2; stfs f1,-30440(13); bl _s801AD568_3; stfs f1,-30436(13); bl _s801AD568_4; stfs f1,-30432(13); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801AD568_0();
extern "C" void _s801AD568_1();
extern "C" void _s801AD568_2();
extern "C" void _s801AD568_3();
extern "C" void _s801AD568_4();
extern "C" void f_801AD568() {}
