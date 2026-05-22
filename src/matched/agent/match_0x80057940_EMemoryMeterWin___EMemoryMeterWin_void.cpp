// 0x80057940 EMemoryMeterWin::~EMemoryMeterWin(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; mr 31,3; addi 9,9,-14032; mr 30,4; stw 9,0x4(31); bl _s80057940_0; lis 9,-32698; andi. 0,30,1; addi 9,9,-13992; stw 9,0x4(31); beq 0f; mr 3,31; bl _s80057940_1; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80057940_0();
extern "C" void _s80057940_1();
extern "C" void f_80057940() {}
