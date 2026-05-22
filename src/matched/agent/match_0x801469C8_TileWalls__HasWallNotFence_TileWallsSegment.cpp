// 0x801469C8 TileWalls::HasWallNotFence(TileWallsSegment) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x0(3); and 0,0,4; cmpw 0,4; bne 3f; mr 4,0; bl _s801469C8_0; cmpwi 3,2; beq 0f; cmpwi 3,12; beq 0f; cmpwi 3,13; beq 0f; cmpwi 3,14; bne 1f; 0:; li 3,1; b 2f; 1:; li 3,0; 2:; xori 3,3,1; b 4f; 3:; li 3,0; 4:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801469C8_0();
extern "C" void f_801469C8() {}
