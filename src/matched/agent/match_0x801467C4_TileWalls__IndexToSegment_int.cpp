// 0x801467C4 TileWalls::IndexToSegment(int, (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 9,1; mr. 4,4; slw 3,9,3; beqlr; li 0,0; cmpwi 3,15; stw 0,0x0(4); blelr; cmpwi 3,16; bne 0f; li 0,2; stw 0,0x0(4); blr; 0:; cmpwi 3,32; bne 1f; li 0,4; li 3,16; stw 0,0x0(4); blr; 1:; cmpwi 3,64; bne 2f; stw 9,0x0(4); li 3,32; blr; 2:; cmpwi 3,128; bnelr; li 0,3; li 3,32; stw 0,0x0(4)"
extern "C" void f_801467C4() {}
