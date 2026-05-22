// 0x803611F8 EStringRedBlackTreeNoCase::FindFirst(char (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,4; mr 28,5; li 5,0; bl _s803611F8_0; mr. 30,3; beq 2f; 0:; lwz 31,0xc(30); cmpwi 31,0; beq 1f; addi 3,31,28; mr 4,29; bl _s803611F8_1; cmpwi 3,0; bne 1f; mr 30,31; b 0b; 1:; cmpwi 28,0; beq 2f; lwz 0,0x18(30); stw 0,0x0(28); 2:; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s803611F8_0();
extern "C" void _s803611F8_1();
extern "C" void f_803611F8() {}
