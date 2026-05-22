// 0x803ACA40 vector<CTilePt, (540 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 28,3; mr 27,4; cmpw 27,28; beq 18f; lwz 31,0x0(27); lis 11,-21846; lwz 10,0x0(28); ori 11,11,43691; lwz 29,0x4(27); mr 4,31; lwz 0,0xc(28); mr 8,10; subf 3,31,29; subf 0,10,0; mullw 26,3,11; mullw 0,0,11; cmplw 26,0; ble 9f; cmpwi 26,0; beq 1f; cmplwi 3,128; ble 0f; bl _s803ACA40_0; mr 27,3; b 2f; 0:; bl _s803ACA40_1; mr 27,3; b 2f; 1:; li 27,0; 2:; mr 30,27; cmpw 31,29; rlwinm 25,26,1,0,30; beq 4f; 3:; mr 3,30; mr 4,31; bl _s803ACA40_2; addi 31,31,3; addi 30,30,3; cmpw 31,29; bne 3b; 4:; lwz 30,0x4(28); lwz 31,0x0(28); cmpw 31,30; beq 6f; 5:; mr 3,31; li 4,2; bl _s803ACA40_3; addi 31,31,3; cmpw 31,30; bne 5b; 6:; lwz 3,0x0(28); lwz 0,0xc(28); cmpwi 3,0; subf 4,3,0; beq 8f; cmplwi 4,128; ble 7f; bl _s803ACA40_4; b 8f; 7:; bl _s803ACA40_5; 8:; add 0,25,26; stw 27,0x0(28); add 0,27,0; stw 0,0xc(28); b 17f; 9:; lwz 0,0x4(28); subf 0,8,0; mullw 9,0,11; cmplw 9,26; blt 13f; mr 29,4; mr 31,8; mr 30,26; cmpwi 26,0; rlwinm 25,26,1,0,30; ble 11f; 10:; mr 3,31; mr 4,29; bl _s803ACA40_6; addi 29,29,3; addi 31,31,3; addic. 30,30,-1; bgt 10b; 11:; lwz 30,0x4(28); cmpw 31,30; beq 17f; 12:; mr 3,31; li 4,2; bl _s803ACA40_7; addi 31,31,3; cmpw 31,30; bne 12b; b 17f; 13:; mr 29,31; mr 30,10; mullw. 31,0,11; rlwinm 25,26,1,0,30; ble 15f; 14:; mr 3,30; mr 4,29; bl _s803ACA40_8; addi 29,29,3; addi 30,30,3; addic. 31,31,-1; bgt 14b; 15:; lwz 0,0x4(28); lwz 9,0x0(28); lwz 11,0x0(27); mr 30,0; subf 0,9,0; lwz 29,0x4(27); add 31,0,11; cmpw 31,29; beq 17f; 16:; mr 3,30; mr 4,31; bl _s803ACA40_9; addi 31,31,3; addi 30,30,3; cmpw 31,29; bne 16b; 17:; lwz 0,0x0(28); add 9,25,26; add 0,0,9; stw 0,0x4(28); 18:; mr 3,28; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s803ACA40_0();
extern "C" void _s803ACA40_1();
extern "C" void _s803ACA40_2();
extern "C" void _s803ACA40_3();
extern "C" void _s803ACA40_4();
extern "C" void _s803ACA40_5();
extern "C" void _s803ACA40_6();
extern "C" void _s803ACA40_7();
extern "C" void _s803ACA40_8();
extern "C" void _s803ACA40_9();
extern "C" void f_803ACA40() {}
