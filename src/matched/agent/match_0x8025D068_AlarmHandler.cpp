// 0x8025D068 AlarmHandler (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); bl _s8025D068_0; lis 3,-32694; addi 3,3,-17216; li 4,32; bl _s8025D068_1; lis 4,-32730; lwz 3,-23480(13); addi 0,4,-11904; stw 0,-23392(13); bl _s8025D068_2; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8025D068_0();
extern "C" void _s8025D068_1();
extern "C" void _s8025D068_2();
extern "C" void f_8025D068() {}
