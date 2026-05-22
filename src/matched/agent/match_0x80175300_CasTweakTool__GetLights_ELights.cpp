// 0x80175300 CasTweakTool::GetLights(ELights (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 9,240; 0:; lwz 0,0x0(3); addic. 9,9,-24; stw 0,0x0(4); lwz 0,0x4(3); stw 0,0x4(4); lwz 0,0x8(3); stw 0,0x8(4); lwz 0,0xc(3); stw 0,0xc(4); lwz 0,0x10(3); stw 0,0x10(4); lwz 0,0x14(3); addi 3,3,24; stw 0,0x14(4); addi 4,4,24; bne 0b; lwz 0,0x0(3); stw 0,0x0(4); lwz 0,0x4(3); stw 0,0x4(4)"
extern "C" void f_80175300() {}
