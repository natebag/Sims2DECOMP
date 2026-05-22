// 0x800B4214 Commander::Commander(void) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 8,-32076(13); lis 9,-32698; mr 11,3; addi 9,9,-5144; li 0,0; stw 9,0xc(11); stw 0,0x4(11); addi 10,13,-32072; stw 8,0x0(11); lwz 9,0x0(10); stw 9,0x8(11); addi 9,9,1; stw 11,-32076(13); stw 9,0x0(10)"
extern "C" void f_800B4214() {}
