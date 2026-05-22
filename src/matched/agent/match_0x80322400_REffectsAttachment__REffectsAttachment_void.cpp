// 0x80322400 REffectsAttachment::REffectsAttachment(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; bl _s80322400_0; lis 9,-32697; li 0,0; addi 9,9,-18496; stw 0,0x14(30); stw 9,0x0(30); addi 11,30,28; stw 0,0x18(30); mr 3,30; stw 0,0x4(11); lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s80322400_0();
extern "C" void f_80322400() {}
