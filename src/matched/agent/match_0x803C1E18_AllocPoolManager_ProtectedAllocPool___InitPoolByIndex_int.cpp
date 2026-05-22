// 0x803C1E18 AllocPoolManager<ProtectedAllocPool>::InitPoolByIndex(int, (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 9,4; mr 28,6; mulli 30,9,52; rlwinm 0,9,2,0,29; mr 29,3; lwzx 6,5,0; addi 9,9,1; mr 4,28; rlwinm 5,9,3,0,28; addi 3,30,8; add 3,29,3; bl _s803C1E18_0; add 30,30,29; addi 30,30,8; lwz 0,0x8(30); lwz 3,0xc(30); mullw 3,3,0; add 3,28,3; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s803C1E18_0();
extern "C" void f_803C1E18() {}
