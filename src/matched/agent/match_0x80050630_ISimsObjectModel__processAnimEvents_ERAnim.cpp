// 0x80050630 ISimsObjectModel::processAnimEvents(ERAnim (440 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 22,0x18(1); stw 0,0x44(1); mr 23,3; mr 26,4; mr 25,5; mr 27,6; mr 30,7; addi 3,1,8; bl _s80050630_0; li 24,0; li 31,0; cmpwi 26,0; beq 0f; addi 9,26,136; addi 3,1,8; mr 4,9; lwz 24,0x4(9); bl _s80050630_1; 0:; cmpwi 30,0; bne 6f; add 28,25,27; cmpw 31,24; mr 22,28; li 29,0; bge 12f; cmpwi 27,0; li 30,0; mfcr 27; 1:; lwz 9,0x8(1); li 31,0; add 5,9,30; lwz 0,0x4(5); cmpwi 0,5; bne 2f; li 31,150; 2:; lwzx 0,9,30; subf. 31,31,0; bge 3f; li 31,0; 3:; cmpw 31,25; blt 5f; mtcrf 128,27; blt 4f; cmpw 31,22; bge 5f; 4:; mr 3,23; mr 4,26; mr 6,29; bl _s80050630_2; cmpwi 3,0; beq 5f; cmpw 28,31; ble 5f; lwz 9,0x8(1); lwzx 28,9,30; 5:; addi 29,29,1; addi 30,30,12; cmpw 29,24; blt 1b; b 12f; 6:; lwz 0,0x14(26); addic. 29,24,-1; subf 25,25,0; subf 28,27,25; blt 12f; mulli 30,29,12; cmpwi 27,0; mfcr 24; mr 27,28; 7:; lwz 9,0x8(1); li 31,0; add 5,9,30; lwz 0,0x4(5); cmpwi 0,5; bne 8f; li 31,150; 8:; lwzx 0,9,30; subf. 31,31,0; bge 9f; li 31,0; 9:; cmpw 31,25; bgt 11f; mtcrf 128,24; blt 10f; cmpw 31,27; ble 11f; 10:; mr 3,23; mr 4,26; mr 6,29; bl _s80050630_3; cmpwi 3,0; beq 11f; cmpw 28,31; bge 11f; lwz 9,0x8(1); lwzx 28,9,30; 11:; addi 30,30,-12; addic. 29,29,-1; bge 7b; 12:; addi 3,1,8; li 4,2; bl _s80050630_4; mr 3,28; lwz 0,0x44(1); mtspr 8,0; lmw 22,0x18(1); addi 1,1,64"
extern "C" void _s80050630_0();
extern "C" void _s80050630_1();
extern "C" void _s80050630_2();
extern "C" void _s80050630_3();
extern "C" void _s80050630_4();
extern "C" void f_80050630() {}
