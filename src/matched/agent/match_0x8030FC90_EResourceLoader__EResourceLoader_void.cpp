// 0x8030FC90 EResourceLoader::EResourceLoader(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32697; mr 11,3; addi 9,9,-20200; stw 9,0x0(11)"
extern "C" void f_8030FC90() {}
