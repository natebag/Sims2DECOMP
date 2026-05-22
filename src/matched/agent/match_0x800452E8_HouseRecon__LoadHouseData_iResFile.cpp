// 0x800452E8 HouseRecon::LoadHouseData(iResFile (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 30,4; mr 28,3; lis 5,28514; stw 28,0x8(1); stw 28,0xc(1); addi 3,1,8; ori 5,5,27252; li 6,0; li 7,0; bl _s800452E8_0; lis 5,20322; addi 3,1,12; mr 4,30; ori 5,5,27213; li 6,1; li 7,0; bl _s800452E8_1; lwz 9,0xc(30); lis 4,17493; ori 4,4,19792; li 5,1; lwz 0,0x84(9); li 6,0; lha 3,0x80(9); mtspr 8,0; add 3,30,3; blrl; mr. 3,3; li 0,0; mcrf cr7,cr0; beq cr7,0f; lwz 0,0x0(3); 0:; cmpwi 0,0; beq 4f; lwz 4,0x4(3); li 0,0; beq cr7,1f; lwz 0,0x0(3); 1:; rlwinm. 9,0,30,2,31; mtspr 9,9; beq 4f; addis 9,28,1; mr 31,4; addi 29,9,-32740; mfspr 30,9; li 27,1; 2:; lwz 4,0x0(31); mr 3,28; addi 31,31,4; bl _s800452E8_2; mr. 3,3; blt 3f; mulli 0,3,28; stwx 27,29,0; 3:; addic. 30,30,-1; bne 2b; 4:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s800452E8_0();
extern "C" void _s800452E8_1();
extern "C" void _s800452E8_2();
extern "C" void f_800452E8() {}
