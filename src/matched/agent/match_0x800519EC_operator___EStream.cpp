// 0x800519EC operator<<(EStream (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s800519EC_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800519EC_0();
extern "C" void f_800519EC() {}
