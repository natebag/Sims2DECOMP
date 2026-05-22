// 0x8003A104 StripFormatting(BString2 (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 4,60; li 5,0; b 1f; 0:; subf 5,31,3; mr 4,31; addi 5,5,1; mr 3,30; bl _s8003A104_0; mr 5,31; mr 3,30; li 4,60; 1:; bl _s8003A104_1; mr 31,3; cmpwi 31,-1; beq 2f; mr 3,30; li 4,62; addi 5,31,1; bl _s8003A104_2; cmpwi 3,-1; bne 0b; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8003A104_0();
extern "C" void _s8003A104_1();
extern "C" void _s8003A104_2();
extern "C" void f_8003A104() {}
