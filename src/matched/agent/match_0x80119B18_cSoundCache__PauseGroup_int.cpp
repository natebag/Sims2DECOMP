// 0x80119B18 cSoundCache::PauseGroup(int) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; mfcr 12; stmw 28,0x10(1); stw 0,0x24(1); stw 12,0xc(1); mr 28,4; mr 30,3; cmpwi 4,28,-1; li 31,0; li 29,64; 0:; lwzx 3,31,30; cmpwi 3,0; beq 2f; beq cr4,1f; lwz 0,0x0(3); cmpwi 0,0; beq 2f; bl _s80119B18_0; cmpw 3,28; bne 2f; 1:; lwzx 3,31,30; bl _s80119B18_1; 2:; addi 31,31,4; addic. 29,29,-1; bne 0b; lwz 0,0x24(1); lwz 12,0xc(1); mtspr 8,0; lmw 28,0x10(1); mtcrf 8,12; addi 1,1,32"
extern "C" void _s80119B18_0();
extern "C" void _s80119B18_1();
extern "C" void f_80119B18() {}
