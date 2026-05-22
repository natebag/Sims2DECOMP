// 0x801C0464 M2MTarget::ReflowButtonSelection(void) (320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 30,3; li 28,0; lwz 0,0x188(30); cmpw 28,0; bge 5f; lis 9,-32700; lis 11,-32700; addi 26,9,-26104; addi 27,11,-26088; 0:; addi 0,28,48; mr 3,30; stb 0,0xd(27); mr 4,28; stb 0,0xc(26); bl _s801C0464_0; lwz 0,0x18c(30); mr 29,3; cmpw 0,28; bne 2f; addi 31,30,288; mr 3,31; bl _s801C0464_1; li 5,0; mr 3,31; mr 4,26; bl _s801C0464_2; mr 3,31; li 4,1; bl _s801C0464_3; mr 4,27; mr 3,31; li 5,0; bl _s801C0464_4; lis 4,-256; cmpwi 29,0; ori 4,4,255; beq 1f; li 4,-1; 1:; mr 3,31; bl _s801C0464_5; mr 3,31; bl _s801C0464_6; b 4f; 2:; addi 31,30,288; mr 3,31; bl _s801C0464_7; li 5,0; mr 3,31; mr 4,26; bl _s801C0464_8; mr 3,31; li 4,0; bl _s801C0464_9; mr 4,27; mr 3,31; li 5,0; bl _s801C0464_10; lis 4,32512; cmpwi 29,0; ori 4,4,255; beq 3f; lis 4,1286; ori 4,4,29183; 3:; mr 3,31; bl _s801C0464_11; mr 3,31; bl _s801C0464_12; 4:; lwz 0,0x188(30); addi 28,28,1; cmpw 28,0; blt 0b; 5:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s801C0464_0();
extern "C" void _s801C0464_1();
extern "C" void _s801C0464_2();
extern "C" void _s801C0464_3();
extern "C" void _s801C0464_4();
extern "C" void _s801C0464_5();
extern "C" void _s801C0464_6();
extern "C" void _s801C0464_7();
extern "C" void _s801C0464_8();
extern "C" void _s801C0464_9();
extern "C" void _s801C0464_10();
extern "C" void _s801C0464_11();
extern "C" void _s801C0464_12();
extern "C" void f_801C0464() {}
