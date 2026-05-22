// 0x8031BB94 ERQuickdata::getRow(void (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); li 29,0; mr. 30,4; beq 1f; cmpwi 5,0; beq 1f; lwz 6,0x8(30); cmpwi 6,0; beq 1f; lwz 31,0x10(30); cmpwi 31,0; bne 0f; li 31,1; 0:; lwz 4,0xc(30); li 3,0; addi 4,4,-1; bl _s8031BB94_0; mr. 3,3; blt 1f; mullw 9,3,31; lwz 0,0x4(30); add 29,0,9; 1:; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8031BB94_0();
extern "C" void f_8031BB94() {}
