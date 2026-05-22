// 0x801BBD84 INGTarget::mix_ingredients(void) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; bl _s801BBD84_0; mr. 27,3; beq 0f; addi 4,31,480; mr 3,31; bl _s801BBD84_1; mr 28,3; addi 4,31,488; mr 3,31; bl _s801BBD84_2; mr 29,3; addi 4,31,496; mr 3,31; bl _s801BBD84_3; mr 30,3; mr 3,31; addi 4,3,504; bl _s801BBD84_4; mr 7,3; mr 4,28; mr 3,27; mr 5,29; mr 6,30; bl _s801BBD84_5; b 1f; 0:; li 3,0; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s801BBD84_0();
extern "C" void _s801BBD84_1();
extern "C" void _s801BBD84_2();
extern "C" void _s801BBD84_3();
extern "C" void _s801BBD84_4();
extern "C" void _s801BBD84_5();
extern "C" void f_801BBD84() {}
