// 0x8003A180 ColorStringForFlash(BString2 (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 28,0x38(1); stw 0,0x4c(1); mr 29,3; mr. 4,4; beq 3f; lis 9,-32707; addi 8,4,-1; lwz 7,0x1a97(9); addi 11,1,32; addi 9,9,6807; rlwinm 0,8,1,0,30; lwz 6,0x8(9); add 0,0,8; lwz 10,0x4(9); lis 4,-32707; stw 7,0x20(1); add 9,11,0; stw 10,0x4(11); addi 4,4,6784; stw 6,0x8(11); addi 3,1,8; addi 28,1,48; li 31,0; lbzx 5,11,0; lbz 7,0x2(9); lbz 6,0x1(9); crxor 6,6,6; bl _s8003A180_0; mr 3,29; bl _s8003A180_1; mr 30,3; cmpw 31,30; bge 2f; 0:; mr 3,29; mr 4,31; bl _s8003A180_2; cmpwi 3,32; bne 1f; mr 3,29; mr 4,31; li 5,1; li 6,95; li 7,1; bl _s8003A180_3; 1:; addi 31,31,1; cmpw 31,30; blt 0b; 2:; mr 3,28; bl _s8003A180_4; addi 4,1,8; mr 3,28; bl _s8003A180_5; mr 4,29; li 5,0; li 6,-1; mr 3,28; bl _s8003A180_6; mr 4,28; mr 3,29; bl _s8003A180_7; mr 3,28; li 4,2; bl _s8003A180_8; 3:; lwz 0,0x4c(1); mtspr 8,0; lmw 28,0x38(1); addi 1,1,72"
extern "C" void _s8003A180_0();
extern "C" void _s8003A180_1();
extern "C" void _s8003A180_2();
extern "C" void _s8003A180_3();
extern "C" void _s8003A180_4();
extern "C" void _s8003A180_5();
extern "C" void _s8003A180_6();
extern "C" void _s8003A180_7();
extern "C" void _s8003A180_8();
extern "C" void f_8003A180() {}
