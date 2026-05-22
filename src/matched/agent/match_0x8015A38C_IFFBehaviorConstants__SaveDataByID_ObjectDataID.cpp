// 0x8015A38C IFFBehaviorConstants::SaveDataByID(ObjectDataID (412 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); lwz 9,-21508(13); mr 29,3; mr 25,4; lwz 11,0x0(9); lwz 4,0x0(25); lha 3,0x38(11); lwz 0,0x3c(11); add 3,9,3; mtspr 8,0; blrl; mr 27,3; mr 3,29; bl _s8015A38C_0; rlwinm 31,3,1,0,30; bl _s8015A38C_1; addi 31,31,2; li 4,12; li 5,0; bl _s8015A38C_2; mr 28,3; cmpwi 31,0; stw 31,0x0(28); beq 0f; bl _s8015A38C_3; mr 4,31; li 5,0; bl _s8015A38C_4; stw 3,0x4(28); b 1f; 0:; stw 31,0x4(28); 1:; li 0,1; lwz 30,0x4(28); stw 0,0x8(28); mr 3,29; bl _s8015A38C_5; lhz 0,0x0(30); rlwinm 9,3,0,17,31; mr 3,29; rlwinm 0,0,0,0,16; or 0,0,9; sth 0,0x0(30); bl _s8015A38C_6; lhz 0,0x0(30); cmpwi 3,0; rlwinm 0,0,0,17,31; sth 0,0x0(30); beq 2f; ori 0,0,32768; sth 0,0x0(30); 2:; li 31,0; addi 26,29,24; b 4f; 3:; lwz 10,0x14(29); add 9,31,31; add 11,30,9; addi 31,31,1; lhzx 0,9,10; sth 0,0x2(11); 4:; mr 3,29; bl _s8015A38C_7; cmpw 31,3; blt 3b; lwz 9,0xc(27); lis 5,16963; lha 6,0x4(25); mr 7,26; lha 3,0xf8(9); mr 4,28; lwz 0,0xfc(9); ori 5,5,20302; add 3,27,3; li 8,0; mtspr 8,0; blrl; mr 3,27; bl _s8015A38C_8; cmpwi 3,0; bne 5f; lwz 9,0xc(27); mr 4,28; lwz 0,0x10c(9); lha 3,0x108(9); mtspr 8,0; add 3,27,3; blrl; mr 3,27; bl _s8015A38C_9; lwz 9,0xc(27); lha 3,0x48(9); lwz 0,0x4c(9); add 3,27,3; mtspr 8,0; blrl; 5:; li 3,1; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s8015A38C_0();
extern "C" void _s8015A38C_1();
extern "C" void _s8015A38C_2();
extern "C" void _s8015A38C_3();
extern "C" void _s8015A38C_4();
extern "C" void _s8015A38C_5();
extern "C" void _s8015A38C_6();
extern "C" void _s8015A38C_7();
extern "C" void _s8015A38C_8();
extern "C" void _s8015A38C_9();
extern "C" void f_8015A38C() {}
