// 0x803265C4 EResourceManager::DelRefAll(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; lwz 9,0x4c(30); cmpwi 9,0; beq 1f; lwz 0,0x0(9); li 31,0; cmplw 31,0; bge 1f; li 29,0; 0:; add 9,29,9; mr 3,30; lwz 4,0x4(9); li 5,1; addi 31,31,1; addi 29,29,4; bl _s803265C4_0; lwz 9,0x4c(30); lwz 0,0x0(9); cmplw 31,0; blt 0b; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s803265C4_0();
extern "C" void f_803265C4() {}
