// 0x800E05BC cXObjectImpl::ReconStream(ReconBuffer (1516 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; mfcr 12; stmw 20,0x20(1); stw 0,0x54(1); stw 12,0x1c(1); mr 31,3; mr 29,5; lwz 3,0x4(31); mr 28,4; lwz 9,0x4(3); mr 27,6; lha 0,0x500(9); lwz 9,0x504(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 29,0; bgt 0f; lwz 4,0x8(31); mr 3,28; li 5,8; addi 30,31,22; bl _s800E05BC_0; mr 21,30; mr 4,30; cmpwi 29,10; mr 3,28; li 5,32; mfcr 30; bl _s800E05BC_1; b 1f; 0:; cmpwi 29,10; addi 21,31,22; mfcr 30; bgt 2f; lwz 4,0x8(31); mr 3,28; li 5,8; bl _s800E05BC_2; mr 3,28; mr 4,21; li 5,8; bl _s800E05BC_3; 1:; cmpwi 27,0; addi 26,1,10; cmpwi 7,29,33; addi 23,29,-66; mfcr 20; mfcr 25; rlwinm 25,25,28,0,3; cmpwi 29,51; mfcr 24; cmpwi 7,29,26; mtcrf 128,30; cmpwi 3,29,4; mfcr 22; rlwinm 22,22,28,0,3; cmpwi 2,29,12; ble 11f; 2:; cmpwi 29,23; bgt 3f; cmpwi 7,27,0; lwz 4,0x8(31); mfcr 20; rlwinm 20,20,28,0,3; mr 3,28; li 5,8; cmpwi 4,29,82; bl _s800E05BC_4; cmpwi 3,29,4; cmpwi 29,33; addi 26,1,10; mfcr 25; addi 23,29,-66; cmpwi 7,29,51; cmpwi 29,26; mfcr 24; rlwinm 24,24,28,0,3; cmpwi 2,29,12; mfcr 22; b 9f; 3:; lha 0,0xe(31); li 5,1; mr 3,28; addi 4,1,8; sth 0,0x8(1); bl _s800E05BC_5; lha 5,0x8(1); lwz 0,0xc(31); cmpw 5,0; ble 8f; cmpwi 27,0; mfcr 20; beq 5f; lwz 3,0x8(31); cmpwi 3,0; beq 4f; bl _s800E05BC_6; 4:; lha 0,0x8(1); addi 26,1,10; cmpwi 4,29,82; addi 23,29,-66; rlwinm 3,0,1,0,30; stw 0,0xc(31); bl _s800E05BC_7; cmpwi 3,29,4; lha 5,0x8(1); cmpwi 29,33; mr 4,3; stw 3,0x8(31); mfcr 25; mr 3,28; bl _s800E05BC_8; cmpwi 2,29,12; cmpwi 29,51; cmpwi 7,29,26; mfcr 24; mfcr 22; rlwinm 22,22,28,0,3; b 9f; 5:; rlwinm 3,5,1,0,30; cmpwi 4,29,82; bl _s800E05BC_9; cmpwi 3,29,4; mr 30,3; lha 5,0x8(1); addi 26,1,10; mr 3,28; mr 4,30; cmpwi 2,29,12; bl _s800E05BC_10; addi 23,29,-66; cmpwi 7,29,33; lwz 0,0xc(31); mfcr 25; rlwinm 25,25,28,0,3; li 10,0; cmpwi 7,29,51; mfcr 24; rlwinm 24,24,28,0,3; cmpw 27,0; cmpwi 7,29,26; mfcr 22; rlwinm 22,22,28,0,3; bge 7f; li 11,0; 6:; lhzx 0,11,30; addi 10,10,1; lwz 9,0x8(31); sthx 0,11,9; addi 11,11,2; lwz 0,0xc(31); cmpw 10,0; blt 6b; 7:; cmpwi 30,0; beq 9f; mr 3,30; bl _s800E05BC_11; b 9f; 8:; lwz 4,0x8(31); mr 3,28; cmpwi 4,29,82; bl _s800E05BC_12; cmpwi 3,29,4; cmpwi 27,0; addi 26,1,10; cmpwi 7,29,33; addi 23,29,-66; mfcr 20; mfcr 25; rlwinm 25,25,28,0,3; cmpwi 29,51; cmpwi 7,29,26; cmpwi 2,29,12; mfcr 22; rlwinm 22,22,28,0,3; mfcr 24; 9:; mr 4,21; mr 3,28; li 5,8; bl _s800E05BC_13; bgt cr4,10f; addi 3,31,40; mr 4,28; li 5,72; bl _s800E05BC_14; b 11f; 10:; cmpwi 29,83; ble 11f; addi 3,31,40; mr 4,28; mr 5,29; bl _s800E05BC_15; 11:; li 0,0; mr 4,26; sth 0,0xa(1); li 5,1; mr 3,28; bl _s800E05BC_16; lwz 11,0x4(31); lwz 30,0x0(31); lwz 9,0x4(11); addi 30,30,12; lwz 0,0x224(9); lha 3,0x220(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(3); lha 0,0x168(9); lwz 9,0x16c(9); add 3,3,0; mtspr 8,9; blrl; mr 6,3; mr 4,28; mr 3,30; mr 5,29; bl _s800E05BC_17; ble cr3,13f; cmpwi 29,6; bgt 12f; lwz 3,0x60(31); mr 4,28; li 5,0; lwz 9,0x0(3); lha 0,0x50(9); lwz 9,0x54(9); add 3,3,0; mtspr 8,9; blrl; b 13f; 12:; lwz 3,0x60(31); mr 4,28; mr 5,29; lwz 9,0x0(3); lha 0,0x50(9); lwz 9,0x54(9); add 3,3,0; mtspr 8,9; blrl; 13:; bgt cr2,14f; lwz 0,0xc(28); cmpwi 0,0; bne 14f; addi 30,31,40; li 4,9; li 5,0; mr 3,30; bl _s800E05BC_18; mr 3,30; li 4,10; li 5,0; bl _s800E05BC_19; 14:; mtcrf 128,25; bgt 15f; addi 30,31,40; li 4,16; li 5,0; mr 3,30; bl _s800E05BC_20; mr 3,30; li 4,17; li 5,0; bl _s800E05BC_21; 15:; lwz 3,0x4(31); mr 5,29; mr 4,28; lwz 9,0x4(3); lha 0,0x4f8(9); lwz 9,0x4fc(9); add 3,3,0; mtspr 8,9; blrl; cmplwi 23,20; bgt 16f; li 0,0; mr 3,28; stw 0,0x10(1); addi 4,1,16; li 5,1; bl _s800E05BC_22; 16:; mtcrf 128,24; bgt 17f; lwz 5,0x94(31); addi 3,31,40; lwz 0,0x90(31); li 4,67; subf 5,0,5; srawi 5,5,5; addi 5,5,-1; extsh 5,5; bl _s800E05BC_23; 17:; mtcrf 128,22; ble 20f; lha 0,0x14(31); mr 3,28; addi 4,1,12; li 5,1; sth 0,0xc(1); bl _s800E05BC_24; lha 9,0xc(1); lha 0,0x14(31); cmpw 9,0; ble 19f; mtcrf 128,20; beq 19f; lwz 3,0x10(31); cmpwi 3,0; beq 18f; bl _s800E05BC_25; 18:; lha 0,0xc(1); mr 3,0; sth 0,0x14(31); rlwinm 3,3,1,0,30; bl _s800E05BC_26; stw 3,0x10(31); 19:; lwz 4,0x10(31); mr 3,28; lha 5,0xc(1); bl _s800E05BC_27; 20:; mtcrf 128,20; beq 21f; addi 3,31,40; li 4,1; li 5,0; bl _s800E05BC_28; 21:; lwz 9,0x0(31); lwz 10,0x0(9); lwz 11,0x18(10); lha 3,0x98(11); lwz 0,0x9c(11); add 3,10,3; mtspr 8,0; blrl; cmpwi 3,0; beq 22f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x4b8(9); lwz 9,0x4bc(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 22f; lwz 9,0x0(31); lwz 10,0x0(9); lwz 11,0x18(10); lwz 0,0x9c(11); lha 3,0x98(11); mtspr 8,0; add 3,10,3; blrl; lwz 11,0x4(31); mr 29,3; lwz 30,0x0(29); lwz 9,0x4(11); lha 0,0x120(30); lha 3,0x4b8(9); addi 30,30,288; lwz 9,0x4bc(9); add 29,29,0; add 3,11,3; mtspr 8,9; blrl; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; 22:; lwz 0,0x54(1); lwz 12,0x1c(1); mtspr 8,0; lmw 20,0x20(1); mtcrf 56,12; addi 1,1,80"
extern "C" void _s800E05BC_0();
extern "C" void _s800E05BC_1();
extern "C" void _s800E05BC_2();
extern "C" void _s800E05BC_3();
extern "C" void _s800E05BC_4();
extern "C" void _s800E05BC_5();
extern "C" void _s800E05BC_6();
extern "C" void _s800E05BC_7();
extern "C" void _s800E05BC_8();
extern "C" void _s800E05BC_9();
extern "C" void _s800E05BC_10();
extern "C" void _s800E05BC_11();
extern "C" void _s800E05BC_12();
extern "C" void _s800E05BC_13();
extern "C" void _s800E05BC_14();
extern "C" void _s800E05BC_15();
extern "C" void _s800E05BC_16();
extern "C" void _s800E05BC_17();
extern "C" void _s800E05BC_18();
extern "C" void _s800E05BC_19();
extern "C" void _s800E05BC_20();
extern "C" void _s800E05BC_21();
extern "C" void _s800E05BC_22();
extern "C" void _s800E05BC_23();
extern "C" void _s800E05BC_24();
extern "C" void _s800E05BC_25();
extern "C" void _s800E05BC_26();
extern "C" void _s800E05BC_27();
extern "C" void _s800E05BC_28();
extern "C" void f_800E05BC() {}
