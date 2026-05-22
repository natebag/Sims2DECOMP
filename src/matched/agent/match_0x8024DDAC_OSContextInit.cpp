// 0x8024DDAC __OSContextInit (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); lis 3,-32731; addi 4,3,-8920; li 3,7; bl _s8024DDAC_0; li 0,0; crxor 6,6,6; lis 4,-32768; lis 3,-32700; stw 0,0xd8(4); addi 3,3,-19548; bl _s8024DDAC_1; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8024DDAC_0();
extern "C" void _s8024DDAC_1();
extern "C" void f_8024DDAC() {}
