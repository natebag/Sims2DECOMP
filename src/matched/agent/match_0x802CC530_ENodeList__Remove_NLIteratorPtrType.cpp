// 0x802CC530 ENodeList::Remove(NLIteratorPtrType (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 11,3; lwz 0,0x0(11); mr 3,4; cmpw 0,3; bne 0f; lwz 0,0x8(3); stw 0,0x0(11); b 1f; 0:; lwz 9,0x4(3); lwz 0,0x8(3); stw 0,0x8(9); 1:; lwz 0,0x4(11); cmpw 0,3; bne 2f; lwz 0,0x4(3); stw 0,0x4(11); b 3f; 2:; lwz 9,0x8(3); lwz 0,0x4(3); stw 0,0x4(9); 3:; bl _s802CC530_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802CC530_0();
extern "C" void f_802CC530() {}
