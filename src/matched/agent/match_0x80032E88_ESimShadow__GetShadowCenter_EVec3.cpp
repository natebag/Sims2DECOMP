// 0x80032E88 ESimShadow::GetShadowCenter(EVec3 (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 11,0x320(3); mr 30,4; lwz 9,0x4(11); lwz 0,0x18c(9); lha 3,0x188(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(3); li 4,2; mr 5,30; lha 0,0xe0(9); lwz 9,0xe4(9); add 3,3,0; mtspr 8,9; blrl; lis 9,-32707; lfs f0,0x1190(9); stfs f0,0x8(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_80032E88() {}
