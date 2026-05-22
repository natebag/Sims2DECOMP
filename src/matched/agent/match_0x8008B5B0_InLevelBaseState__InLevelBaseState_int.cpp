// 0x8008B5B0 InLevelBaseState::InLevelBaseState(int) (328 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); lis 9,-32698; mr 28,3; li 30,0; li 0,-1; li 10,1; addi 9,9,-10536; lis 11,-32698; stw 4,0x0(28); stw 9,0x18(28); addi 29,28,44; stw 0,0x4(28); addi 11,11,30832; stw 0,0xc(28); addi 26,28,84; stw 10,0x14(28); mr 3,26; stw 30,0x8(28); addi 25,28,92; stw 30,0x10(28); addi 24,28,96; stw 30,0x1c(28); addi 23,28,100; stw 30,0x20(28); lis 27,-32707; stw 11,0x84(29); stw 30,0x2c(28); stw 30,0x4(29); stw 30,0x8(29); stw 30,0xc(29); stw 30,0x10(29); stw 30,0x1c(29); stw 30,0x20(29); stw 30,0x24(29); stw 10,0x14(29); stw 0,0x18(29); bl _s8008B5B0_0; addi 3,28,88; bl _s8008B5B0_1; mr 3,25; bl _s8008B5B0_2; mr 3,24; bl _s8008B5B0_3; mr 3,23; bl _s8008B5B0_4; li 0,3; stw 30,0x3c(29); stw 0,0x4c(29); addi 9,28,124; stw 30,0x40(29); addi 11,28,140; stw 30,0x44(29); addi 10,28,156; sth 30,0x48(29); addi 4,27,30796; sth 30,0x4a(29); mr 3,26; stw 30,0x8(9); stw 30,0x7c(28); stw 30,0x8(11); stw 30,0x8c(28); stw 30,0x8(10); stw 30,0x9c(28); bl _s8008B5B0_5; addi 4,27,30796; mr 3,25; bl _s8008B5B0_6; addi 4,27,30796; mr 3,24; bl _s8008B5B0_7; mr 3,23; addi 4,27,30796; bl _s8008B5B0_8; mr 3,28; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"
extern "C" void _s8008B5B0_0();
extern "C" void _s8008B5B0_1();
extern "C" void _s8008B5B0_2();
extern "C" void _s8008B5B0_3();
extern "C" void _s8008B5B0_4();
extern "C" void _s8008B5B0_5();
extern "C" void _s8008B5B0_6();
extern "C" void _s8008B5B0_7();
extern "C" void _s8008B5B0_8();
extern "C" void f_8008B5B0() {}
