// 0x800453EC HouseRecon::SaveHouseData(iResFile (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stmw 25,0x54(1); stw 0,0x74(1); mr 26,3; mr 25,4; addis 9,26,1; li 4,0; lwz 29,0x6004(9); addi 28,1,8; cmpwi 29,0; ble 2f; mtspr 9,29; addi 9,9,-32740; 0:; lwz 0,0x0(9); addi 9,9,28; cmpwi 0,0; beq 1f; addi 4,4,1; 1:; bdnz 0b; 2:; li 27,0; cmpwi 4,0; beq 7f; rlwinm 30,4,2,0,29; bl _s800453EC_0; li 4,12; li 5,0; bl _s800453EC_1; mr 31,3; cmpwi 30,0; stw 30,0x0(31); beq 3f; bl _s800453EC_2; mr 4,30; li 5,0; bl _s800453EC_3; stw 3,0x4(31); b 4f; 3:; stw 27,0x4(31); 4:; li 0,1; mr 27,31; stw 0,0x8(31); cmpwi 29,0; lwz 11,0x4(27); ble 7f; mtspr 9,29; addis 9,26,1; addi 3,9,-32764; 5:; lwz 0,0x18(3); cmpwi 0,0; beq 6f; lwz 0,0x0(3); stw 0,0x0(11); addi 11,11,4; 6:; addi 3,3,28; bdnz 5b; 7:; addi 4,28,8; li 5,64; mr 3,28; bl _s800453EC_4; lwz 9,0xc(25); lis 5,17493; mr 4,27; mr 7,28; lha 3,0xf8(9); ori 5,5,19792; lwz 0,0xfc(9); li 6,1; add 3,25,3; li 8,0; mtspr 8,0; blrl; lwz 0,0x74(1); mtspr 8,0; lmw 25,0x54(1); addi 1,1,112"
extern "C" void _s800453EC_0();
extern "C" void _s800453EC_1();
extern "C" void _s800453EC_2();
extern "C" void _s800453EC_3();
extern "C" void _s800453EC_4();
extern "C" void f_800453EC() {}
