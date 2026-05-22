// 0x802CC670 ENodeList::AddHead(ENodeList (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 30,0x4(4); mr 31,3; b 1f; 0:; lwz 4,0x0(30); lwz 30,0x4(30); bl _s802CC670_0; 1:; mr 3,31; li 0,1; cmpwi 30,0; bne 2f; li 0,0; 2:; cmpwi 0,0; bne 0b; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802CC670_0();
extern "C" void f_802CC670() {}
