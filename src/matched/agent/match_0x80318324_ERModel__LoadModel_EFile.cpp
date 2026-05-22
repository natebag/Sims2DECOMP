// 0x80318324 ERModel::LoadModel(EFile (832 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 23,0x34(1); stw 0,0x5c(1); mr 29,3; mr. 30,4; beq 8f; addi 3,1,8; bl _s80318324_0; lis 5,19791; addi 3,1,8; mr 4,30; ori 5,5,17484; li 6,57; li 7,58; bl _s80318324_1; cmpwi 3,0; bne 0f; addi 3,1,8; li 4,2; bl _s80318324_2; b 8f; 0:; addi 3,1,8; bl _s80318324_3; lwz 9,0x18(1); mr 3,29; lwz 0,0x10(29); rlwimi 0,9,8,0,23; stw 0,0x10(29); bl _s80318324_4; lwz 31,0x18(1); bl _s80318324_5; mr 4,31; li 5,0; bl _s80318324_6; mr. 27,3; bne 1f; bl _s80318324_7; mr 4,31; li 5,0; bl _s80318324_8; mr 27,3; 1:; lwz 9,0x28(30); mr 4,27; lwz 5,0x18(1); addi 31,27,53; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,30,3; blrl; li 0,0; mr 4,27; stb 0,0x178(29); li 5,4; addi 3,29,320; bl _s80318324_9; addi 4,27,4; li 5,48; addi 3,29,324; bl _s80318324_10; li 5,1; addi 4,27,52; addi 3,29,308; bl _s80318324_11; mr 4,31; mr 3,29; bl _s80318324_12; add 31,31,3; mr 4,31; addi 3,29,260; bl _s80318324_13; add 31,31,3; mr 4,31; addi 3,29,284; bl _s80318324_14; add 31,31,3; mr 4,31; addi 3,29,296; bl _s80318324_15; add 31,31,3; mr 4,31; addi 3,29,144; bl _s80318324_16; add 31,31,3; li 5,1; addi 3,1,32; mr 4,31; crxor 6,6,6; bl _s80318324_17; lbz 0,0x20(1); li 9,1; cmpwi 0,0; bne 2f; li 9,0; 2:; addi 31,31,1; stw 9,0x1c(29); mr 4,31; li 5,4; addi 3,29,136; addi 31,31,4; bl _s80318324_18; addi 30,29,60; mr 4,31; addi 3,1,40; li 5,4; li 28,0; bl _s80318324_19; addi 31,31,4; mr 3,30; li 4,0; li 5,0; addi 26,29,72; bl _s80318324_20; addi 25,29,88; lwz 4,0x28(1); mr 3,30; li 5,0; addi 24,29,112; bl _s80318324_21; addi 23,29,376; lwz 0,0x28(1); cmpw 28,0; bge 4f; li 30,0; 3:; lwz 9,0x3c(29); mr 4,31; addi 28,28,1; add 9,9,30; stw 29,0x14(9); lwz 3,0x3c(29); lwz 5,0xc(1); add 3,3,30; bl _s80318324_22; addi 30,30,24; lwz 0,0x28(1); add 31,31,3; cmpw 28,0; blt 3b; 4:; mr 4,31; li 5,16; mr 3,26; addi 31,31,16; bl _s80318324_23; mr 4,31; li 5,24; mr 3,25; addi 31,31,24; bl _s80318324_24; mr 4,31; li 5,24; mr 3,24; addi 31,31,24; bl _s80318324_25; mr 4,31; li 5,1; mr 3,23; addi 31,31,1; bl _s80318324_26; addi 3,1,32; mr 4,31; li 5,1; crxor 6,6,6; bl _s80318324_27; lbz 0,0x20(1); li 9,1; cmpwi 0,0; bne 5f; li 9,0; 5:; addi 31,31,1; stw 9,0x8c(29); addi 3,1,32; mr 4,31; li 5,1; crxor 6,6,6; bl _s80318324_28; lbz 0,0x20(1); li 9,1; cmpwi 0,0; bne 6f; li 9,0; 6:; stw 9,0x18(29); addi 4,31,1; addi 3,1,32; li 5,1; crxor 6,6,6; bl _s80318324_29; lbz 0,0x20(1); li 9,1; cmpwi 0,0; bne 7f; li 9,0; 7:; stw 9,0x1c(29); bl _s80318324_30; mr 4,27; bl _s80318324_31; lbz 4,0x178(29); mr 3,29; extsb 4,4; bl _s80318324_32; addi 3,1,8; li 4,2; bl _s80318324_33; 8:; lwz 0,0x5c(1); mtspr 8,0; lmw 23,0x34(1); addi 1,1,88"
extern "C" void _s80318324_0();
extern "C" void _s80318324_1();
extern "C" void _s80318324_2();
extern "C" void _s80318324_3();
extern "C" void _s80318324_4();
extern "C" void _s80318324_5();
extern "C" void _s80318324_6();
extern "C" void _s80318324_7();
extern "C" void _s80318324_8();
extern "C" void _s80318324_9();
extern "C" void _s80318324_10();
extern "C" void _s80318324_11();
extern "C" void _s80318324_12();
extern "C" void _s80318324_13();
extern "C" void _s80318324_14();
extern "C" void _s80318324_15();
extern "C" void _s80318324_16();
extern "C" void _s80318324_17();
extern "C" void _s80318324_18();
extern "C" void _s80318324_19();
extern "C" void _s80318324_20();
extern "C" void _s80318324_21();
extern "C" void _s80318324_22();
extern "C" void _s80318324_23();
extern "C" void _s80318324_24();
extern "C" void _s80318324_25();
extern "C" void _s80318324_26();
extern "C" void _s80318324_27();
extern "C" void _s80318324_28();
extern "C" void _s80318324_29();
extern "C" void _s80318324_30();
extern "C" void _s80318324_31();
extern "C" void _s80318324_32();
extern "C" void _s80318324_33();
extern "C" void f_80318324() {}
