// 0x80079A8C CUnlockDisplayObject::SetAnimationID(unsigned (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x30(3); li 9,0; stw 4,0x34(3); cmpwi 0,0; beq 0f; cmpwi 4,0; bne 1f; 0:; li 9,1; 1:; stw 9,0x80(3)"
extern "C" void f_80079A8C() {}
