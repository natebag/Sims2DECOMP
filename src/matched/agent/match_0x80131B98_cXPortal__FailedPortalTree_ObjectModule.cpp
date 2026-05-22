// 0x80131B98 cXPortal::FailedPortalTree(ObjectModule (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 11,4; mr 29,3; lwz 9,0x4(11); li 4,6; mr 31,5; lha 3,0x260(9); lwz 0,0x264(9); add 3,11,3; mtspr 8,0; blrl; mr 30,3; cmpwi 31,0; beq 0f; lwz 9,0x4(31); lha 3,0x20(9); lwz 0,0x24(9); add 3,31,3; mtspr 8,0; blrl; b 1f; 0:; li 3,0; 1:; lis 9,-32706; mr 4,30; lfs f1,-12356(9); bl _s80131B98_0; lwz 9,0x4(31); lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; blrl; mr. 11,3; beq 2f; lwz 9,0x4(11); lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; b 3f; 2:; li 3,0; 3:; lis 9,-32706; mr 4,30; lfs f1,-12356(9); bl _s80131B98_1; mr 3,29; mr 4,30; bl _s80131B98_2; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80131B98_0();
extern "C" void _s80131B98_1();
extern "C" void _s80131B98_2();
extern "C" void f_80131B98() {}
