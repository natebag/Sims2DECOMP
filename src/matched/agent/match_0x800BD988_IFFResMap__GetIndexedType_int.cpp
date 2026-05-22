// 0x800BD988 IFFResMap::GetIndexedType(int) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 4,4; ble 0f; lwz 11,0x0(3); lis 9,-21846; lwz 0,0x4(3); ori 9,9,43691; subf 0,11,0; mullw 0,0,9; srawi 0,0,3; cmpw 4,0; bgt 0f; mulli 9,4,24; add 9,11,9; lwz 3,-8(9); blr; 0:; li 3,0"
extern "C" int f_800BD988() {}
