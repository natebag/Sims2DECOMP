// 0x8004EB70 ISimsObjectModel::CalcOrient(void) (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-168(1); mfspr 0,8; stmw 29,0x9c(1); stw 0,0xac(1); mr 31,3; addi 29,1,72; addi 3,1,8; lfs f1,0x3f0(31); mr 30,3; bl _s8004EB70_0; addi 3,1,8; addi 4,31,1028; bl _s8004EB70_1; lis 9,-32707; lis 11,-32707; lfs f0,0x3208(9); mr 4,29; lfs f13,0x320c(11); mr 3,30; stfs f0,0x48(1); stfs f0,0x4(29); stfs f13,0x8(29); bl _s8004EB70_2; lwz 9,0x0(31); mr 4,30; lwz 0,0x9c(9); lha 3,0x98(9); mtspr 8,0; add 3,31,3; blrl; lwz 0,0x44c(31); cmpwi 0,0; beq 0f; cmpw 0,31; beq 0f; lwz 9,0x0(31); addi 30,1,88; mr 4,30; lwz 0,0x114(9); lha 3,0x110(9); mtspr 8,0; add 3,31,3; blrl; lis 9,-32707; lis 11,-32707; lfs f0,0x3210(9); mr 4,29; lfs f13,0x3214(11); mr 3,30; stfs f0,0x48(1); stfs f0,0x4(29); stfs f13,0x8(29); bl _s8004EB70_3; lwz 11,0x44c(31); mr 4,30; lwz 9,0x0(11); lha 3,0x98(9); lwz 0,0x9c(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 0,0xac(1); mtspr 8,0; lmw 29,0x9c(1); addi 1,1,168"
extern "C" void _s8004EB70_0();
extern "C" void _s8004EB70_1();
extern "C" void _s8004EB70_2();
extern "C" void _s8004EB70_3();
extern "C" void f_8004EB70() {}
