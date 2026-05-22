// 0x801F8FDC INTTarget::TriggerInteractionAnimation(unsigned (376 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 24,0x40(1); stw 0,0x64(1); mr 26,4; mr 31,3; mr 25,5; mr 24,6; add 0,26,25; stw 26,0xa0(31); stw 25,0xa4(31); lis 4,-32704; stw 24,0xb0(31); addi 4,4,-30836; stw 0,0xac(31); addi 3,1,8; mr 5,26; crxor 6,6,6; bl _s801F8FDC_0; cmpwi 26,0; beq 0f; addi 28,1,40; addi 29,1,48; addi 30,1,56; mr 3,28; bl _s801F8FDC_1; addi 27,31,180; addi 4,1,8; mr 3,28; bl _s801F8FDC_2; mr 3,29; bl _s801F8FDC_3; lis 4,-32704; mr 3,29; addi 4,4,-22820; bl _s801F8FDC_4; mr 5,28; mr 3,30; mr 4,29; bl _s801F8FDC_5; mr 4,30; mr 3,27; bl _s801F8FDC_6; mr 3,30; li 4,2; bl _s801F8FDC_7; mr 3,29; li 4,2; bl _s801F8FDC_8; mr 3,28; li 4,2; bl _s801F8FDC_9; b 1f; 0:; addi 3,31,180; addi 4,1,8; bl _s801F8FDC_10; 1:; lis 30,-32704; addi 3,1,8; mr 5,25; addi 4,30,-30836; crxor 6,6,6; bl _s801F8FDC_11; addi 4,1,8; addi 3,31,184; bl _s801F8FDC_12; addi 3,1,8; mr 5,24; addi 4,30,-30836; crxor 6,6,6; bl _s801F8FDC_13; addi 4,1,8; addi 3,31,196; bl _s801F8FDC_14; add 5,26,25; addi 3,1,8; addi 4,30,-30836; crxor 6,6,6; bl _s801F8FDC_15; addi 4,1,8; addi 3,31,192; bl _s801F8FDC_16; lwz 4,-28528(13); lis 5,-32704; lwz 6,0x98(31); addi 5,5,-22812; addi 3,31,200; bl _s801F8FDC_17; li 0,1; stw 0,0x90(31); lwz 0,0x64(1); mtspr 8,0; lmw 24,0x40(1); addi 1,1,96"
extern "C" void _s801F8FDC_0();
extern "C" void _s801F8FDC_1();
extern "C" void _s801F8FDC_2();
extern "C" void _s801F8FDC_3();
extern "C" void _s801F8FDC_4();
extern "C" void _s801F8FDC_5();
extern "C" void _s801F8FDC_6();
extern "C" void _s801F8FDC_7();
extern "C" void _s801F8FDC_8();
extern "C" void _s801F8FDC_9();
extern "C" void _s801F8FDC_10();
extern "C" void _s801F8FDC_11();
extern "C" void _s801F8FDC_12();
extern "C" void _s801F8FDC_13();
extern "C" void _s801F8FDC_14();
extern "C" void _s801F8FDC_15();
extern "C" void _s801F8FDC_16();
extern "C" void _s801F8FDC_17();
extern "C" void f_801F8FDC() {}
