// 0x8002EBB8 ERoom::Init(void) (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); addi 30,1,8; addi 29,1,12; li 0,0; mr 28,3; stw 0,0xc(1); stw 0,0x8(1); li 4,1; mr 5,30; mr 6,29; li 7,1; bl _s8002EBB8_0; li 7,1; mr 3,28; li 4,0; mr 5,30; mr 6,29; bl _s8002EBB8_1; mr 4,30; mr 5,29; mr 3,28; li 6,1; bl _s8002EBB8_2; mr 3,28; bl _s8002EBB8_3; lis 9,-32697; lwz 10,0x8(1); lwz 11,0x5e94(9); mr 3,28; lwz 0,0xc(1); lwz 4,0x24(11); stw 10,-32648(13); stw 0,-32652(13); bl _s8002EBB8_4; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s8002EBB8_0();
extern "C" void _s8002EBB8_1();
extern "C" void _s8002EBB8_2();
extern "C" void _s8002EBB8_3();
extern "C" void _s8002EBB8_4();
extern "C" void f_8002EBB8() {}
