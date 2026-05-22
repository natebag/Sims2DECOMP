// 0x800D4960 NghResFile::DecompressSection(NghResFileSectionHeader (604 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; mfcr 12; stmw 29,0x14(1); stw 0,0x24(1); stw 12,0x10(1); mr 31,4; mr 29,3; lwz 9,0x4(31); cmpwi 4,5,0; lwz 0,0xc(31); stw 9,0x8(1); stw 0,0xc(1); bne cr4,0f; addi 4,1,8; bl _s800D4960_0; mr 3,29; addi 4,1,12; bl _s800D4960_1; mr 3,29; addi 4,31,16; bl _s800D4960_2; 0:; lwz 0,0xc(1); li 9,0; lwz 4,0x8(1); mr 3,31; lwz 30,0x10(31); add 4,0,4; stw 9,0x10(31); bl _s800D4960_3; cmpw 30,3; stw 30,0x10(31); li 0,-4; bne 1f; li 0,1; 1:; cmpwi 0,1; beq 3f; 2:; li 3,0; b 9f; 3:; bne cr4,4f; mr 3,29; mr 4,31; bl _s800D4960_4; mr 3,29; addi 4,31,4; bl _s800D4960_5; mr 3,29; addi 4,31,8; bl _s800D4960_6; mr 3,29; addi 4,31,12; bl _s800D4960_7; mr 3,29; addi 4,31,20; bl _s800D4960_8; mr 3,29; addi 4,31,24; bl _s800D4960_9; 4:; bl _s800D4960_10; lwz 0,0x4(31); li 5,64; lwz 4,0x8(31); li 6,0; li 7,0; add 4,0,4; bl _s800D4960_11; mr 29,3; lwz 5,0x4(31); mr 4,31; crxor 6,6,6; bl _s800D4960_12; lwz 0,0x14(31); cmplwi 0,8; bgt 2b; cmplwi 0,7; blt 2b; lwz 0,0x0(31); cmpwi 0,2; bne 6f; lwz 3,0x4(31); lwz 4,0xc(31); add 5,29,3; lwz 6,0x8(31); add 3,31,3; bl _s800D4960_13; lwz 0,0x8(31); cmpw 3,0; bne 7f; bne cr4,8f; cmpwi 3,0; beq 8f; bl _s800D4960_14; lwz 0,0x4(29); li 5,64; lwz 4,0x8(29); li 6,0; li 7,0; add 4,0,4; bl _s800D4960_15; mr. 31,3; beq 8f; lwz 0,0x4(29); mr 4,29; lwz 5,0x8(29); mr 3,31; add 5,0,5; crxor 6,6,6; bl _s800D4960_16; lwz 3,0x4(31); li 4,32; lwz 30,0x4(29); li 5,32; add 3,31,3; add 30,29,30; addi 3,3,12; addi 6,30,12; bl _s800D4960_17; li 0,256; addi 30,30,1036; mtspr 9,0; 5:; lbz 0,0x0(30); lbz 9,0x2(30); stb 0,0x2(30); stb 9,0x0(30); addi 30,30,4; bdnz 5b; bl _s800D4960_18; mr 4,31; bl _s800D4960_19; b 8f; 6:; lwz 3,0x4(31); lwz 4,0xc(31); add 5,29,3; lwz 6,0x8(31); add 3,31,3; bl _s800D4960_20; lwz 0,0x8(31); cmpw 3,0; beq 8f; 7:; bl _s800D4960_21; mr 4,29; bl _s800D4960_22; b 2b; 8:; mr 3,29; 9:; lwz 0,0x24(1); lwz 12,0x10(1); mtspr 8,0; lmw 29,0x14(1); mtcrf 8,12; addi 1,1,32"
extern "C" void _s800D4960_0();
extern "C" void _s800D4960_1();
extern "C" void _s800D4960_2();
extern "C" void _s800D4960_3();
extern "C" void _s800D4960_4();
extern "C" void _s800D4960_5();
extern "C" void _s800D4960_6();
extern "C" void _s800D4960_7();
extern "C" void _s800D4960_8();
extern "C" void _s800D4960_9();
extern "C" void _s800D4960_10();
extern "C" void _s800D4960_11();
extern "C" void _s800D4960_12();
extern "C" void _s800D4960_13();
extern "C" void _s800D4960_14();
extern "C" void _s800D4960_15();
extern "C" void _s800D4960_16();
extern "C" void _s800D4960_17();
extern "C" void _s800D4960_18();
extern "C" void _s800D4960_19();
extern "C" void _s800D4960_20();
extern "C" void _s800D4960_21();
extern "C" void _s800D4960_22();
extern "C" void f_800D4960() {}
