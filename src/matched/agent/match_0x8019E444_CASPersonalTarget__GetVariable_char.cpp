// 0x8019E444 CASPersonalTarget::GetVariable(char (440 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); mr 30,3; mr 31,4; li 3,32; bl _s8019E444_0; li 0,0; mr 29,3; stb 0,0x0(29); lwz 3,0x84(30); bl _s8019E444_1; mr 30,3; mr 4,31; lis 3,-32705; addi 3,3,-13300; bl _s8019E444_2; cmpwi 3,0; bne 0f; lbz 6,0x11f(30); b 4f; 0:; lis 3,-32705; mr 4,31; addi 3,3,-13284; bl _s8019E444_3; cmpwi 3,0; bne 1f; lbz 6,0x11c(30); b 4f; 1:; lis 3,-32705; mr 4,31; addi 3,3,-13264; bl _s8019E444_4; cmpwi 3,0; bne 2f; lbz 6,0x120(30); b 4f; 2:; lis 3,-32705; mr 4,31; addi 3,3,-13244; bl _s8019E444_5; cmpwi 3,0; bne 3f; lbz 6,0x11e(30); b 4f; 3:; lis 3,-32705; mr 4,31; addi 3,3,-13224; bl _s8019E444_6; cmpwi 3,0; bne 5f; lbz 6,0x11d(30); 4:; lis 5,-32705; addi 5,5,-15596; mr 3,29; extsb 6,6; li 4,32; crxor 6,6,6; bl _s8019E444_7; b 7f; 5:; lis 3,-32705; mr 4,31; addi 3,3,-13192; bl _s8019E444_8; mr 28,3; cmpwi 28,0; bne 6f; addi 3,30,284; bl _s8019E444_9; mr 6,3; lis 5,-32705; addi 5,5,-15596; li 4,3; addi 3,1,8; crxor 6,6,6; bl _s8019E444_10; addi 0,1,8; lis 3,-32705; stb 28,0xa(1); addi 3,3,-12476; stw 0,0x10(1); li 4,0; li 5,0; li 6,1; addi 7,1,16; bl _s8019E444_11; b 7f; 6:; lis 3,-32705; mr 4,31; addi 3,3,-13208; bl _s8019E444_12; cmpwi 3,0; bne 7f; lbz 6,0x121(30); lis 5,-32705; addi 5,5,-15596; mr 3,29; extsb 6,6; li 4,32; crxor 6,6,6; bl _s8019E444_13; 7:; li 0,0; mr 3,29; stb 0,0x1f(29); lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s8019E444_0();
extern "C" void _s8019E444_1();
extern "C" void _s8019E444_2();
extern "C" void _s8019E444_3();
extern "C" void _s8019E444_4();
extern "C" void _s8019E444_5();
extern "C" void _s8019E444_6();
extern "C" void _s8019E444_7();
extern "C" void _s8019E444_8();
extern "C" void _s8019E444_9();
extern "C" void _s8019E444_10();
extern "C" void _s8019E444_11();
extern "C" void _s8019E444_12();
extern "C" void _s8019E444_13();
extern "C" void f_8019E444() {}
