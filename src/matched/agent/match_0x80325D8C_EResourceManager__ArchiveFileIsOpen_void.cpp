// 0x80325D8C EResourceManager::ArchiveFileIsOpen(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; li 4,-1; stw 30,0x8(1); li 31,1; lwz 9,0x0(30); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,30,3; blrl; lwz 0,0x50(30); cmpwi 0,0; bne 0f; li 31,0; 0:; lwz 3,0x8(1); lwz 9,0x0(3); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void f_80325D8C() {}
