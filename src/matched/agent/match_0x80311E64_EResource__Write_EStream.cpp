// 0x80311E64 EResource::Write(EStream (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 29,4; addi 30,1,8; lis 4,-32702; mr 3,30; addi 4,4,1176; bl _s80311E64_0; mr 4,30; mr 3,29; bl _s80311E64_1; lwz 4,0x8(1); mr 3,30; bl _s80311E64_2; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s80311E64_0();
extern "C" void _s80311E64_1();
extern "C" void _s80311E64_2();
extern "C" void f_80311E64() {}
