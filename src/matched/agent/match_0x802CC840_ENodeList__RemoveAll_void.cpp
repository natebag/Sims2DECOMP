// 0x802CC840 ENodeList::RemoveAll(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 30,0x4(31); b 1f; 0:; mr 3,30; lwz 30,0x4(30); bl _s802CC840_0; 1:; li 0,1; cmpwi 30,0; bne 2f; li 0,0; 2:; cmpwi 0,0; bne 0b; stw 0,0x0(31); stw 0,0x4(31); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802CC840_0();
extern "C" void f_802CC840() {}
