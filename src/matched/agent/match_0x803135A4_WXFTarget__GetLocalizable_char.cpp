// 0x803135A4 WXFTarget::GetLocalizable(char (1172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 1,1,16; blr; mr 9,3; li 0,0; stw 0,0x4(9); stw 0,0x0(9); blr; stwu 1,-48(1); mfspr 0,8; stmw 22,0x8(1); stw 0,0x34(1); mr 31,3; mr 23,4; lwz 3,0x0(31); li 29,0; lis 22,-32693; bl _s803135A4_0; mr 27,3; cmpw 29,27; bge 4f; li 24,0; li 25,0; li 26,0; li 28,0; 0:; mr 3,31; mr 4,29; bl _s803135A4_1; cmpwi 3,0; beq 2f; lwz 9,0x4(31); lwzx 30,28,9; cmpwi 30,0; beq 3f; lwz 3,0x0(30); cmpwi 3,0; beq 1f; bl _s803135A4_2; 1:; stw 24,0x4(30); mr 3,30; stw 24,0x8(30); bl _s803135A4_3; b 3f; 2:; lwz 9,0x4(31); addi 3,22,31260; lwzx 4,26,9; bl _s803135A4_4; 3:; lwz 9,0x4(31); addi 29,29,1; addi 26,26,4; addi 28,28,4; stwx 24,25,9; cmpw 29,27; addi 25,25,4; blt 0b; 4:; lis 30,-32693; lwz 4,0x4(31); addi 3,30,31260; li 29,0; bl _s803135A4_5; stw 29,0x4(31); addi 3,30,31260; lwz 4,0x0(31); bl _s803135A4_6; stw 29,0x0(31); andi. 0,23,1; beq 5f; mr 3,31; bl _s803135A4_7; 5:; lwz 0,0x34(1); mtspr 8,0; lmw 22,0x8(1); addi 1,1,48; blr; stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); stw 4,0x8(1); addi 5,1,8; li 4,0; li 6,0; lwz 3,0x0(3); li 7,0; bl _s803135A4_8; mr 31,3; bl _s803135A4_9; cmpwi 3,3; ble 6f; addi 3,3,-4; lis 4,-32702; add 3,31,3; addi 4,4,1520; bl _s803135A4_10; subfic 0,3,0; adde 3,0,3; b 7f; 6:; li 3,0; 7:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24; blr; stwu 1,-72(1); mfspr 0,8; stmw 26,0x30(1); stw 0,0x4c(1); mr 28,4; mr 31,3; lwz 9,0x28(28); lis 29,-32693; lis 26,-32693; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,28,3; blrl; lwz 9,0x28(28); mr 27,3; addi 4,1,8; li 5,24; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,28,3; blrl; addi 3,1,8; bl _s803135A4_11; mr 30,3; li 5,8; mr 4,30; addi 3,29,31260; bl _s803135A4_12; addi 11,1,8; lwz 8,0x8(1); lwz 10,0xc(11); addi 5,30,-24; lwz 0,0x4(11); lwz 9,0x8(11); stw 3,0x0(31); stw 8,0x0(3); stw 10,0xc(3); stw 0,0x4(3); stw 9,0x8(3); lwz 9,0x10(11); lwz 0,0x14(11); stw 9,0x10(3); stw 0,0x14(3); lwz 11,0x28(28); lwz 4,0x0(31); lwz 0,0x1c(11); lha 3,0x18(11); addi 4,4,24; mtspr 8,0; add 3,28,3; blrl; lwz 3,0x0(31); bl _s803135A4_13; mr 30,3; li 5,8; addi 3,29,31260; rlwinm 4,30,2,0,29; bl _s803135A4_14; li 0,0; stw 3,0x4(31); cmpw 0,30; stw 0,0x20(1); bge 11f; 8:; lwz 3,0x0(31); li 4,0; addi 5,1,32; addi 6,1,36; addi 7,1,40; bl _s803135A4_15; cmpwi 3,0; beq 9f; lwz 4,0x28(1); cmpwi 4,-1; beq 9f; li 5,8; addi 3,26,31260; bl _s803135A4_16; lwz 9,0x20(1); li 5,0; lwz 11,0x4(31); rlwinm 9,9,2,0,29; stwx 3,9,11; lwz 10,0x28(28); lwz 4,0x24(1); lwz 0,0x2c(10); lha 3,0x28(10); add 4,27,4; mtspr 8,0; add 3,28,3; blrl; lwz 11,0x28(28); lwz 9,0x20(1); lha 3,0x18(11); lwz 10,0x4(31); rlwinm 9,9,2,0,29; lwz 0,0x1c(11); add 3,28,3; lwzx 4,9,10; lwz 5,0x28(1); mtspr 8,0; blrl; lwz 4,0x20(1); mr 3,31; bl _s803135A4_17; cmpwi 3,0; beq 10f; lwz 4,0x20(1); mr 3,31; bl _s803135A4_18; lwz 9,0x20(1); lwz 11,0x4(31); rlwinm 9,9,2,0,29; stwx 3,9,11; b 10f; 9:; lwz 9,0x20(1); li 0,0; lwz 11,0x4(31); rlwinm 9,9,2,0,29; stwx 0,9,11; 10:; lwz 9,0x20(1); addi 9,9,1; cmpw 9,30; stw 9,0x20(1); blt 8b; 11:; lwz 0,0x4c(1); mtspr 8,0; lmw 26,0x30(1); addi 1,1,72; blr; lwz 3,0x0(3); addi 3,3,24; blr; stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); mr 30,3; addi 5,1,8; lwz 3,0x0(30); addi 6,1,12; addi 7,1,16; bl _s803135A4_19; lwz 9,0x8(1); lwz 11,0x4(30); rlwinm 9,9,2,0,29; lwzx 3,9,11; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); bl _s803135A4_20; mr 30,3; lis 4,-32702; addi 4,4,1528; bl _s803135A4_21; cmpwi 3,0; mr 3,30; beq 12f; li 3,0; 12:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,5; mr 28,6; bl _s803135A4_22; mr 30,3; lwz 3,0x0(30); bl _s803135A4_23; lwz 0,0x4(30); stw 0,0x0(29); lwz 9,0x8(30); stw 9,0x0(28); lwz 3,0x0(30); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s803135A4_0();
extern "C" void _s803135A4_1();
extern "C" void _s803135A4_2();
extern "C" void _s803135A4_3();
extern "C" void _s803135A4_4();
extern "C" void _s803135A4_5();
extern "C" void _s803135A4_6();
extern "C" void _s803135A4_7();
extern "C" void _s803135A4_8();
extern "C" void _s803135A4_9();
extern "C" void _s803135A4_10();
extern "C" void _s803135A4_11();
extern "C" void _s803135A4_12();
extern "C" void _s803135A4_13();
extern "C" void _s803135A4_14();
extern "C" void _s803135A4_15();
extern "C" void _s803135A4_16();
extern "C" void _s803135A4_17();
extern "C" void _s803135A4_18();
extern "C" void _s803135A4_19();
extern "C" void _s803135A4_20();
extern "C" void _s803135A4_21();
extern "C" void _s803135A4_22();
extern "C" void _s803135A4_23();
extern "C" void f_803135A4() {}
