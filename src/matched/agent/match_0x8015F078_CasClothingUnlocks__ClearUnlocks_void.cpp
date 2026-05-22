// 0x8015F078 CasClothingUnlocks::ClearUnlocks(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; li 0,2; stb 0,0x8(1); li 4,2; li 5,2560; bl _s8015F078_0; lbz 4,0x8(1); li 5,480; addi 3,30,2560; bl _s8015F078_1; mr 3,30; li 4,0; li 5,0; bl _s8015F078_2; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8015F078_0();
extern "C" void _s8015F078_1();
extern "C" void _s8015F078_2();
extern "C" void f_8015F078() {}
