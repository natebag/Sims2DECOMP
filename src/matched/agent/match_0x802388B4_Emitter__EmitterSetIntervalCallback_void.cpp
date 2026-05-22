// 0x802388B4 Emitter::EmitterSetIntervalCallback(void (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); lwz 0,0x7c(3); mr 12,4; mr 11,5; cmpwi 0,0; beq 0f; li 4,0; li 5,0; li 6,0; li 7,0; li 8,0; li 9,0; li 10,0; stw 12,0x8(1); stw 11,0xc(1); ori 4,4,65535; ori 5,5,65535; ori 6,6,65535; ori 7,7,65535; ori 8,8,65535; ori 9,9,65535; ori 10,10,65535; bl _s802388B4_0; 0:; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s802388B4_0();
extern "C" void f_802388B4() {}
