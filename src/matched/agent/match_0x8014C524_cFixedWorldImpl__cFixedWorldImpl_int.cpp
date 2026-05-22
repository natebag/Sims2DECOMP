// 0x8014C524 cFixedWorldImpl::cFixedWorldImpl(int, (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32698; mr 30,3; addi 9,9,21704; mr 29,4; mr 28,5; stw 9,0x0(30); addi 3,30,4; bl _s8014C524_0; lis 9,-32698; lis 11,-32698; li 0,0; addi 9,9,21352; addi 11,11,21384; mr 4,29; mr 5,28; li 6,0; stw 9,0x10(30); mr 3,30; stw 11,0x0(30); stw 0,0x38(30); stw 0,0x14(30); stw 0,0x18(30); stw 0,0x2c(30); stw 0,0x30(30); stw 0,0x34(30); stw 0,0x3c(30); stw 0,0x40(30); bl _s8014C524_1; bl _s8014C524_2; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8014C524_0();
extern "C" void _s8014C524_1();
extern "C" void _s8014C524_2();
extern "C" void f_8014C524() {}
