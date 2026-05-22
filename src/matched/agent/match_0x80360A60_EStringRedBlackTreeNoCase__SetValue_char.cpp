// 0x80360A60 EStringRedBlackTreeNoCase::SetValue(char (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; mr 30,4; mr 28,5; bl _s80360A60_0; mr. 31,3; beq 0f; addi 3,31,28; mr 4,30; bl _s80360A60_1; cmpwi 3,0; bne 0f; stw 28,0x18(31); mr 3,31; b 1f; 0:; mr 3,29; mr 4,31; mr 5,30; mr 6,28; bl _s80360A60_2; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80360A60_0();
extern "C" void _s80360A60_1();
extern "C" void _s80360A60_2();
extern "C" void f_80360A60() {}
