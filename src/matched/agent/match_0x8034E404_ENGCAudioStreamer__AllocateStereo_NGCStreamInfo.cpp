// 0x8034E404 ENGCAudioStreamer::AllocateStereo(NGCStreamInfo (348 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 23,0x14(1); stw 0,0x3c(1); lis 9,-32702; mr 24,4; addi 9,9,8864; mr 23,5; lwz 25,0x0(9); lwz 26,0x4(9); mr 29,6; bl _s8034E404_0; addi 31,1,8; mr 3,31; bl _s8034E404_1; mr 25,3; cmpwi 25,-1; beq 1f; addi 3,1,12; bl _s8034E404_2; mr 26,3; cmpwi 26,-1; beq 0f; lwz 9,0x8(1); mr 5,29; lwz 0,0x4(31); mr 4,24; li 6,0; lis 28,-32702; stw 0,0x8(9); lis 27,-32715; lwz 0,0x8(1); lwz 9,0x4(31); stw 0,0xc(9); lwz 3,0x8(1); bl _s8034E404_3; lwz 0,0x4(31); mr 30,3; mr 5,29; li 6,127; mr 3,0; mr 4,23; bl _s8034E404_4; mr 29,3; bl _s8034E404_5; lwz 4,0x8(1); addi 3,28,8872; addi 4,4,36; bl _s8034E404_6; lwz 9,0x8(1); mr 5,30; addi 7,27,-5440; li 8,1; lwz 11,0x10(9); addi 3,9,36; lwz 4,0x68(9); lwz 6,0x8(11); bl _s8034E404_7; lwz 4,0x4(31); addi 3,28,8872; addi 4,4,36; bl _s8034E404_8; lwz 9,0x4(31); mr 5,29; addi 7,27,-5440; li 8,1; lwz 11,0x10(9); addi 3,9,36; lwz 4,0x68(9); lwz 6,0x8(11); bl _s8034E404_9; b 2f; 0:; lwz 9,0x8(1); li 0,0; li 25,-1; stw 0,0x0(9); bl _s8034E404_10; b 2f; 1:; bl _s8034E404_11; 2:; mr 3,25; stw 3,0x40(24); stw 26,0x40(23); lwz 0,0x3c(1); mtspr 8,0; lmw 23,0x14(1); addi 1,1,56"
extern "C" void _s8034E404_0();
extern "C" void _s8034E404_1();
extern "C" void _s8034E404_2();
extern "C" void _s8034E404_3();
extern "C" void _s8034E404_4();
extern "C" void _s8034E404_5();
extern "C" void _s8034E404_6();
extern "C" void _s8034E404_7();
extern "C" void _s8034E404_8();
extern "C" void _s8034E404_9();
extern "C" void _s8034E404_10();
extern "C" void _s8034E404_11();
extern "C" void f_8034E404() {}
