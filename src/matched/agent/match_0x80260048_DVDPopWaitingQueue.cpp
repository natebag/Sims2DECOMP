// 0x80260048 __DVDPopWaitingQueue (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); bl _s80260048_0; li 0,4; lis 4,-32694; mtspr 9,0; addi 4,4,-17096; li 31,0; 0:; lwz 0,0x0(4); cmplw 0,4; beq 1f; bl _s80260048_1; bl _s80260048_2; lis 4,-32694; rlwinm 5,31,3,0,28; addi 0,4,-17096; add 5,0,5; lwz 31,0x0(5); lwz 0,0x0(31); stw 0,0x0(5); lwz 4,0x0(31); stw 5,0x4(4); bl _s80260048_3; li 0,0; stw 0,0x0(31); mr 3,31; stw 0,0x4(31); b 2f; 1:; addi 4,4,8; addi 31,31,1; bdnz 0b; bl _s80260048_4; li 3,0; 2:; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s80260048_0();
extern "C" void _s80260048_1();
extern "C" void _s80260048_2();
extern "C" void _s80260048_3();
extern "C" void _s80260048_4();
extern "C" void f_80260048() {}
