// 0x80075CC8 SkinCompositor::CreateSkinQuadrantPrecomposited(ERTexture (292 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 28,0x28(1); stw 0,0x3c(1); mr 30,5; mr 28,6; mr. 29,4; beq 1f; lwz 0,0x14(29); cmpwi 0,0; beq 1f; cmpwi 30,0; beq 1f; lwz 0,0x8(29); cmpw 30,0; li 3,1; beq 3f; lis 3,-32692; mr 4,30; addi 3,3,-7364; li 5,0; li 6,0; bl _s80075CC8_0; mr. 31,3; beq 1f; lwz 0,0x14(31); cmpwi 0,0; beq 1f; li 0,0; addi 9,1,8; stw 0,0x8(1); li 8,64; li 11,1; li 10,32; stb 11,0x18(9); mr 3,9; stw 0,0x1c(9); mr 4,28; stw 0,0x4(9); stw 0,0x8(9); stb 0,0x19(9); stb 0,0x1b(9); sth 0,0x14(9); sth 0,0x16(9); sth 8,0x10(9); stb 10,0x1a(9); sth 8,0x12(9); bl _s80075CC8_1; lwz 11,0x14(31); lhz 9,0x18(1); lhz 0,0x10(11); cmpw 0,9; bne 0f; lhz 9,0x12(11); lhz 0,0x1a(1); cmpw 9,0; beq 2f; 0:; mr 3,31; bl _s80075CC8_2; 1:; li 3,0; b 3f; 2:; lwz 4,0x14(29); mr 3,30; bl _s80075CC8_3; mr 30,3; mr 3,31; bl _s80075CC8_4; mr 3,30; 3:; lwz 0,0x3c(1); mtspr 8,0; lmw 28,0x28(1); addi 1,1,56"
extern "C" void _s80075CC8_0();
extern "C" void _s80075CC8_1();
extern "C" void _s80075CC8_2();
extern "C" void _s80075CC8_3();
extern "C" void _s80075CC8_4();
extern "C" void f_80075CC8() {}
