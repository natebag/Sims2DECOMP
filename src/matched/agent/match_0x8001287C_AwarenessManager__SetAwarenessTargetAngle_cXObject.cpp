// 0x8001287C AwarenessManager::SetAwarenessTargetAngle(cXObject (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32707; mr 30,3; lfs f0,-9032(9); li 29,0; mr. 31,4; stfs f0,0x20(30); beq 0f; lwz 9,0x4(31); lha 3,0x1a8(9); lwz 0,0x1ac(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; lwz 11,0x34(30); mr 4,31; lwz 10,0x0(11); lwz 9,0x4(10); lha 3,0x20(9); lwz 0,0x24(9); add 3,10,3; mtspr 8,0; blrl; lis 9,-32707; lfs f0,-9028(9); fcmpu 0,f1,f0; bge 0f; lwz 4,0x1c(30); mr 3,30; bl _s8001287C_0; lis 9,-32707; fabs f0,f1; lfs f13,-9024(9); fcmpu 0,f0,f13; cror 3,2,0; bns 0f; stfs f1,0x20(30); li 29,1; 0:; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8001287C_0();
extern "C" void f_8001287C() {}
