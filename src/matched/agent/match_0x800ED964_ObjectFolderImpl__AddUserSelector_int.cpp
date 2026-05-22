// 0x800ED964 ObjectFolderImpl::AddUserSelector(int, (924 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 25,0x24(1); stw 0,0x44(1); mr 28,3; mr 30,5; mr. 31,4; beq 0f; lwz 9,0x0(28); mr 4,31; lha 3,0x78(9); lwz 0,0x7c(9); add 3,28,3; mtspr 8,0; blrl; cmpwi 3,0; beq 1f; 0:; li 3,0; b 21f; 1:; li 3,196; addi 25,28,64; bl _s800ED964_0; mr 27,3; lwz 9,0x6b8(28); mr 11,27; li 10,192; 2:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 2b; lwz 0,0x0(9); li 3,168; stw 0,0x0(11); stw 31,0x1c(27); sth 30,0xbc(27); bl _s800ED964_1; bl _s800ED964_2; mr 31,3; mr 4,27; addi 3,31,28; addi 26,31,12; bl _s800ED964_3; li 8,0; li 9,0; 3:; rlwinm 0,9,2,0,29; addi 10,9,1; lwzx 9,25,0; li 11,0; cmpwi 9,0; beq 5f; 4:; lwz 9,0xa4(9); addi 11,11,1; cmpwi 9,0; bne 4b; 5:; mr 9,10; add 8,8,11; cmpwi 9,255; ble 3b; stw 8,0x70(31); stw 28,0x50(31); lwz 9,0x0(28); lwz 4,0x698(28); lha 3,0x38(9); lwz 0,0x3c(9); add 3,28,3; mtspr 8,0; blrl; mr. 3,3; beq 6f; lwz 0,0x8(3); stw 0,0x54(31); b 7f; 6:; stw 3,0x54(31); 7:; lwz 0,0x698(28); mr 3,28; stw 0,0x4(31); lwz 4,0x698(28); bl _s800ED964_4; lhz 0,0x7e(31); lis 9,-32706; lis 11,-32706; addi 9,9,-19824; oris 0,0,128; addi 11,11,-19812; rlwinm 0,0,0,30,27; stw 3,0x8(31); ori 0,0,4; stw 9,0x14(31); stw 11,0x18(31); li 3,8; stw 0,0x7c(31); bl _s800ED964_5; mr 4,31; bl _s800ED964_6; stw 3,0x10(31); bl _s800ED964_7; mr 29,3; lwz 4,0x4(31); lwz 30,0x0(29); li 5,0; addi 3,1,8; lha 0,0x20(30); addi 30,30,32; add 29,29,0; bl _s800ED964_8; lwz 0,0x4(30); lis 4,-24789; mr 3,29; mr 6,26; ori 4,4,49436; addi 5,1,8; mtspr 8,0; blrl; cmpwi 3,0; beq 8f; lwz 3,0xc(31); mr 5,31; lwz 4,0x10(31); lwz 9,0x0(3); lha 0,0x28(9); lwz 9,0x2c(9); add 3,3,0; mtspr 8,9; blrl; 8:; lha 0,0xb4(27); cmpwi 0,0; beq 20f; li 3,12; addi 29,28,1632; bl _s800ED964_9; lha 5,0xb4(27); addi 26,1,16; lwz 4,0x1c(27); bl _s800ED964_10; lwz 30,0x4(29); lwz 0,0xc(29); stw 3,0x10(1); cmpw 30,0; beq 9f; stw 3,0x0(30); lwz 9,0x4(29); addi 9,9,4; stw 9,0x4(29); b 20f; 9:; lwz 0,0x660(28); li 9,1; stw 9,0x18(1); addi 11,1,24; subf 0,0,30; addi 9,1,20; srawi 3,0,2; stw 3,0x14(1); cmplwi 3,1; bge 10f; mr 9,11; 10:; lwz 0,0x0(9); add. 0,3,0; beq 12f; rlwinm 0,0,2,0,29; mr 27,0; cmplwi 0,128; ble 11f; mr 3,27; bl _s800ED964_11; mr 28,3; b 13f; 11:; mr 3,27; bl _s800ED964_12; mr 28,3; b 13f; 12:; li 28,0; li 27,0; 13:; lwz 4,0x0(29); cmpw 30,4; beq 14f; subf 30,4,30; mr 3,28; mr 5,30; bl _s800ED964_13; add 0,3,30; b 15f; 14:; mr 0,28; 15:; lwz 9,0x18(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 17f; 16:; lwz 0,0x0(26); stw 0,0x0(30); addi 30,30,4; bdnz 16b; 17:; lwz 3,0x0(29); lwz 0,0xc(29); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 19f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 18f; bl _s800ED964_14; b 19f; 18:; bl _s800ED964_15; 19:; add 0,27,28; stw 28,0x0(29); stw 0,0xc(29); stw 30,0x4(29); 20:; mr 3,31; bl _s800ED964_16; rlwinm 9,3,2,22,29; lwzx 0,25,9; mr 3,31; stw 0,0xa4(31); stwx 31,25,9; 21:; lwz 0,0x44(1); mtspr 8,0; lmw 25,0x24(1); addi 1,1,64"
extern "C" void _s800ED964_0();
extern "C" void _s800ED964_1();
extern "C" void _s800ED964_2();
extern "C" void _s800ED964_3();
extern "C" void _s800ED964_4();
extern "C" void _s800ED964_5();
extern "C" void _s800ED964_6();
extern "C" void _s800ED964_7();
extern "C" void _s800ED964_8();
extern "C" void _s800ED964_9();
extern "C" void _s800ED964_10();
extern "C" void _s800ED964_11();
extern "C" void _s800ED964_12();
extern "C" void _s800ED964_13();
extern "C" void _s800ED964_14();
extern "C" void _s800ED964_15();
extern "C" void _s800ED964_16();
extern "C" void f_800ED964() {}
