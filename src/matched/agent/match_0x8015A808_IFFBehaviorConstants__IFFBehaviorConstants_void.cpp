// 0x8015A808 IFFBehaviorConstants::IFFBehaviorConstants(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; addi 28,29,24; bl _s8015A808_0; lis 9,-32698; lis 30,-32706; addi 9,9,22096; addi 30,30,-8416; stw 9,0x0(29); addi 4,29,32; li 5,64; mr 3,28; bl _s8015A808_1; mr 3,28; mr 4,30; li 5,-1; bl _s8015A808_2; li 0,0; mr 3,29; stw 0,0x60(29); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8015A808_0();
extern "C" void _s8015A808_1();
extern "C" void _s8015A808_2();
extern "C" void f_8015A808() {}
