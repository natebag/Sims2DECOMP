// 0x800406C4 EGlobal::GetFloorIndex(FloorTile (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0xd4(3); li 11,0; lwz 9,0x0(9); cmpwi 9,0; beq 0f; lwz 11,-4(9); 0:; li 3,0; cmpw 3,11; bge 2f; 1:; lwz 0,0x0(9); addi 9,9,4; cmpw 0,4; beqlr; addi 3,3,1; cmpw 3,11; blt 1b; 2:; li 3,0"
extern "C" int f_800406C4() {}
