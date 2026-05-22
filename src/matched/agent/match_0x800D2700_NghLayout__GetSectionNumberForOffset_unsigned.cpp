// 0x800D2700 NghLayout::GetSectionNumberForOffset(unsigned (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(3); li 3,0; lwz 0,0x4(9); cmpwi 0,0; blelr; lwz 0,0xc(9); subf. 4,0,4; bltlr; 0:; addi 9,9,24; addi 3,3,1; lwz 0,0x4(9); cmpwi 0,0; blelr; lwz 0,0xc(9); subf. 4,0,4; bge 0b"
extern "C" int f_800D2700() {}
