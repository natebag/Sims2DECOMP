// 0x801F0780 INVTarget::PushGrabFilter(void) (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 30,-26524(13); lwz 4,0x84(31); mr 3,30; bl _s801F0780_0; mr 4,3; mr 3,30; bl _s801F0780_1; mr 30,3; lis 5,-32704; li 6,100; li 4,0; addi 5,5,-26040; bl _s801F0780_2; mr 0,3; lis 5,15; mr 4,0; stw 0,0xd0(31); mr 3,30; bl _s801F0780_3; lwz 4,0xd0(31); mr 3,30; li 5,128; bl _s801F0780_4; lwz 4,0xd0(31); mr 3,30; li 5,64; bl _s801F0780_5; lwz 9,-21432(13); lwz 0,0x3dc(9); cmpwi 0,0; bne 0f; lwz 4,0xd0(31); mr 3,30; li 5,4096; bl _s801F0780_6; lwz 4,0xd0(31); mr 3,30; li 5,8192; bl _s801F0780_7; lwz 4,0xd0(31); mr 3,30; li 5,16384; bl _s801F0780_8; li 5,0; lwz 4,0xd0(31); mr 3,30; ori 5,5,32768; bl _s801F0780_9; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801F0780_0();
extern "C" void _s801F0780_1();
extern "C" void _s801F0780_2();
extern "C" void _s801F0780_3();
extern "C" void _s801F0780_4();
extern "C" void _s801F0780_5();
extern "C" void _s801F0780_6();
extern "C" void _s801F0780_7();
extern "C" void _s801F0780_8();
extern "C" void _s801F0780_9();
extern "C" void f_801F0780() {}
