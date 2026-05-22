// 0x803834EC CARDFormatAsync (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); addi 31,4,0; stw 30,0x10(1); addi 30,3,0; bl _s803834EC_0; addi 4,3,0; addi 3,30,0; addi 5,31,0; bl _s803834EC_1; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s803834EC_0();
extern "C" void _s803834EC_1();
extern "C" void f_803834EC() {}
