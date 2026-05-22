// 0x8032787C FreeMemory(EA::Allocator::GeneralAllocator (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,5; mr 29,4; mr 3,30; bl _s8032787C_0; cmpwi 3,0; beq 2f; rlwinm 0,29,1,0,30; li 31,0; add 29,0,29; 0:; mr 3,30; bl _s8032787C_1; cmpwi 3,0; add 31,31,3; beq 1f; cmplw 31,29; blt 0b; 1:; li 3,1; b 3f; 2:; li 3,0; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8032787C_0();
extern "C" void _s8032787C_1();
extern "C" void f_8032787C() {}
