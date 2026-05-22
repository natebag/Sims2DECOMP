// 0x8032488C __static_initialization_and_destruction_0 (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 1f; cmpwi 3,0; beq 0f; lis 30,-32693; addi 30,30,24536; mr 3,30; bl _s8032488C_0; lis 11,-32702; lis 9,-32697; lfs f0,0xc9c(11); addi 9,9,-17712; stw 9,0xd1c(30); stfs f0,0xd20(30); b 1f; 0:; lis 3,-32693; li 4,2; addi 3,3,24536; bl _s8032488C_1; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8032488C_0();
extern "C" void _s8032488C_1();
extern "C" void f_8032488C() {}
