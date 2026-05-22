// 0x8019E124 CASPersonalTarget::SetVariable(char (408 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); mr 30,3; mr 28,5; lwz 3,0x84(30); mr 31,4; bl _s8019E124_0; mr 27,3; mr 3,28; bl _s8019E124_1; extsb 29,3; mr 4,31; lis 3,-32705; addi 3,3,-13300; bl _s8019E124_2; cmpwi 3,0; bne 0f; stb 29,0x8f(30); b 7f; 0:; lis 3,-32705; mr 4,31; addi 3,3,-13284; bl _s8019E124_3; cmpwi 3,0; bne 1f; stb 29,0x8c(30); b 7f; 1:; lis 3,-32705; mr 4,31; addi 3,3,-13264; bl _s8019E124_4; cmpwi 3,0; bne 2f; stb 29,0x90(30); b 7f; 2:; lis 3,-32705; mr 4,31; addi 3,3,-13244; bl _s8019E124_5; cmpwi 3,0; bne 3f; stb 29,0x8e(30); b 7f; 3:; lis 3,-32705; mr 4,31; addi 3,3,-13224; bl _s8019E124_6; cmpwi 3,0; bne 4f; stb 29,0x8d(30); b 7f; 4:; lis 3,-32705; mr 4,31; addi 3,3,-13172; bl _s8019E124_7; cmpwi 3,0; bne 5f; mr 3,30; mr 4,28; bl _s8019E124_8; b 7f; 5:; lis 3,-32705; mr 4,31; addi 3,3,-13192; bl _s8019E124_9; mr 28,3; cmpwi 28,0; bne 6f; addi 3,30,140; bl _s8019E124_10; mr 6,3; lis 5,-32705; addi 5,5,-15596; li 4,3; addi 3,1,8; crxor 6,6,6; bl _s8019E124_11; addi 0,1,8; lis 3,-32705; stb 28,0xa(1); addi 3,3,-12476; stw 0,0x10(1); li 4,0; li 5,0; li 6,1; addi 7,1,16; bl _s8019E124_12; b 7f; 6:; lis 3,-32705; mr 4,31; addi 3,3,-13208; bl _s8019E124_13; cmpwi 3,0; bne 7f; stb 29,0x121(27); 7:; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"
extern "C" void _s8019E124_0();
extern "C" void _s8019E124_1();
extern "C" void _s8019E124_2();
extern "C" void _s8019E124_3();
extern "C" void _s8019E124_4();
extern "C" void _s8019E124_5();
extern "C" void _s8019E124_6();
extern "C" void _s8019E124_7();
extern "C" void _s8019E124_8();
extern "C" void _s8019E124_9();
extern "C" void _s8019E124_10();
extern "C" void _s8019E124_11();
extern "C" void _s8019E124_12();
extern "C" void _s8019E124_13();
extern "C" void f_8019E124() {}
