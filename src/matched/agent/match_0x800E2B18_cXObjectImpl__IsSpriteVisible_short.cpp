// 0x800E2B18 cXObjectImpl::IsSpriteVisible(short) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lha 0,0x14(3); mr 11,4; cmpwi 0,0; bne 1f; 0:; li 3,1; blr; 1:; lwz 9,0x88(3); lha 4,0x80(9); cmpw 11,4; blt 0b; add 0,4,0; cmpw 11,0; bge 0b; subf 9,4,11; lwz 11,0x10(3); add 9,9,9; li 3,1; lhax 0,9,11; cmpwi 0,0; bnelr; li 3,0"
extern "C" int f_800E2B18() {}
