// 0x80090900 LoadingScreenStateMachine::~LoadingScreenStateMachine(void) (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; mr 31,3; addi 9,9,-9664; li 0,0; stw 9,0x18(31); lis 11,-32698; stw 0,-32160(13); addi 11,11,-7936; mr 30,4; addi 3,31,84; stw 11,0x18(31); li 4,2; bl _s80090900_0; lwz 3,0x2c(31); addi 9,31,44; cmpwi 3,0; beq 1f; lwz 0,0xc(9); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 0f; bl _s80090900_1; b 1f; 0:; bl _s80090900_2; 1:; lis 9,-32698; andi. 0,30,1; addi 9,9,-13880; stw 9,0x18(31); beq 2f; mr 3,31; bl _s80090900_3; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80090900_0();
extern "C" void _s80090900_1();
extern "C" void _s80090900_2();
extern "C" void _s80090900_3();
extern "C" void f_80090900() {}
