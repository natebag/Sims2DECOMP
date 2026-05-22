// 0x80326D1C EResourceManager::AddRef(char (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; mr 30,5; mr 28,6; mr 3,4; bl _s80326D1C_0; mr 4,3; mr 5,30; mr 3,29; mr 6,28; li 7,1; bl _s80326D1C_1; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80326D1C_0();
extern "C" void _s80326D1C_1();
extern "C" void f_80326D1C() {}
