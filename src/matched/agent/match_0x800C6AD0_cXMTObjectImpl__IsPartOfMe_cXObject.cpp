// 0x800C6AD0 cXMTObjectImpl::IsPartOfMe(cXObject (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0xc(3); cmpwi 0,0; beq 2f; mr 3,0; b 2f; 0:; lwz 9,0x4(3); lwz 0,0x0(9); cmpw 0,4; bne 1f; li 3,1; blr; 1:; lwz 3,0x8(3); 2:; cmpwi 3,0; bne 0b; li 3,0"
extern "C" int f_800C6AD0() {}
