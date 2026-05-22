// 0x8028ED54 AptCharacterInst::sMethod_getNewTextFormat(AptValue (1060 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stfd f31,0x30(1); stmw 26,0x18(1); stw 0,0x3c(1); mr 28,3; cmpwi 4,0; ble 0f; lwz 3,-22936(13); b 23f; 0:; lwz 27,0x4c(28); lwz 0,0x68(27); cmpwi 0,0; bne 9f; lwz 3,-23020(13); li 4,32; li 30,-1; li 26,2; bl _s8028ED54_0; mr 31,3; lis 9,-32704; lfs f31,0x4e90(9); lwz 29,-22936(13); bl _s8028ED54_1; stfs f31,0x4(31); mr 3,29; stw 30,0x1c(31); stw 30,0x8(31); stw 26,0x10(31); stw 30,0x14(31); stw 30,0x18(31); bl _s8028ED54_2; cmpwi 3,0; bne 1f; mr 3,29; mr 4,31; bl _s8028ED54_3; 1:; mr 3,29; bl _s8028ED54_4; mr. 30,3; bne 7f; addi 3,1,8; bl _s8028ED54_5; addi 4,1,8; mr 3,29; bl _s8028ED54_6; lis 4,-32704; addi 3,1,8; addi 4,4,18408; bl _s8028ED54_7; cmpwi 3,0; bne 2f; lis 4,-32704; addi 3,1,8; addi 4,4,18416; bl _s8028ED54_8; cmpwi 3,0; beq 3f; 2:; stw 30,0xc(31); b 6f; 3:; lis 4,-32704; addi 3,1,8; addi 4,4,18424; bl _s8028ED54_9; cmpwi 3,0; beq 4f; stw 26,0xc(31); b 6f; 4:; lis 4,-32704; addi 3,1,8; addi 4,4,18432; bl _s8028ED54_10; cmpwi 3,0; li 0,3; beq 5f; li 0,1; 5:; stw 0,0xc(31); 6:; addi 3,1,8; li 4,2; bl _s8028ED54_11; b 8f; 7:; li 0,3; stw 0,0xc(31); 8:; stw 31,0x68(27); 9:; lwz 3,-23016(13); li 4,68; bl _s8028ED54_12; lwz 9,0x4c(28); mr 29,3; li 4,36; lwz 30,0x68(9); addi 31,29,36; bl _s8028ED54_13; lis 9,-32703; li 4,8; addi 9,9,8984; addi 3,29,12; stw 9,0x8(29); bl _s8028ED54_14; li 0,0; lis 9,-32703; stb 0,0x20(29); addi 9,9,21120; lis 4,-32704; stw 9,0x8(29); lwz 0,0x20(29); addi 4,4,18440; mr 3,31; rlwinm 0,0,0,10,7; stw 0,0x20(29); bl _s8028ED54_15; lis 9,-32704; li 11,-1; lfs f31,0x4e90(9); li 0,3; li 9,2; stw 0,0xc(31); stfs f31,0x4(31); mr 3,31; stw 9,0x10(31); mr 4,30; stw 11,0x1c(31); stw 11,0x8(31); stw 11,0x14(31); stw 11,0x18(31); bl _s8028ED54_16; lis 9,-32703; addi 9,9,4912; stw 9,0x8(29); lwz 0,0xc(30); cmpwi 0,3; beq 10f; stw 0,0xc(31); 10:; lwz 0,0x8(30); cmpwi 0,-1; beq 11f; stw 0,0x8(31); 11:; lis 4,-32704; mr 3,30; addi 4,4,18440; bl _s8028ED54_17; cmpwi 3,0; beq 12f; mr 3,31; mr 4,30; bl _s8028ED54_18; 12:; lfs f0,0x4(30); fcmpu 0,f0,f31; beq 13f; stfs f0,0x4(31); 13:; lwz 0,0x10(30); cmpwi 0,2; beq 14f; stw 0,0x10(31); 14:; lwz 0,0x14(30); cmpwi 0,-1; beq 15f; stw 0,0x14(31); 15:; lwz 0,0x18(30); cmpwi 0,-1; beq 16f; stw 0,0x18(31); 16:; lwz 3,0x1c(30); cmpwi 3,-1; beq 17f; stw 3,0x1c(31); 17:; lwz 0,0x2c(29); cmpwi 0,-1; bne 18f; lwz 9,0x4c(28); lwz 0,0x24(9); stw 0,0x2c(29); 18:; lwz 9,0x4c(28); lwz 11,0x8(9); lwz 9,0x4(11); lwz 10,0x18(11); addi 9,9,8; lwz 0,0xc(9); cmpw 10,0; bge 20f; cmpwi 10,-1; beq 20f; lwz 9,0x10(9); rlwinm 11,10,2,0,29; lwzx 9,11,9; lwz 0,0x0(9); cmpwi 0,3; bne 20f; lwz 4,0x8(9); addi 3,1,8; bl _s8028ED54_19; lwz 11,0x8(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x24(29); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 19f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8028ED54_20; 19:; lwz 0,0x8(1); stw 0,0x0(31); lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 22f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8028ED54_21; b 22f; 20:; lis 4,-32704; addi 3,1,8; addi 4,4,18440; bl _s8028ED54_22; lwz 11,0x8(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x24(29); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 21f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8028ED54_23; 21:; lwz 0,0x8(1); stw 0,0x24(29); lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 22f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8028ED54_24; 22:; lwz 9,0x4c(28); mr 3,29; lwz 0,0x3c(9); stw 0,0x30(29); lwz 9,0x4c(28); lfs f0,0x60(9); stfs f0,0x28(29); 23:; lwz 0,0x3c(1); mtspr 8,0; lmw 26,0x18(1); lfd f31,0x30(1); addi 1,1,56"
extern "C" void _s8028ED54_0();
extern "C" void _s8028ED54_1();
extern "C" void _s8028ED54_2();
extern "C" void _s8028ED54_3();
extern "C" void _s8028ED54_4();
extern "C" void _s8028ED54_5();
extern "C" void _s8028ED54_6();
extern "C" void _s8028ED54_7();
extern "C" void _s8028ED54_8();
extern "C" void _s8028ED54_9();
extern "C" void _s8028ED54_10();
extern "C" void _s8028ED54_11();
extern "C" void _s8028ED54_12();
extern "C" void _s8028ED54_13();
extern "C" void _s8028ED54_14();
extern "C" void _s8028ED54_15();
extern "C" void _s8028ED54_16();
extern "C" void _s8028ED54_17();
extern "C" void _s8028ED54_18();
extern "C" void _s8028ED54_19();
extern "C" void _s8028ED54_20();
extern "C" void _s8028ED54_21();
extern "C" void _s8028ED54_22();
extern "C" void _s8028ED54_23();
extern "C" void _s8028ED54_24();
extern "C" void f_8028ED54() {}
