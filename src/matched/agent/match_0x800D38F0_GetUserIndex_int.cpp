// 0x800D38F0 GetUserIndex(int) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 11,3; addi 9,13,-31940; li 3,0; 0:; lwz 0,0x0(9); addi 9,9,4; cmpw 11,0; beqlr; addi 3,3,1; cmpwi 3,1; ble 0b; li 3,-1"
extern "C" int f_800D38F0() {}
