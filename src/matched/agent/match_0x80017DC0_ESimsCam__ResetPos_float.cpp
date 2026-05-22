// 0x80017DC0 ESimsCam::ResetPos(float) (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); lis 9,-32707; mr 31,3; lfs f0,-7316(9); li 0,1; stw 0,0x478(31); fcmpu 0,f1,f0; bne 0f; lwz 9,0x0(31); addi 8,31,1084; addi 7,31,1060; lwz 10,0xc8(9); addi 9,9,200; lwz 0,0x8(9); lwz 11,0x4(9); stw 10,0x43c(31); stw 0,0x8(8); stw 11,0x4(8); lwz 9,0x0(31); lwz 10,0xd4(9); addi 9,9,212; lwz 0,0x8(9); lwz 11,0x4(9); stw 10,0x424(31); stw 0,0x8(7); stw 11,0x4(7); lwz 9,0x0(31); lfs f0,0xb4(9); stfs f0,0x450(31); lfs f13,0xb0(9); stfs f13,0x44c(31); b 1f; 0:; lwz 9,0x0(31); lfs f0,0xb4(9); stfs f1,0x44c(31); stfs f0,0x450(31); 1:; lwz 9,0x0(31); mr 3,31; lfs f1,0xb8(9); bl _s80017DC0_0; bl _s80017DC0_1; lwz 4,0x4(31); li 5,-1; bl _s80017DC0_2; mr. 30,3; beq 2f; lwz 0,0x4(31); lis 9,-32697; addi 9,9,24012; addi 3,1,8; rlwinm 0,0,2,0,29; addi 9,9,188; lwzx 4,9,0; li 5,1; li 6,0; bl _s80017DC0_3; lwz 9,0x5c(30); addi 4,1,8; lha 3,0xc0(9); lwz 0,0xc4(9); add 3,30,3; mtspr 8,0; blrl; 2:; mr 3,31; bl _s80017DC0_4; mr 3,31; bl _s80017DC0_5; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s80017DC0_0();
extern "C" void _s80017DC0_1();
extern "C" void _s80017DC0_2();
extern "C" void _s80017DC0_3();
extern "C" void _s80017DC0_4();
extern "C" void _s80017DC0_5();
extern "C" void f_80017DC0() {}
