// 0x801F06EC INVTarget::PushPlaceFilter(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; lwz 30,-26524(13); lwz 4,0x84(29); mr 3,30; bl _s801F06EC_0; mr 4,3; mr 3,30; bl _s801F06EC_1; mr 30,3; lis 5,-32704; li 6,100; li 4,0; addi 5,5,-26040; bl _s801F06EC_2; mr 0,3; lis 5,15; mr 4,0; mr 3,30; stw 0,0xd0(29); bl _s801F06EC_3; lwz 4,0xd0(29); mr 3,30; li 5,128; bl _s801F06EC_4; lwz 4,0xd0(29); mr 3,30; li 5,64; bl _s801F06EC_5; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801F06EC_0();
extern "C" void _s801F06EC_1();
extern "C" void _s801F06EC_2();
extern "C" void _s801F06EC_3();
extern "C" void _s801F06EC_4();
extern "C" void _s801F06EC_5();
extern "C" void f_801F06EC() {}
