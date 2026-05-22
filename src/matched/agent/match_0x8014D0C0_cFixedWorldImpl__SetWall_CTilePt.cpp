// 0x8014D0C0 cFixedWorldImpl::SetWall(CTilePt (1380 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 25,0x14(1); stw 0,0x34(1); lwz 0,-32044(13); mr 25,3; mr 31,4; mr 29,5; cmpwi 0,0; bne 11f; mr 3,29; bl _s8014D0C0_0; mr 3,31; bl _s8014D0C0_1; mr 26,3; mr 3,31; bl _s8014D0C0_2; lwz 9,0x38(25); rlwinm 10,26,2,0,29; mr 27,3; li 4,16; lwz 11,0xc(9); mr 3,29; rlwinm 28,27,3,0,28; lwzx 30,10,11; stw 30,0x8(1); add 31,30,28; bl _s8014D0C0_3; cmpwi 3,0; beq 0f; li 4,32; mr 3,29; bl _s8014D0C0_4; li 0,16; li 4,16; stbx 0,30,28; mr 3,29; bl _s8014D0C0_5; stb 3,0x3(31); li 4,16; li 5,2; mr 3,29; bl _s8014D0C0_6; stb 3,0x6(31); li 5,4; li 4,16; mr 3,29; bl _s8014D0C0_7; stb 3,0x7(31); li 4,2; mr 3,29; bl _s8014D0C0_8; stb 3,0x2(31); li 4,4; mr 3,29; bl _s8014D0C0_9; stb 3,0x4(31); b 1f; 0:; lbzx 0,30,28; andi. 0,0,239; stbx 0,30,28; 1:; mr 3,29; li 4,32; bl _s8014D0C0_10; cmpwi 3,0; beq 2f; li 4,16; mr 3,29; bl _s8014D0C0_11; li 0,32; li 4,32; stb 0,0x0(31); mr 3,29; bl _s8014D0C0_12; stb 3,0x3(31); li 4,32; li 5,1; mr 3,29; bl _s8014D0C0_13; stb 3,0x6(31); li 5,3; li 4,32; mr 3,29; bl _s8014D0C0_14; stb 3,0x7(31); li 4,1; mr 3,29; bl _s8014D0C0_15; stb 3,0x2(31); li 4,3; mr 3,29; bl _s8014D0C0_16; stb 3,0x4(31); b 3f; 2:; lbz 0,0x0(31); andi. 0,0,223; stb 0,0x0(31); 3:; mr 3,29; li 4,1; bl _s8014D0C0_17; mr. 3,3; beq 4f; mr 3,29; bl _s8014D0C0_18; lbz 0,0x0(31); li 4,1; mr 3,29; ori 0,0,1; stb 0,0x0(31); bl _s8014D0C0_19; stb 3,0x2(31); li 4,1; li 5,0; mr 3,29; bl _s8014D0C0_20; stb 3,0x4(31); li 4,1; mr 3,29; bl _s8014D0C0_21; lbz 0,0x1(31); cmpwi 26,0; or 0,0,3; stb 0,0x1(31); ble 5f; lwz 8,0x38(25); addi 9,26,-1; rlwinm 9,9,2,0,29; rlwinm 7,27,3,0,28; lwz 11,0xc(8); lwzx 10,9,11; stw 10,0x8(1); lbzx 0,10,7; ori 0,0,4; stbx 0,10,7; b 5f; 4:; lbz 0,0x0(31); andi. 9,0,1; beq 5f; rlwinm 0,0,0,24,30; cmpwi 26,0; stb 0,0x0(31); ble 5f; lwz 7,0x38(25); addi 9,26,-1; rlwinm 9,9,2,0,29; rlwinm 8,27,3,0,28; lwz 11,0xc(7); lwzx 10,9,11; stw 10,0x8(1); add 9,10,8; lbzx 0,10,8; andi. 0,0,251; stbx 0,10,8; stb 3,0x7(9); 5:; mr 3,29; li 4,2; bl _s8014D0C0_22; mr. 3,3; beq 6f; mr 3,29; bl _s8014D0C0_23; lbz 0,0x0(31); li 4,2; mr 3,29; ori 0,0,2; stb 0,0x0(31); bl _s8014D0C0_24; stb 3,0x3(31); li 4,2; li 5,0; mr 3,29; bl _s8014D0C0_25; stb 3,0x5(31); li 4,2; mr 3,29; bl _s8014D0C0_26; lbz 0,0x1(31); rlwinm 3,3,2,0,29; cmpwi 27,0; or 0,0,3; stb 0,0x1(31); ble 7f; lwz 9,0x38(25); rlwinm 8,26,2,0,29; addi 11,27,-1; lwz 10,0xc(9); rlwinm 11,11,3,0,28; lwzx 9,8,10; stw 9,0x8(1); lbzx 0,9,11; ori 0,0,8; stbx 0,9,11; b 7f; 6:; lbz 0,0x0(31); andi. 9,0,2; beq 7f; andi. 0,0,253; cmpwi 27,0; stb 0,0x0(31); ble 7f; lwz 9,0x38(25); rlwinm 8,26,2,0,29; addi 11,27,-1; lwz 10,0xc(9); rlwinm 11,11,3,0,28; lwzx 9,8,10; stw 9,0x8(1); add 10,9,11; lbzx 0,9,11; andi. 0,0,247; stbx 0,9,11; stb 3,0x6(10); 7:; mr 3,29; li 4,4; bl _s8014D0C0_27; mr. 3,3; beq 8f; mr 3,29; bl _s8014D0C0_28; lbz 0,0x0(31); mr 3,29; li 4,4; li 5,0; ori 0,0,4; stb 0,0x0(31); bl _s8014D0C0_29; stb 3,0x7(31); lwz 9,0x14(25); addi 9,9,-1; cmpw 26,9; bge 9f; lwz 9,0x38(25); addi 11,26,1; rlwinm 11,11,2,0,29; rlwinm 10,27,3,0,28; lwz 8,0xc(9); li 4,4; mr 3,29; lwzx 9,11,8; stw 9,0x8(1); add 30,9,10; lbzx 0,9,10; ori 0,0,1; stbx 0,9,10; bl _s8014D0C0_30; stb 3,0x2(30); li 4,4; mr 3,29; bl _s8014D0C0_31; lbz 0,0x1(30); or 0,0,3; stb 0,0x1(30); b 9f; 8:; lbz 0,0x0(31); andi. 9,0,4; beq 9f; andi. 0,0,251; stb 0,0x0(31); lwz 9,0x14(25); addi 9,9,-1; cmpw 26,9; bge 9f; lwz 7,0x38(25); addi 9,26,1; rlwinm 9,9,2,0,29; rlwinm 8,27,3,0,28; lwz 11,0xc(7); lwzx 10,9,11; stw 10,0x8(1); add 9,10,8; lbzx 0,10,8; rlwinm 0,0,0,24,30; stbx 0,10,8; stb 3,0x4(9); 9:; mr 3,29; li 4,8; bl _s8014D0C0_32; mr. 3,3; beq 10f; mr 3,29; bl _s8014D0C0_33; lbz 0,0x0(31); mr 3,29; li 4,8; li 5,0; ori 0,0,8; stb 0,0x0(31); bl _s8014D0C0_34; stb 3,0x6(31); lwz 9,0x18(25); addi 9,9,-1; cmpw 27,9; bge 11f; lwz 9,0x38(25); rlwinm 8,26,2,0,29; addi 11,27,1; li 4,8; lwz 10,0xc(9); rlwinm 11,11,3,0,28; mr 3,29; lwzx 9,8,10; stw 9,0x8(1); add 30,9,11; lbzx 0,9,11; ori 0,0,2; stbx 0,9,11; bl _s8014D0C0_35; stb 3,0x3(30); li 4,8; mr 3,29; bl _s8014D0C0_36; lbz 0,0x1(30); rlwinm 3,3,2,0,29; or 0,0,3; stb 0,0x1(30); b 11f; 10:; lbz 0,0x0(31); andi. 9,0,8; beq 11f; andi. 0,0,247; stb 0,0x0(31); lwz 9,0x18(25); addi 9,9,-1; cmpw 27,9; bge 11f; lwz 9,0x38(25); rlwinm 8,26,2,0,29; addi 11,27,1; lwz 10,0xc(9); rlwinm 11,11,3,0,28; lwzx 9,8,10; stw 9,0x8(1); add 10,9,11; lbzx 0,9,11; andi. 0,0,253; stbx 0,9,11; stb 3,0x5(10); 11:; mr 3,29; li 4,2; bl _s8014D0C0_37; lwz 0,0x34(1); mtspr 8,0; lmw 25,0x14(1); addi 1,1,48"
extern "C" void _s8014D0C0_0();
extern "C" void _s8014D0C0_1();
extern "C" void _s8014D0C0_2();
extern "C" void _s8014D0C0_3();
extern "C" void _s8014D0C0_4();
extern "C" void _s8014D0C0_5();
extern "C" void _s8014D0C0_6();
extern "C" void _s8014D0C0_7();
extern "C" void _s8014D0C0_8();
extern "C" void _s8014D0C0_9();
extern "C" void _s8014D0C0_10();
extern "C" void _s8014D0C0_11();
extern "C" void _s8014D0C0_12();
extern "C" void _s8014D0C0_13();
extern "C" void _s8014D0C0_14();
extern "C" void _s8014D0C0_15();
extern "C" void _s8014D0C0_16();
extern "C" void _s8014D0C0_17();
extern "C" void _s8014D0C0_18();
extern "C" void _s8014D0C0_19();
extern "C" void _s8014D0C0_20();
extern "C" void _s8014D0C0_21();
extern "C" void _s8014D0C0_22();
extern "C" void _s8014D0C0_23();
extern "C" void _s8014D0C0_24();
extern "C" void _s8014D0C0_25();
extern "C" void _s8014D0C0_26();
extern "C" void _s8014D0C0_27();
extern "C" void _s8014D0C0_28();
extern "C" void _s8014D0C0_29();
extern "C" void _s8014D0C0_30();
extern "C" void _s8014D0C0_31();
extern "C" void _s8014D0C0_32();
extern "C" void _s8014D0C0_33();
extern "C" void _s8014D0C0_34();
extern "C" void _s8014D0C0_35();
extern "C" void _s8014D0C0_36();
extern "C" void _s8014D0C0_37();
extern "C" void f_8014D0C0() {}
