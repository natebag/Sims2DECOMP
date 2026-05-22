// 0x8015F5E0 CasCostumes::CompareSimDescription(CasSimDescriptionS2C (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 30,0x48(1); stw 0,0x54(1); mr 31,4; mr. 3,3; beq 0f; cmpwi 31,0; beq 0f; addi 30,1,40; addi 4,1,8; li 5,32; addi 3,3,4; bl _s8015F5E0_0; mr 4,30; li 5,32; addi 3,31,4; bl _s8015F5E0_1; mr 4,30; addi 3,1,8; bl _s8015F5E0_2; rlwinm 3,3,1,31,31; b 1f; 0:; li 3,1; 1:; lwz 0,0x54(1); mtspr 8,0; lmw 30,0x48(1); addi 1,1,80"
extern "C" void _s8015F5E0_0();
extern "C" void _s8015F5E0_1();
extern "C" void _s8015F5E0_2();
extern "C" void f_8015F5E0() {}
