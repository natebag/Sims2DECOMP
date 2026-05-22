// 0x80364D24 EMovie::EMovie(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32697; mr 11,3; addi 9,9,-9664; stw 9,0x8(11)"
extern "C" void f_80364D24() {}
