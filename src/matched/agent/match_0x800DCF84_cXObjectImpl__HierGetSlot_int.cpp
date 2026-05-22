// 0x800DCF84 cXObjectImpl::HierGetSlot(int) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 4,4; blt 0f; lwz 9,0x90(3); lwz 0,0x94(3); subf 0,9,0; srawi 0,0,5; cmplw 4,0; bge 0f; rlwinm 3,4,5,0,26; add 3,9,3; blr; 0:; li 3,0"
extern "C" int f_800DCF84() {}
