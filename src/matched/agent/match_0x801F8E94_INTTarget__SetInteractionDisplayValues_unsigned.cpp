// 0x801F8E94 INTTarget::SetInteractionDisplayValues(unsigned (328 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 26,0x40(1); stw 0,0x5c(1); mr 30,4; mr 31,3; mr 26,5; stw 30,0xa0(31); stw 26,0xa8(31); lis 4,-32704; addi 4,4,-30836; addi 3,1,8; mr 5,30; crxor 6,6,6; bl _s801F8E94_0; cmpwi 30,0; beq 0f; addi 28,1,40; addi 29,1,48; addi 30,1,56; mr 3,28; bl _s801F8E94_1; addi 27,31,180; addi 4,1,8; mr 3,28; bl _s801F8E94_2; mr 3,29; bl _s801F8E94_3; lis 4,-32704; mr 3,29; addi 4,4,-22820; bl _s801F8E94_4; mr 5,28; mr 3,30; mr 4,29; bl _s801F8E94_5; mr 4,30; mr 3,27; bl _s801F8E94_6; mr 3,30; li 4,2; bl _s801F8E94_7; mr 3,29; li 4,2; bl _s801F8E94_8; mr 3,28; li 4,2; bl _s801F8E94_9; b 1f; 0:; addi 3,31,180; addi 4,1,8; bl _s801F8E94_10; 1:; lis 4,-32704; mr 5,26; addi 4,4,-30836; addi 3,1,8; crxor 6,6,6; bl _s801F8E94_11; addi 3,31,188; addi 4,1,8; bl _s801F8E94_12; lwz 0,0x9c(31); cmpwi 0,0; beq 2f; lwz 0,0x90(31); cmpwi 0,0; bne 2f; lwz 4,-28528(13); lis 5,-32704; lwz 6,0x98(31); addi 5,5,-22816; addi 3,31,200; bl _s801F8E94_13; li 0,1; stw 0,0x90(31); 2:; li 0,1; stw 0,0x9c(31); lwz 0,0x5c(1); mtspr 8,0; lmw 26,0x40(1); addi 1,1,88"
extern "C" void _s801F8E94_0();
extern "C" void _s801F8E94_1();
extern "C" void _s801F8E94_2();
extern "C" void _s801F8E94_3();
extern "C" void _s801F8E94_4();
extern "C" void _s801F8E94_5();
extern "C" void _s801F8E94_6();
extern "C" void _s801F8E94_7();
extern "C" void _s801F8E94_8();
extern "C" void _s801F8E94_9();
extern "C" void _s801F8E94_10();
extern "C" void _s801F8E94_11();
extern "C" void _s801F8E94_12();
extern "C" void _s801F8E94_13();
extern "C" void f_801F8E94() {}
