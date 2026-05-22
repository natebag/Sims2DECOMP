// 0x803101E0 EResourceLoaderImpl::EResourceLoaderImpl(void) (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; li 30,0; addi 29,31,1004; bl _s803101E0_0; addi 3,31,8; bl _s803101E0_1; lis 9,-32697; lis 11,-32697; addi 9,9,-20528; addi 11,11,-20496; stw 30,0x34c(31); addi 3,31,860; stw 30,0x348(31); stw 9,0x340(31); stw 11,0x0(31); bl _s803101E0_2; addi 3,31,888; bl _s803101E0_3; mr 3,29; bl _s803101E0_4; mr 3,29; li 4,1; li 5,0; bl _s803101E0_5; stw 30,0x350(31); li 11,0; li 0,1; addi 9,31,856; 0:; stw 11,0x0(9); addic. 0,0,-1; addi 9,9,-4; bge 0b; li 0,0; mr 3,31; stw 0,0x3e4(31); stw 0,0x3e0(31); stw 0,0x3e8(31); stw 31,-22652(13); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s803101E0_0();
extern "C" void _s803101E0_1();
extern "C" void _s803101E0_2();
extern "C" void _s803101E0_3();
extern "C" void _s803101E0_4();
extern "C" void _s803101E0_5();
extern "C" void f_803101E0() {}
