// 0x801B8BA4 H2DTarget::SelectedPersonChanged(int, (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; mr 31,5; bl _s801B8BA4_0; addi 30,30,156; rlwinm 0,29,2,0,29; lwzx 3,30,0; cmpwi 3,0; beq 0f; mr 4,31; bl _s801B8BA4_1; 0:; cmpwi 31,0; beq 1f; lwz 9,0x4(31); lha 3,0x3b0(9); lwz 0,0x3b4(9); add 3,31,3; mtspr 8,0; blrl; 1:; lis 9,-32697; rlwinm 4,29,4,0,27; addi 9,9,23428; add 11,4,9; lwz 0,0x100(11); cmpwi 0,0; beq 2f; mr 9,11; lwz 3,0x100(9); bl _s801B8BA4_2; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801B8BA4_0();
extern "C" void _s801B8BA4_1();
extern "C" void _s801B8BA4_2();
extern "C" void f_801B8BA4() {}
