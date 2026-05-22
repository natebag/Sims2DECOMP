// 0x8020AE38 InteractorModule::InteractorInputManager::~InteractorInputManager(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; lwz 9,0x0(30); cmpwi 9,0; beq 2f; lwz 0,-8(9); rlwinm 0,0,5,0,26; add 31,9,0; cmpw 9,31; beq 1f; 0:; addi 31,31,-32; li 4,0; mr 3,31; bl _s8020AE38_0; lwz 0,0x0(30); cmpw 0,31; bne 0b; 1:; lwz 3,0x0(30); addi 3,3,-8; bl _s8020AE38_1; 2:; li 0,0; andi. 9,29,1; stw 0,0x0(30); beq 3f; mr 3,30; bl _s8020AE38_2; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8020AE38_0();
extern "C" void _s8020AE38_1();
extern "C" void _s8020AE38_2();
extern "C" void f_8020AE38() {}
