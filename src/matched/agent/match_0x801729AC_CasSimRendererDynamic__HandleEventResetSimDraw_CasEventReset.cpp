// 0x801729AC CasSimRendererDynamic::HandleEventResetSimDraw(CasEventResetSimDraw (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; addi 29,31,8; mr 3,29; bl _s801729AC_0; lwz 0,0x8(30); cmpwi 0,0; beq 0f; mr 3,31; bl _s801729AC_1; 0:; mr 3,29; bl _s801729AC_2; mr 3,31; bl _s801729AC_3; mr 3,29; bl _s801729AC_4; mr 3,29; bl _s801729AC_5; lis 9,-32702; lis 11,-32702; addi 9,9,17920; addi 11,11,18064; li 7,0; li 6,0; b 2f; 1:; addi 6,10,4; addi 7,7,1; 2:; cmplwi 7,36; bge 4f; mr 10,6; lwz 8,0x218(31); lwzx 0,10,9; cmpw 0,8; beq 3f; lwzx 0,10,11; cmpw 0,8; bne 1b; 3:; lwz 9,0x224(31); lwzx 0,6,9; stw 0,0x218(31); 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801729AC_0();
extern "C" void _s801729AC_1();
extern "C" void _s801729AC_2();
extern "C" void _s801729AC_3();
extern "C" void _s801729AC_4();
extern "C" void _s801729AC_5();
extern "C" void f_801729AC() {}
