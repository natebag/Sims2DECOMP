// 0x8022EF24 EIStaticSubModel::DrawWireFrame(ERC (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,3; lwz 9,0x70(30); lwz 0,0xf4(9); lha 3,0xf0(9); mtspr 8,0; add 3,30,3; blrl; lwz 0,0x7c(29); mr 4,30; lwz 9,0xa0(29); mulli 0,0,24; lwz 3,0x3c(9); add 3,3,0; bl _s8022EF24_0; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8022EF24_0();
extern "C" void f_8022EF24() {}
