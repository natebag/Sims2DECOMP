// 0x80139C04 IsRectInside(IRect (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 4,4; bne 0f; li 3,1; blr; 0:; lwz 9,0x4(3); lwz 0,0x4(4); cmpw 9,0; blt 1f; lwz 9,0xc(3); lwz 0,0xc(4); cmpw 9,0; bgt 1f; lwz 9,0x0(3); lwz 0,0x0(4); cmpw 9,0; blt 1f; lwz 9,0x8(3); lwz 0,0x8(4); li 3,1; cmpw 9,0; blelr; 1:; li 3,0"
extern "C" int f_80139C04() {}
