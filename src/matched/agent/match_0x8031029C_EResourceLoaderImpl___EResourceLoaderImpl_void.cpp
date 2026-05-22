// 0x8031029C EResourceLoaderImpl::~EResourceLoaderImpl(void) (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lis 9,-32697; lis 11,-32697; mr 30,3; addi 9,9,-20528; addi 11,11,-20496; stw 9,0x340(30); stw 11,0x0(30); li 0,0; addi 29,30,1004; stw 0,-22652(13); mr 27,4; mr 3,29; bl _s8031029C_0; addi 28,30,888; mr 3,29; li 4,2; bl _s8031029C_1; addi 3,30,964; li 4,2; bl _s8031029C_2; mr 3,28; li 4,2; bl _s8031029C_3; addi 3,30,860; li 4,2; bl _s8031029C_4; addi 3,30,8; li 4,0; bl _s8031029C_5; mr 3,30; mr 4,27; bl _s8031029C_6; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8031029C_0();
extern "C" void _s8031029C_1();
extern "C" void _s8031029C_2();
extern "C" void _s8031029C_3();
extern "C" void _s8031029C_4();
extern "C" void _s8031029C_5();
extern "C" void _s8031029C_6();
extern "C" void f_8031029C() {}
