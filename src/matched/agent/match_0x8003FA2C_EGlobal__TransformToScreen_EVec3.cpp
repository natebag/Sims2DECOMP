// 0x8003FA2C EGlobal::TransformToScreen(EVec3 (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; mr 31,5; bl _s8003FA2C_0; mr. 3,3; li 0,0; beq 0f; mr 4,30; mr 5,31; bl _s8003FA2C_1; mr. 0,3; bne 1f; lis 9,-32707; lis 11,-32707; lfs f0,0x278c(9); lfs f13,0x2790(11); stfs f0,0x0(31); stfs f13,0x4(31); b 1f; 0:; lis 9,-32707; lfs f0,0x278c(9); stfs f0,0x0(31); stfs f0,0x4(31); 1:; mr 3,0; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8003FA2C_0();
extern "C" void _s8003FA2C_1();
extern "C" void f_8003FA2C() {}
