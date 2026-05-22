// 0x803522E4 Effects::EffectsManager::EffectsManager(void) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; li 0,0; stw 0,0x0(9); addi 11,9,4; stw 0,0x4(11); li 8,1; stw 0,0x4(9); addi 10,9,16; stw 8,0x8(11); stw 0,0x4(10); stw 0,0x10(9); stw 8,0x8(10)"
extern "C" void f_803522E4() {}
