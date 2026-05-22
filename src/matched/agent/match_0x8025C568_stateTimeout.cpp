// 0x8025C568 stateTimeout (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,291; stw 0,0x4(1); addi 3,3,17768; stwu 1,-8(1); bl _s8025C568_0; bl _s8025C568_1; li 3,0; bl _s8025C568_2; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8025C568_0();
extern "C" void _s8025C568_1();
extern "C" void _s8025C568_2();
extern "C" void f_8025C568() {}
