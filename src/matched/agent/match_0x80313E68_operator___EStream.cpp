// 0x80313E68 operator<<(EStream (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s80313E68_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80313E68_0();
extern "C" void f_80313E68() {}
