// 0x8032708C EResourceManager::DelRef(char (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 30,5; mr 3,4; bl _s8032708C_0; mr 4,3; mr 5,30; mr 3,29; bl _s8032708C_1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8032708C_0();
extern "C" void _s8032708C_1();
extern "C" void f_8032708C() {}
