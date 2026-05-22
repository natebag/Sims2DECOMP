// 0x8032949C ImageProcessingManager::SetStageFilter(int, (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mulli 3,3,36; lwz 0,-26588(13); li 9,24; add 3,3,0; 0:; lwz 0,0x0(4); addic. 9,9,-24; stw 0,0x0(3); lwz 0,0x4(4); stw 0,0x4(3); lwz 0,0x8(4); stw 0,0x8(3); lwz 0,0xc(4); stw 0,0xc(3); lwz 0,0x10(4); stw 0,0x10(3); lwz 0,0x14(4); addi 4,4,24; stw 0,0x14(3); addi 3,3,24; bne 0b; lwz 0,0x0(4); stw 0,0x0(3); lwz 0,0x4(4); stw 0,0x4(3); lwz 0,0x8(4); stw 0,0x8(3)"
extern "C" void f_8032949C() {}
