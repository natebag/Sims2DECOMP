// 0x8031C1F8 LoadXImage(char (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 5,3; li 0,0; addi 30,1,8; mr 29,4; lis 28,-32694; lis 6,-32702; stw 0,0x8(1); addi 6,6,2432; addi 3,28,-10620; mr 4,30; lis 7,-32768; lis 8,-32768; li 9,0; li 31,0; bl _s8031C1F8_0; cmpwi 3,0; beq 0f; lwz 3,0x8(1); mr 4,29; bl _s8031C1F8_1; mr 31,3; mr 4,30; addi 3,28,-10620; bl _s8031C1F8_2; 0:; mr 3,31; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s8031C1F8_0();
extern "C" void _s8031C1F8_1();
extern "C" void _s8031C1F8_2();
extern "C" void f_8031C1F8() {}
