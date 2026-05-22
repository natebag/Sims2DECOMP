// 0x8025CD6C stateCheckID2 (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-32694; stw 0,0x4(1); lis 4,-32730; addi 6,4,-12640; stwu 1,-8(1); addi 3,3,-17248; li 4,32; li 5,1056; bl _s8025CD6C_0; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8025CD6C_0();
extern "C" void f_8025CD6C() {}
