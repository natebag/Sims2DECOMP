// 0x800A7620 QuickStringSet::Count(char) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x8(3); cmpwi 9,0; beq 0f; lwz 9,0x0(9); li 3,0; cmpwi 9,0; beqlr; lwz 3,-4(9); blr; 0:; lwz 3,0x4(3); cmpwi 3,0; beq 2f; lwz 3,0x0(3); li 0,0; cmpwi 3,0; beq 1f; lwz 0,-4(3); 1:; mr 3,0; blr; 2:; li 3,0"
extern "C" int f_800A7620() {}
