// 0x802854F8 AptActionQueueC::GetDequeSize(void) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x8(3); lis 0,-13108; lwz 11,0x4(3); ori 0,0,52429; subf 9,11,9; mullw 9,9,0; srawi. 9,9,2; bge 0f; lwz 3,0x10(3); add 3,9,3; blr; 0:; mr 3,9"
extern "C" int f_802854F8() {}
