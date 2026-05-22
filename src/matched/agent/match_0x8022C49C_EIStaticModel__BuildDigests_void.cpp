// 0x8022C49C EIStaticModel::BuildDigests(void) (432 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 22,0x8(1); stw 0,0x34(1); mr 29,3; lwz 3,0x120(29); bl _s8022C49C_0; lwz 0,0x5c(29); cmpwi 3,0; stw 3,0x11c(29); rlwinm 0,0,0,17,15; stw 0,0x5c(29); beq 6f; bl _s8022C49C_1; lwz 4,0x11c(29); li 5,0; rlwinm 4,4,4,0,27; bl _s8022C49C_2; lwz 9,0x120(29); li 11,0; stw 3,0x118(29); lwz 0,0x8c(9); cmpwi 0,0; beq 0f; li 11,1; 0:; stw 11,0x318(29); li 8,0; mr 30,3; lwz 0,0x40(9); cmpw 8,0; bge 6f; lis 22,-32692; 1:; lwz 11,0x120(29); mulli 10,8,24; li 25,0; lwz 9,0x3c(11); addi 23,8,1; add 28,9,10; lwz 0,0x4(28); cmpw 25,0; bge 5f; addi 24,22,-17444; li 26,0; 2:; lwz 27,0x0(28); li 5,0; li 6,0; mr 3,24; add 31,27,26; lwz 4,0xc(31); stw 28,0x20(31); bl _s8022C49C_3; stw 3,0x4(30); addi 4,29,8; mr 3,30; bl _s8022C49C_4; lwz 0,0x8(30); andi. 0,0,1024; beq 3f; lwz 4,0xc(31); mr 3,24; li 5,1; bl _s8022C49C_5; lwz 9,0x11c(29); lwz 0,0x5c(29); addi 9,9,-1; ori 0,0,32768; stw 9,0x11c(29); stw 0,0x5c(29); b 4f; 3:; lhz 9,0xe(28); sth 0,0x2(30); sth 9,0x0(30); lwzx 0,27,26; stw 0,0xc(30); addi 30,30,16; 4:; lwz 0,0x4(28); addi 25,25,1; addi 26,26,112; cmpw 25,0; blt 2b; 5:; lwz 9,0x120(29); mr 8,23; lwz 0,0x40(9); cmpw 8,0; blt 1b; 6:; lwz 9,0x120(29); lwz 0,0x24(9); cmpwi 0,0; beq 7f; li 0,0; stw 0,0x68(29); 7:; lwz 9,0x120(29); lwz 0,0x28(9); cmpwi 0,0; beq 8f; li 0,0; stw 0,0x6c(29); 8:; lwz 9,0x120(29); lwz 0,0x2c(9); cmpwi 0,0; beq 9f; li 0,0; stw 0,0x70(29); 9:; lwz 0,0x34(1); mtspr 8,0; lmw 22,0x8(1); addi 1,1,48"
extern "C" void _s8022C49C_0();
extern "C" void _s8022C49C_1();
extern "C" void _s8022C49C_2();
extern "C" void _s8022C49C_3();
extern "C" void _s8022C49C_4();
extern "C" void _s8022C49C_5();
extern "C" void f_8022C49C() {}
