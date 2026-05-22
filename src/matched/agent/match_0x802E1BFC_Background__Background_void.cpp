// 0x802E1BFC Background::Background(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32697; mr 11,3; addi 9,9,-23088; stw 9,0x0(11)"
extern "C" void f_802E1BFC() {}
