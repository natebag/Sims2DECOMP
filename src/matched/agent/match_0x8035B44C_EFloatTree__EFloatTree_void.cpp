// 0x8035B44C EFloatTree::EFloatTree(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32700; mr 11,3; li 0,0; addi 9,9,11784; stw 0,0x0(11); stw 9,0x8(11); stw 0,0x4(11)"
extern "C" void f_8035B44C() {}
