// 0x802CC720 ENodeList::InsertBefore(NLIteratorPtrType (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 31,4; mr 29,5; li 3,12; bl _s802CC720_0; mr. 3,3; beq 3f; stw 29,0x0(3); lwz 9,0x4(31); cmpwi 9,0; beq 0f; stw 3,0x8(9); lwz 0,0x4(31); stw 0,0x4(3); stw 3,0x4(31); stw 31,0x8(3); b 3f; 0:; lwz 9,0x0(30); stw 9,0x8(3); cmpwi 9,0; beq 1f; stw 3,0x4(9); b 2f; 1:; stw 3,0x4(30); 2:; li 0,0; stw 0,0x4(3); stw 3,0x0(30); 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802CC720_0();
extern "C" void f_802CC720() {}
