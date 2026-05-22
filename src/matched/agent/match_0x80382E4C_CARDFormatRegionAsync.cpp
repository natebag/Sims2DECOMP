// 0x80382E4C __CARDFormatRegionAsync (1624 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-88(1); stmw 18,0x20(1); addi 20,4,0; addi 22,3,0; addi 19,5,0; addi 4,1,24; bl _s80382E4C_0; cmpwi 3,0; bge 0f; b 14f; 0:; lwz 3,0x18(1); li 4,255; li 5,8192; lwz 27,0x80(3); mr 3,27; bl _s80382E4C_1; lis 3,-13312; lhz 18,0x206e(3); sth 20,0x24(27); bl _s80382E4C_2; lwz 0,0xc(3); stw 0,0x14(27); lbz 0,0x12(3); li 3,0; stw 0,0x18(27); bl _s80382E4C_3; bl _s80382E4C_4; addi 21,4,0; addi 20,3,0; addi 26,21,0; addi 30,20,0; bl _s80382E4C_5; mulli 0,22,12; add 25,3,0; lis 3,16838; addi 24,25,0; addi 31,3,20077; li 28,0; li 23,4; b 2f; 1:; mullw 5,30,31; mulhwu 3,26,31; li 30,0; add 5,5,3; mullw 3,26,30; mullw 0,26,31; li 29,12345; addc 4,0,29; add 0,5,3; adde 3,0,30; li 5,16; bl _s80382E4C_6; mullw 6,3,31; lbz 0,0x0(24); mulhwu 5,4,31; add 6,6,5; addc 8,4,0; extsh 7,28; mullw 5,4,30; stbx 8,27,7; mullw 0,4,31; addc 4,0,29; add 0,6,5; adde 3,0,30; li 5,16; bl _s80382E4C_7; li 26,32767; and 0,3,30; and 4,4,26; mullw 5,0,31; mulhwu 3,4,31; add 5,5,3; mullw 3,4,30; mullw 0,4,31; addc 4,0,29; add 0,5,3; adde 3,0,30; li 5,16; bl _s80382E4C_8; mullw 6,3,31; mulhwu 5,4,31; addi 9,28,1; extsh 9,9; lbzx 0,25,9; add 6,6,5; mullw 5,4,30; addc 7,4,0; mullw 0,4,31; stbx 7,27,9; addc 4,0,29; add 0,6,5; adde 3,0,30; li 5,16; bl _s80382E4C_9; and 0,3,30; and 4,4,26; mullw 5,0,31; mulhwu 3,4,31; add 5,5,3; mullw 3,4,30; mullw 0,4,31; addc 4,0,29; add 0,5,3; adde 3,0,30; li 5,16; bl _s80382E4C_10; mullw 6,3,31; mulhwu 5,4,31; addi 9,28,2; extsh 9,9; lbzx 0,25,9; add 6,6,5; mullw 5,4,30; addc 7,4,0; mullw 0,4,31; stbx 7,27,9; addc 4,0,29; add 0,6,5; adde 3,0,30; li 5,16; bl _s80382E4C_11; and 0,3,30; and 4,4,26; mullw 5,0,31; mulhwu 3,4,31; add 5,5,3; mullw 3,4,30; mullw 0,4,31; addc 4,0,29; add 0,5,3; adde 3,0,30; li 5,16; bl _s80382E4C_12; mullw 6,3,31; mulhwu 5,4,31; addi 9,28,3; extsh 9,9; lbzx 0,25,9; add 6,6,5; mullw 5,4,30; addc 7,4,0; mullw 0,4,31; stbx 7,27,9; addc 4,0,29; add 0,6,5; adde 3,0,30; li 5,16; bl _s80382E4C_13; and 0,3,30; and 4,4,26; mullw 5,0,31; mulhwu 3,4,31; add 5,5,3; mullw 3,4,30; mullw 0,4,31; addc 4,0,29; add 0,5,3; adde 3,0,30; li 5,16; bl _s80382E4C_14; mullw 6,3,31; mulhwu 5,4,31; addi 9,28,4; extsh 9,9; lbzx 0,25,9; add 6,6,5; mullw 5,4,30; addc 7,4,0; mullw 0,4,31; stbx 7,27,9; addc 4,0,29; add 0,6,5; adde 3,0,30; li 5,16; bl _s80382E4C_15; and 0,3,30; and 4,4,26; mullw 5,0,31; mulhwu 3,4,31; add 5,5,3; mullw 3,4,30; mullw 0,4,31; addc 4,0,29; add 0,5,3; adde 3,0,30; li 5,16; bl _s80382E4C_16; mullw 6,3,31; mulhwu 5,4,31; addi 9,28,5; extsh 9,9; lbzx 0,25,9; add 6,6,5; mullw 5,4,30; addc 7,4,0; mullw 0,4,31; stbx 7,27,9; addc 4,0,29; add 0,6,5; adde 3,0,30; li 5,16; bl _s80382E4C_17; and 0,3,30; and 4,4,26; mullw 5,0,31; mulhwu 3,4,31; add 5,5,3; mullw 3,4,30; mullw 0,4,31; addc 4,0,29; add 0,5,3; adde 3,0,30; li 5,16; bl _s80382E4C_18; mullw 6,3,31; mulhwu 5,4,31; addi 9,28,6; extsh 9,9; lbzx 0,25,9; add 6,6,5; mullw 5,4,30; addc 7,4,0; mullw 0,4,31; stbx 7,27,9; addc 4,0,29; add 0,6,5; adde 3,0,30; li 5,16; bl _s80382E4C_19; and 0,3,30; and 4,4,26; mullw 5,0,31; mulhwu 3,4,31; add 5,5,3; mullw 3,4,30; mullw 0,4,31; addc 4,0,29; add 0,5,3; adde 3,0,30; li 5,16; bl _s80382E4C_20; mullw 6,3,31; mulhwu 5,4,31; addi 9,28,7; extsh 9,9; lbzx 0,25,9; add 6,6,5; mullw 5,4,30; addc 7,4,0; mullw 0,4,31; stbx 7,27,9; addc 4,0,29; add 0,6,5; adde 3,0,30; li 5,16; bl _s80382E4C_21; and 26,4,26; and 30,3,30; addi 24,24,8; addi 28,28,8; 2:; extsh 0,28; cmpw 0,23; blt 1b; b 13f; 3:; lis 3,16838; addi 25,3,20077; b 5f; 4:; mullw 5,30,25; mulhwu 3,26,25; li 24,0; add 5,5,3; mullw 3,26,24; mullw 0,26,25; li 23,12345; addc 4,0,23; add 0,5,3; adde 3,0,24; li 5,16; bl _s80382E4C_22; mullw 6,3,25; lbz 0,0x0(29); mulhwu 5,4,25; add 6,6,5; addc 8,4,0; extsh 7,28; mullw 5,4,24; stbx 8,27,7; mullw 0,4,25; addc 4,0,23; add 0,6,5; adde 3,0,24; li 5,16; bl _s80382E4C_23; li 0,32767; and 26,4,0; and 30,3,24; addi 29,29,1; addi 28,28,1; 5:; extsh 0,28; cmpwi 0,12; blt 4b; li 3,0; bl _s80382E4C_24; stw 18,0x1c(27); li 18,0; addi 3,27,0; stw 21,0x10(27); addi 5,27,508; addi 6,27,510; stw 20,0xc(27); li 4,508; sth 18,0x20(27); lwz 7,0x18(1); lhz 0,0x8(7); sth 0,0x22(27); bl _s80382E4C_25; b 7f; 6:; lwz 4,0x18(1); extsh 3,18; addi 0,3,1; lwz 3,0x80(4); rlwinm 0,0,13,0,18; li 4,255; add 20,3,0; addi 3,20,0; li 5,8192; bl _s80382E4C_26; addi 4,20,8128; sth 18,0x1ffa(20); addi 3,20,0; addi 5,4,60; addi 6,4,62; li 4,8188; bl _s80382E4C_27; addi 18,18,1; 7:; extsh 0,18; cmpwi 0,2; blt 6b; li 18,0; b 9f; 8:; lwz 4,0x18(1); extsh 3,18; addi 0,3,3; lwz 3,0x80(4); rlwinm 0,0,13,0,18; li 4,0; add 20,3,0; addi 3,20,0; li 5,8192; bl _s80382E4C_28; sth 18,0x4(20); li 0,4; addi 5,20,0; lwz 4,0x18(1); addi 3,20,4; addi 6,20,2; lhz 7,0x10(4); li 4,8188; addi 7,7,-5; sth 7,0x6(20); sth 0,0x8(20); bl _s80382E4C_29; addi 18,18,1; 9:; extsh 0,18; cmpwi 0,2; blt 8b; cmplwi 19,0; beq 10f; mr 0,19; b 11f; 10:; lis 3,-32712; addi 0,3,-4304; 11:; lwz 5,0x18(1); lis 3,1; addi 4,3,-24576; stw 0,0xd0(5); lwz 3,0x18(1); lwz 3,0x80(3); bl _s80382E4C_30; lwz 4,0x18(1); li 0,0; lis 3,-32712; stw 0,0x28(4); addi 5,3,11528; addi 3,22,0; lwz 6,0x18(1); lwz 4,0xc(6); lwz 0,0x28(6); mullw 4,4,0; bl _s80382E4C_31; mr. 18,3; bge 12f; lwz 3,0x18(1); mr 4,18; bl _s80382E4C_32; 12:; mr 3,18; b 14f; 13:; add 29,25,0; b 3b; 14:; lmw 18,0x20(1); lwz 0,0x5c(1); addi 1,1,88; mtspr 8,0"
extern "C" void _s80382E4C_0();
extern "C" void _s80382E4C_1();
extern "C" void _s80382E4C_2();
extern "C" void _s80382E4C_3();
extern "C" void _s80382E4C_4();
extern "C" void _s80382E4C_5();
extern "C" void _s80382E4C_6();
extern "C" void _s80382E4C_7();
extern "C" void _s80382E4C_8();
extern "C" void _s80382E4C_9();
extern "C" void _s80382E4C_10();
extern "C" void _s80382E4C_11();
extern "C" void _s80382E4C_12();
extern "C" void _s80382E4C_13();
extern "C" void _s80382E4C_14();
extern "C" void _s80382E4C_15();
extern "C" void _s80382E4C_16();
extern "C" void _s80382E4C_17();
extern "C" void _s80382E4C_18();
extern "C" void _s80382E4C_19();
extern "C" void _s80382E4C_20();
extern "C" void _s80382E4C_21();
extern "C" void _s80382E4C_22();
extern "C" void _s80382E4C_23();
extern "C" void _s80382E4C_24();
extern "C" void _s80382E4C_25();
extern "C" void _s80382E4C_26();
extern "C" void _s80382E4C_27();
extern "C" void _s80382E4C_28();
extern "C" void _s80382E4C_29();
extern "C" void _s80382E4C_30();
extern "C" void _s80382E4C_31();
extern "C" void _s80382E4C_32();
extern "C" void f_80382E4C() {}
