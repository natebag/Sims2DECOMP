// 0x80299074 AptPseudoDisplayList::ClearList(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 9,0x0(3); lwz 31,0x8(9); cmpwi 31,0; beq 3f; 0:; lwz 29,0x8(31); cmpwi 31,0; beq 2f; lwz 9,0x4(31); li 30,0; stw 30,0x0(31); stw 30,0x8(31); cmpwi 9,0; stw 30,0xc(31); beq 1f; mr 3,9; stw 30,0x0(9); stw 30,0x4(9); li 4,28; stw 30,0x8(9); bl _s80299074_0; stw 30,0x4(31); 1:; mr 3,31; li 4,20; bl _s80299074_1; 2:; mr. 31,29; bne 0b; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80299074_0();
extern "C" void _s80299074_1();
extern "C" void f_80299074() {}
