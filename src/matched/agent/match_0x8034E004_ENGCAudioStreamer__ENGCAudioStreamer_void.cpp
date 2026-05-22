// 0x8034E004 ENGCAudioStreamer::ENGCAudioStreamer(void) (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 22,0x8(1); stw 0,0x34(1); lis 9,-32690; lis 29,1; addi 31,9,-14064; lis 28,2; addi 22,31,120; addi 23,31,24; addi 24,31,28; mr 27,3; lis 25,-32715; li 26,0; ori 29,29,16768; ori 28,28,12960; li 30,0; 0:; stw 26,0x0(31); bl _s8034E004_0; lis 4,1; li 6,0; li 7,0; ori 4,4,16768; li 5,32; bl _s8034E004_1; stw 3,0x68(31); stw 29,0x6c(31); mr 3,29; stw 28,0x70(31); bl _s8034E004_2; stwx 3,23,30; addi 4,25,-3432; li 5,0; li 3,31; bl _s8034E004_3; stwx 3,24,30; li 4,0; li 5,-904; li 6,-904; lbz 8,0x15(31); li 7,-904; li 9,127; li 10,0; bl _s8034E004_4; addi 31,31,120; addi 30,30,120; cmplw 31,22; ble 0b; li 0,0; mr 3,27; stw 0,-22476(13); stw 0,-22484(13); lwz 0,0x34(1); mtspr 8,0; lmw 22,0x8(1); addi 1,1,48"
extern "C" void _s8034E004_0();
extern "C" void _s8034E004_1();
extern "C" void _s8034E004_2();
extern "C" void _s8034E004_3();
extern "C" void _s8034E004_4();
extern "C" void f_8034E004() {}
