// 0x80325CE8 EResourceManager::ArchiveFileIsUsingHDD(void) (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; li 4,-1; stw 30,0x8(1); lwz 9,0x0(30); lha 3,0x10(9); lwz 0,0x14(9); add 3,30,3; mtspr 8,0; blrl; lwz 9,0x50(30); cmpwi 9,0; bne 0f; lwz 3,0x8(1); lwz 9,0x0(3); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; li 3,0; b 1f; 0:; lwz 11,0x8(1); lwz 30,0x10(9); lwz 9,0x0(11); subfic 0,30,0; adde 30,0,30; lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; mr 3,30; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void f_80325CE8() {}
