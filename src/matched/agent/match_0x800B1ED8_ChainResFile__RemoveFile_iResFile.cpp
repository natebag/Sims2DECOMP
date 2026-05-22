// 0x800B1ED8 ChainResFile::RemoveFile(iResFile (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; mfcr 12; stmw 22,0x10(1); stw 0,0x3c(1); stw 12,0xc(1); mr 27,3; mr 23,4; addi 24,27,16; li 22,0; 0:; li 25,0; li 28,0; addi 29,27,44; addi 30,27,40; li 26,0; 1:; addi 9,27,16; mulli 11,28,24; cmpwi 4,25,0; cmpwi 7,28,6; bne cr4,3f; lwzx 0,9,26; cmpw 0,23; bne 2f; stwx 25,9,26; li 25,1; 2:; cmpwi 4,25,0; beq cr4,5f; 3:; add 31,11,27; mr 4,29; bgt cr7,4f; lwz 0,0x0(30); stwu 0,0x10(31); addi 3,31,4; bl _s800B1ED8_0; lwz 0,0x14(30); stw 0,0x14(31); b 5f; 4:; stwx 22,24,11; 5:; addi 28,28,1; addi 29,29,24; addi 30,30,24; addi 26,26,24; cmpwi 28,7; ble 1b; bne cr4,0b; lwz 0,0x3c(1); lwz 12,0xc(1); mtspr 8,0; lmw 22,0x10(1); mtcrf 8,12; addi 1,1,56"
extern "C" void _s800B1ED8_0();
extern "C" void f_800B1ED8() {}
