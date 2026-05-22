// 0x80119530 cSoundCache::Shutdown(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; li 28,0; li 31,0; li 29,64; 0:; lwzx 11,31,30; li 4,3; cmpwi 11,0; beq 1f; lwz 9,0x94(11); lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; stwx 28,31,30; 1:; addi 31,31,4; addic. 29,29,-1; bne 0b; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void f_80119530() {}
