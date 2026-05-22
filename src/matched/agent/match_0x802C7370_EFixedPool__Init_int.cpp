// 0x802C7370 EFixedPool::Init(int, (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,5; mr 28,3; mr 30,4; bl _s802C7370_0; mullw 4,30,29; li 5,32; li 6,0; li 7,0; bl _s802C7370_1; mr 0,3; mr 4,30; mr 3,28; mr 5,29; mr 6,0; stw 0,0x4(28); bl _s802C7370_2; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802C7370_0();
extern "C" void _s802C7370_1();
extern "C" void _s802C7370_2();
extern "C" void f_802C7370() {}
