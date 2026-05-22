// 0x8031373C FlashBigFile::LoadFiles(EFile (524 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 26,0x30(1); stw 0,0x4c(1); mr 28,4; mr 31,3; lwz 9,0x28(28); lis 29,-32693; lis 26,-32693; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,28,3; blrl; lwz 9,0x28(28); mr 27,3; addi 4,1,8; li 5,24; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,28,3; blrl; addi 3,1,8; bl _s8031373C_0; mr 30,3; li 5,8; mr 4,30; addi 3,29,31260; bl _s8031373C_1; addi 11,1,8; lwz 8,0x8(1); lwz 10,0xc(11); addi 5,30,-24; lwz 0,0x4(11); lwz 9,0x8(11); stw 3,0x0(31); stw 8,0x0(3); stw 10,0xc(3); stw 0,0x4(3); stw 9,0x8(3); lwz 9,0x10(11); lwz 0,0x14(11); stw 9,0x10(3); stw 0,0x14(3); lwz 11,0x28(28); lwz 4,0x0(31); lwz 0,0x1c(11); lha 3,0x18(11); addi 4,4,24; mtspr 8,0; add 3,28,3; blrl; lwz 3,0x0(31); bl _s8031373C_2; mr 30,3; li 5,8; addi 3,29,31260; rlwinm 4,30,2,0,29; bl _s8031373C_3; li 0,0; stw 3,0x4(31); cmpw 0,30; stw 0,0x20(1); bge 3f; 0:; lwz 3,0x0(31); li 4,0; addi 5,1,32; addi 6,1,36; addi 7,1,40; bl _s8031373C_4; cmpwi 3,0; beq 1f; lwz 4,0x28(1); cmpwi 4,-1; beq 1f; li 5,8; addi 3,26,31260; bl _s8031373C_5; lwz 9,0x20(1); li 5,0; lwz 11,0x4(31); rlwinm 9,9,2,0,29; stwx 3,9,11; lwz 10,0x28(28); lwz 4,0x24(1); lwz 0,0x2c(10); lha 3,0x28(10); add 4,27,4; mtspr 8,0; add 3,28,3; blrl; lwz 11,0x28(28); lwz 9,0x20(1); lha 3,0x18(11); lwz 10,0x4(31); rlwinm 9,9,2,0,29; lwz 0,0x1c(11); add 3,28,3; lwzx 4,9,10; lwz 5,0x28(1); mtspr 8,0; blrl; lwz 4,0x20(1); mr 3,31; bl _s8031373C_6; cmpwi 3,0; beq 2f; lwz 4,0x20(1); mr 3,31; bl _s8031373C_7; lwz 9,0x20(1); lwz 11,0x4(31); rlwinm 9,9,2,0,29; stwx 3,9,11; b 2f; 1:; lwz 9,0x20(1); li 0,0; lwz 11,0x4(31); rlwinm 9,9,2,0,29; stwx 0,9,11; 2:; lwz 9,0x20(1); addi 9,9,1; cmpw 9,30; stw 9,0x20(1); blt 0b; 3:; lwz 0,0x4c(1); mtspr 8,0; lmw 26,0x30(1); addi 1,1,72"
extern "C" void _s8031373C_0();
extern "C" void _s8031373C_1();
extern "C" void _s8031373C_2();
extern "C" void _s8031373C_3();
extern "C" void _s8031373C_4();
extern "C" void _s8031373C_5();
extern "C" void _s8031373C_6();
extern "C" void _s8031373C_7();
extern "C" void f_8031373C() {}
