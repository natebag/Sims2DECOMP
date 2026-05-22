// 0x800D2744 NghLayout::GetSubSectionNumberForOffset(unsigned (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 7,3; lwz 11,0x4(7); li 3,0; lwz 0,0x4(11); cmpwi 0,0; blelr; li 8,0; 0:; lwzx 0,8,11; li 10,0; add 9,8,11; cmpw 10,0; bge 2f; lwz 0,0x4(9); subf. 4,0,4; bltlr; lwz 9,0x4(7); lwzx 11,8,9; add 9,8,9; 1:; addi 10,10,1; addi 3,3,1; cmpw 10,11; bge 2f; lwz 0,0x4(9); subf. 4,0,4; bge 1b; 2:; cmpwi 4,0; bltlr; lwz 11,0x4(7); addi 8,8,24; add 9,8,11; lwz 0,0x4(9); cmpwi 0,0; bgt 0b"
extern "C" int f_800D2744() {}
