// 0x801389B4 FindIntersectingRect(IRect (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 10,4; lwz 0,0x4(10); lwz 11,0x0(10); cmpw 11,0; beq 2f; lis 4,-13108; lwz 7,0x0(3); mr 8,0; ori 4,4,52429; 0:; lwz 0,0x8(11); cmpw 7,0; bge 1f; lwz 9,0x8(3); lwz 0,0x0(11); cmpw 9,0; ble 1f; lwz 9,0x4(3); lwz 0,0xc(11); cmpw 9,0; bge 1f; lwz 9,0xc(3); lwz 0,0x4(11); cmpw 9,0; ble 1f; lwz 3,0x0(10); subf 3,3,11; mullw 3,3,4; srawi 3,3,2; blr; 1:; addi 11,11,20; cmpw 11,8; bne 0b; 2:; li 3,-1"
extern "C" int f_801389B4() {}
