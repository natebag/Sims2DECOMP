// 0x8002FE18 ERoom::GetWallFromTileAndSegment(TileWallsSegment, (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,5; addi 11,3,112; li 10,0; 0:; lwz 9,0x0(11); addi 11,11,4; cmpwi 9,0; beq 2f; lwz 3,0x0(9); cmpwi 3,0; beq 2f; lwz 9,0x0(3); lwz 0,0x20(9); cmpw 0,4; bne 2f; mr 31,3; 1:; lwz 3,0x0(31); mr 4,30; bl _s8002FE18_0; mr. 3,3; bne 4f; lwz 31,0x8(31); cmpwi 31,0; bne 1b; b 3f; 2:; addi 10,10,1; cmpwi 10,3; ble 0b; 3:; li 3,0; 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s8002FE18_0();

struct ERoom {
    void GetWallFromTileAndSegment_TileWallsSegment();
};

void ERoom::GetWallFromTileAndSegment_TileWallsSegment() {
}
