// 0x8004FD38 ISimsObjectModel::DoAnimation(void) (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; lwz 9,0x358(30); cmpwi 9,0; li 0,0; beq 0f; lwz 0,0x18(9); 0:; cmpwi 0,0; addi 29,30,1124; beq 5f; addi 31,30,820; lwz 5,-26812(13); mr 3,31; addi 4,30,192; bl _s8004FD38_0; lwz 9,0x11c(30); lwz 0,0x4(31); mtspr 9,9; lwz 11,0x118(30); andi. 9,0,8; beq 3f; mfspr 0,9; lwz 3,0xc(31); cmpwi 0,0; beq 5f; 1:; lha 0,0x2(11); lha 9,0x0(11); rlwinm 10,0,0,29,27; cmpwi 9,-1; beq 2f; mulli 9,9,68; add 9,9,3; lhz 0,0x2(9); rlwinm 0,0,0,28,28; or 10,0,10; 2:; sth 10,0x2(11); addi 11,11,16; bdnz 1b; b 5f; 3:; mfspr 9,9; cmpwi 9,0; beq 5f; 4:; lhz 0,0x2(11); rlwinm 0,0,0,29,27; sth 0,0x2(11); addi 11,11,16; bdnz 4b; 5:; lwz 0,0x4(29); cmpwi 0,0; ble 6f; mr 3,30; bl _s8004FD38_1; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8004FD38_0();
extern "C" void _s8004FD38_1();
extern "C" void f_8004FD38() {}
