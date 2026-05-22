// 0x8002F81C ERoomWall::CountWalls(void) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x14(3); li 3,0; cmpwi 9,0; beqlr; 0:; lwz 0,0x0(9); cmpwi 0,0; beq 1f; addi 3,3,1; 1:; lwz 9,0x8(9); cmpwi 9,0; bne 0b"
extern "C" int f_8002F81C() {}
