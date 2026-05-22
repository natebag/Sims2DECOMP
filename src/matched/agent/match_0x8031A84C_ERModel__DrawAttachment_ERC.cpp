// 0x8031A84C ERModel::DrawAttachment(ERC (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 29,0x4c(1); stw 0,0x5c(1); lis 9,-32702; mr 31,4; mr 30,5; lfs f1,0x8e4(9); addi 4,1,8; bl _s8031A84C_0; mr. 29,3; beq 0f; lwz 9,0x70(31); addi 4,1,8; li 5,1; lha 3,0xe8(9); lwz 0,0xec(9); add 3,31,3; mtspr 8,0; blrl; mr 3,30; mr 4,31; bl _s8031A84C_1; 0:; mr 3,29; lwz 0,0x5c(1); mtspr 8,0; lmw 29,0x4c(1); addi 1,1,88"
extern "C" void _s8031A84C_0();
extern "C" void _s8031A84C_1();
extern "C" void f_8031A84C() {}
