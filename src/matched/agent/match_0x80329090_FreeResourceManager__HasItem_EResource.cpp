// 0x80329090 FreeResourceManager::HasItem(EResource (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; mr 30,4; stw 31,0x8(1); li 4,-1; lwz 9,0x0(31); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,31,3; blrl; lwz 0,0xca0(31); li 11,0; cmpw 11,0; bge 2f; addi 9,31,32; 0:; lwz 0,0x0(9); addi 9,9,4; cmpw 0,30; bne 1f; lwz 3,0x8(1); lwz 9,0x0(3); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; li 3,1; b 3f; 1:; lwz 0,0xca0(31); addi 11,11,1; cmpw 11,0; blt 0b; 2:; lwz 3,0x8(1); lwz 9,0x0(3); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; li 3,0; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void f_80329090() {}
