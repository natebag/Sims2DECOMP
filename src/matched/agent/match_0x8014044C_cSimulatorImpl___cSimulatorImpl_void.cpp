// 0x8014044C cSimulatorImpl::~cSimulatorImpl(void) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lis 11,-32698; lwz 3,0x174(31); lis 9,-32698; addi 11,11,17976; addi 9,9,18008; mr 30,4; stw 11,0x10(31); stw 9,0x0(31); cmpwi 3,0; beq 0f; li 4,3; bl _s8014044C_0; 0:; addi 3,31,4; li 4,0; bl _s8014044C_1; lis 9,-32698; andi. 0,30,1; addi 9,9,18432; stw 9,0x0(31); beq 1f; mr 3,31; bl _s8014044C_2; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8014044C_0();
extern "C" void _s8014044C_1();
extern "C" void _s8014044C_2();
extern "C" void f_8014044C() {}
