// 0x8034D89C ENgcScheduler::Init(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; li 4,10; addi 3,31,840; bl _s8034D89C_0; cmpwi 3,0; beq 0f; lis 9,-32702; mr 3,31; addi 9,9,8628; li 4,3; stw 9,0x32c(31); li 5,16384; li 6,0; bl _s8034D89C_1; cmpwi 3,0; li 3,0; beq 1f; mr 3,31; bl _s8034D89C_2; li 3,1; b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8034D89C_0();
extern "C" void _s8034D89C_1();
extern "C" void _s8034D89C_2();
extern "C" void f_8034D89C() {}
