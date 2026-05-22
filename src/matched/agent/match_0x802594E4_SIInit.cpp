// 0x802594E4 SIInit (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 4,-32694; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); addi 31,4,-21872; lwz 3,-27832(13); bl _s802594E4_0; li 5,-1; stw 5,0x60(31); lis 3,-32700; addi 4,3,-15972; stw 5,0x40(31); li 0,0; li 3,0; stw 5,0x20(31); stw 5,0x0(31); stw 0,0x4(4); bl _s802594E4_1; lis 3,-13312; 0:; addi 4,3,25600; lwzu 0,0x34(4); rlwinm. 0,0,0,31,31; bne 0b; lis 0,-32768; lis 3,-32730; stw 0,0x0(4); addi 4,3,-28856; li 3,20; bl _s802594E4_2; li 3,2048; bl _s802594E4_3; li 3,0; bl _s802594E4_4; li 3,1; bl _s802594E4_5; li 3,2; bl _s802594E4_6; li 3,3; bl _s802594E4_7; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s802594E4_0();
extern "C" void _s802594E4_1();
extern "C" void _s802594E4_2();
extern "C" void _s802594E4_3();
extern "C" void _s802594E4_4();
extern "C" void _s802594E4_5();
extern "C" void _s802594E4_6();
extern "C" void _s802594E4_7();
extern "C" void f_802594E4() {}
