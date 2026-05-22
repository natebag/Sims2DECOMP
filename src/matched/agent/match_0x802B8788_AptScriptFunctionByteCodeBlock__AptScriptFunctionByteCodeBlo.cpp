// 0x802B8788 AptScriptFunctionByteCodeBlock::AptScriptFunctionByteCodeBlock(unsigned (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 30,3; lwz 28,0x0(6); lwz 29,0x4(6); mr 27,4; mr 26,5; mr 25,7; mr 5,9; mr 6,8; li 4,45; li 7,0; bl _s802B8788_0; lis 9,-32703; stw 27,0x34(30); addi 9,9,27368; stw 26,0x38(30); stw 9,0x8(30); mr 3,30; stw 25,0x3c(30); stw 28,0x40(30); stw 29,0x44(30); lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s802B8788_0();
extern "C" void f_802B8788() {}
