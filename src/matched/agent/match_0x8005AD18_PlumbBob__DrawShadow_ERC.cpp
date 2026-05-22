// 0x8005AD18 PlumbBob::DrawShadow(ERC (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,3; lwz 9,0x70(30); addi 4,29,48; lwz 0,0x16c(9); lha 3,0x168(9); mtspr 8,0; add 3,30,3; blrl; lwz 11,0x164(29); mr 4,30; lwz 10,0x0(29); lwz 8,0x4(29); addi 9,11,12; lwz 0,0x8(29); stw 10,0xc(11); stw 0,0x8(9); stw 8,0x4(9); lwz 3,0x164(29); bl _s8005AD18_0; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8005AD18_0();
extern "C" void f_8005AD18() {}
