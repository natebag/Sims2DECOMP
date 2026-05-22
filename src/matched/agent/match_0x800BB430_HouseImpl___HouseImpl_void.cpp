// 0x800BB430 HouseImpl::~HouseImpl(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; lis 11,-32698; mr 31,3; addi 9,9,-3440; addi 11,11,-3408; stw 9,0x10(31); mr 30,4; stw 11,0x0(31); bl _s800BB430_0; addi 3,31,24; li 4,2; bl _s800BB430_1; addi 3,31,4; li 4,0; bl _s800BB430_2; lis 9,-32698; andi. 0,30,1; addi 9,9,-3248; stw 9,0x0(31); beq 0f; mr 3,31; bl _s800BB430_3; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800BB430_0();
extern "C" void _s800BB430_1();
extern "C" void _s800BB430_2();
extern "C" void _s800BB430_3();
extern "C" void f_800BB430() {}
