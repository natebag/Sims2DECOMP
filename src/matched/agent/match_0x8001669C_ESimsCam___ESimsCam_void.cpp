// 0x8001669C ESimsCam::~ESimsCam(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lis 9,-32698; lwz 3,0x550(31); addi 9,9,-21016; mr 29,4; stw 9,0x56c(31); cmpwi 3,0; beq 0f; li 4,3; bl _s8001669C_0; 0:; addi 30,31,1224; mr 3,30; bl _s8001669C_1; li 0,0; mr 3,30; stw 0,0x0(31); li 4,2; bl _s8001669C_2; addi 3,31,16; li 4,0; bl _s8001669C_3; andi. 0,29,1; beq 1f; bl _s8001669C_4; mr 4,31; bl _s8001669C_5; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8001669C_0();
extern "C" void _s8001669C_1();
extern "C" void _s8001669C_2();
extern "C" void _s8001669C_3();
extern "C" void _s8001669C_4();
extern "C" void _s8001669C_5();
extern "C" void f_8001669C() {}
