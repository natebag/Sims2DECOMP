// 0x8032737C EResourceManager::Detach(EResource (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 0,0x48(31); cmpwi 0,0; beq 0f; li 4,-1; bl _s8032737C_0; lwz 4,0x8(30); addi 3,31,3336; bl _s8032737C_1; mr 3,31; bl _s8032737C_2; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8032737C_0();
extern "C" void _s8032737C_1();
extern "C" void _s8032737C_2();
extern "C" void f_8032737C() {}
