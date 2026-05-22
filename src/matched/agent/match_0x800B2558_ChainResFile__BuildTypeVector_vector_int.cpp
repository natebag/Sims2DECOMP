// 0x800B2558 ChainResFile::BuildTypeVector(vector<int, (620 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 23,0x1c(1); stw 0,0x44(1); mr 25,3; li 27,0; addi 29,25,16; mr 28,4; lwzx 0,29,27; cmpwi 0,0; beq 19f; 0:; mulli 30,27,24; lwzx 11,29,30; mr 23,30; lwz 9,0xc(11); lha 3,0x68(9); lwz 0,0x6c(9); add 3,11,3; mtspr 8,0; blrl; mr 31,3; lwzx 3,29,30; bl _s800B2558_0; cmpwi 3,0; beq 1f; lwzx 3,29,23; li 31,0; bl _s800B2558_1; mr 4,3; mr 3,25; bl _s800B2558_2; 1:; addi 26,27,1; cmpwi 31,0; beq 18f; 2:; addi 9,25,16; mr 4,31; lwzx 11,9,23; addi 24,31,-1; lwz 9,0xc(11); lwz 0,0x74(9); lha 3,0x70(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(28); li 10,0; lwz 0,0x4(28); stw 3,0x8(1); cmpw 9,0; beq 5f; lwz 0,0x0(9); mr 11,3; cmpw 0,3; b 4f; 3:; lwz 0,0x4(28); addi 9,9,4; cmpw 9,0; beq 5f; lwz 0,0x0(9); cmpw 0,11; 4:; bne 3b; li 10,1; 5:; cmpwi 10,0; bne 17f; lwz 0,0x4(28); addi 27,1,8; lwz 9,0xc(28); mr 30,0; cmpw 0,9; beq 6f; lwz 0,0x8(1); stw 0,0x0(30); lwz 9,0x4(28); addi 9,9,4; stw 9,0x4(28); b 17f; 6:; lwz 9,0x0(28); li 0,1; stw 0,0x10(1); addi 11,1,12; subf 9,9,30; addi 0,1,16; srawi 9,9,2; stw 9,0xc(1); cmplwi 9,1; bge 7f; mr 11,0; 7:; lwz 0,0x0(11); add. 0,9,0; beq 9f; rlwinm 0,0,2,0,29; mr 29,0; cmplwi 0,128; ble 8f; mr 3,29; bl _s800B2558_3; mr 31,3; b 10f; 8:; mr 3,29; bl _s800B2558_4; mr 31,3; b 10f; 9:; li 31,0; li 29,0; 10:; lwz 4,0x0(28); cmpw 30,4; beq 11f; subf 30,4,30; mr 3,31; mr 5,30; bl _s800B2558_5; add 0,3,30; b 12f; 11:; mr 0,31; 12:; lwz 9,0x10(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 14f; 13:; lwz 0,0x0(27); stw 0,0x0(30); addi 30,30,4; bdnz 13b; 14:; lwz 3,0x0(28); lwz 0,0xc(28); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 16f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 15f; bl _s800B2558_6; b 16f; 15:; bl _s800B2558_7; 16:; add 0,29,31; stw 31,0x0(28); stw 30,0x4(28); stw 0,0xc(28); 17:; extsh 31,24; cmpwi 31,0; bne 2b; 18:; mr 27,26; cmpwi 26,7; bgt 19f; mulli 9,26,24; addi 29,25,16; lwzx 0,29,9; cmpwi 0,0; bne 0b; 19:; lwz 0,0x44(1); mtspr 8,0; lmw 23,0x1c(1); addi 1,1,64"
extern "C" void _s800B2558_0();
extern "C" void _s800B2558_1();
extern "C" void _s800B2558_2();
extern "C" void _s800B2558_3();
extern "C" void _s800B2558_4();
extern "C" void _s800B2558_5();
extern "C" void _s800B2558_6();
extern "C" void _s800B2558_7();
extern "C" void f_800B2558() {}
