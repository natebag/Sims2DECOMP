// 0x80210634 InteractorModule::GetObjectPosition(EVec3 (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 31,3; mr. 11,4; beq 0f; lwz 9,0x4(11); addi 30,1,24; mr 3,30; lwz 0,0x35c(9); lha 4,0x358(9); mtspr 8,0; add 4,11,4; blrl; addi 3,1,8; mr 4,30; bl _s80210634_0; addi 9,1,8; lwz 11,0x8(1); lwz 10,0x8(9); mr 3,30; lwz 0,0x4(9); li 4,2; stw 11,0x0(31); stw 0,0x4(31); stw 10,0x8(31); bl _s80210634_1; lis 9,-32704; lfs f0,-11248(9); stfs f0,0x8(31); 0:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"
extern "C" void _s80210634_0();
extern "C" void _s80210634_1();
extern "C" void f_80210634() {}
