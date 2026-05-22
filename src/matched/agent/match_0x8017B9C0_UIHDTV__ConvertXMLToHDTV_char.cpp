// 0x8017B9C0 UIHDTV::ConvertXMLToHDTV(char (756 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-368(1); mfspr 0,8; stmw 18,0x138(1); stw 0,0x174(1); mr 28,3; lwz 24,0x0(4); addi 3,1,8; li 25,0; bl _s8017B9C0_0; addi 29,1,8; mr 3,24; bl _s8017B9C0_1; mr 20,3; addi 3,1,8; mr 4,20; bl _s8017B9C0_2; cmplw 25,20; bge 16f; li 18,0; mr 19,29; addi 21,1,24; 0:; lbzx 4,24,25; mr 3,28; extsb 4,4; bl _s8017B9C0_3; cmpwi 3,0; beq 12f; mr 4,24; mr 5,25; mr 3,28; bl _s8017B9C0_4; mr 31,3; addi 6,1,288; mr 4,24; mr 5,25; stw 18,0x120(1); mr 3,28; bl _s8017B9C0_5; mr 30,3; mr 4,24; mr 3,28; mr 5,25; bl _s8017B9C0_6; cmpwi 3,0; beq 2f; lwz 4,0x4(19); neg 30,30; addi 3,4,-1; subf. 5,3,4; beq 1f; bl _s8017B9C0_7; 1:; lwz 9,0x4(29); addi 9,9,-1; stw 9,0x4(29); 2:; cmpwi 31,0; bne 3f; mr 4,30; mr 3,28; bl _s8017B9C0_8; b 7f; 3:; cmpwi 31,1; bne 4f; mr 4,30; mr 3,28; bl _s8017B9C0_9; b 7f; 4:; cmpwi 31,2; bne 5f; mr 4,30; mr 3,28; bl _s8017B9C0_10; b 7f; 5:; cmpwi 31,3; bne 6f; mr 4,30; mr 3,28; bl _s8017B9C0_11; b 7f; 6:; mr 3,30; 7:; mr 5,3; lis 4,-32706; addi 4,4,12788; mr 3,21; crxor 6,6,6; bl _s8017B9C0_12; li 30,0; mr 3,21; mr 22,21; bl _s8017B9C0_13; mr 27,3; cmpw 30,27; bge 11f; mr 31,29; li 26,1; li 23,0; 8:; lbzx 0,22,30; stb 0,0x118(1); lwz 4,0x4(31); lwz 9,0xc(31); addi 0,4,1; cmpw 0,9; bne 10f; lwz 0,0x8(1); addi 11,1,296; stw 26,0x128(1); addi 9,1,292; subf 0,0,4; stw 0,0x124(1); cmplw 0,26; bge 9f; mr 9,11; 9:; lwz 4,0x0(9); mr 3,29; add 4,0,4; bl _s8017B9C0_14; 10:; lwz 9,0x4(29); addi 30,30,1; cmpw 30,27; stb 23,0x1(9); lwz 11,0x4(29); lbz 0,0x118(1); stb 0,0x0(11); lwz 9,0x4(29); addi 9,9,1; stw 9,0x4(29); blt 8b; 11:; lwz 0,0x120(1); add 25,25,0; b 15f; 12:; lwz 4,0x4(19); lwz 11,0xc(19); lbzx 0,24,25; addi 9,4,1; cmpw 9,11; stb 0,0x18(1); bne 14f; lwz 9,0x8(1); li 0,1; stw 0,0x130(1); subf 9,9,4; addi 0,1,304; addi 4,1,300; stw 9,0x12c(1); cmplwi 9,1; bge 13f; mr 4,0; 13:; lwz 4,0x0(4); mr 3,29; add 4,9,4; bl _s8017B9C0_15; 14:; lwz 9,0x4(29); addi 25,25,1; stb 18,0x1(9); lwz 11,0x4(29); lbz 0,0x18(1); stb 0,0x0(11); lwz 9,0x4(29); addi 9,9,1; stw 9,0x4(29); 15:; cmplw 25,20; blt 0b; 16:; lwz 0,0x8(1); lwz 30,0x4(29); subf 30,0,30; bl _s8017B9C0_16; addi 4,30,1; li 5,0; bl _s8017B9C0_17; mr 31,3; lwz 4,0x8(1); bl _s8017B9C0_18; li 0,0; stbx 0,31,30; lwz 3,0x8(1); lwz 0,0xc(29); cmpwi 3,0; subf 4,3,0; beq 18f; cmplwi 4,128; ble 17f; bl _s8017B9C0_19; b 18f; 17:; bl _s8017B9C0_20; 18:; mr 3,31; lwz 0,0x174(1); mtspr 8,0; lmw 18,0x138(1); addi 1,1,368"
extern "C" void _s8017B9C0_0();
extern "C" void _s8017B9C0_1();
extern "C" void _s8017B9C0_2();
extern "C" void _s8017B9C0_3();
extern "C" void _s8017B9C0_4();
extern "C" void _s8017B9C0_5();
extern "C" void _s8017B9C0_6();
extern "C" void _s8017B9C0_7();
extern "C" void _s8017B9C0_8();
extern "C" void _s8017B9C0_9();
extern "C" void _s8017B9C0_10();
extern "C" void _s8017B9C0_11();
extern "C" void _s8017B9C0_12();
extern "C" void _s8017B9C0_13();
extern "C" void _s8017B9C0_14();
extern "C" void _s8017B9C0_15();
extern "C" void _s8017B9C0_16();
extern "C" void _s8017B9C0_17();
extern "C" void _s8017B9C0_18();
extern "C" void _s8017B9C0_19();
extern "C" void _s8017B9C0_20();
extern "C" void f_8017B9C0() {}
