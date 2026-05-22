// 0x802CCAB4 ENodeList::MoveContents(ENodeList (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 30,4; bl _s802CCAB4_0; lwz 9,0x0(30); li 11,0; lwz 0,0x4(30); stw 9,0x0(29); stw 0,0x4(29); stw 11,0x4(30); stw 11,0x0(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802CCAB4_0();
extern "C" void f_802CCAB4() {}
