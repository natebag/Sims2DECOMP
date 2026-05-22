// 0x802D7534 efclose (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); stw 3,0x8(1); addi 4,1,8; lis 3,-32694; addi 3,3,-10620; bl _s802D7534_0; li 3,0; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s802D7534_0();
extern "C" void f_802D7534() {}
