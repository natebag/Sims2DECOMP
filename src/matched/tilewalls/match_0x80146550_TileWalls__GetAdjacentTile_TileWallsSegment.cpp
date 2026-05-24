// 0x80146550 TileWalls::GetAdjacentTile(TileWallsSegment, (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,4; cmpwi 3,4; beq 3f; bgt 0f; cmpwi 3,1; beq 1f; cmpwi 3,2; beq 2f; b 6f; 0:; cmpwi 3,16; beq 6f; bgt 6f; cmpwi 3,8; beq 5f; b 6f; 1:; li 4,2; b 4f; 2:; li 4,0; b 4f; 3:; li 4,3; 4:; li 5,0; addi 3,1,8; bl _s80146550_0; addi 4,1,8; mr 3,31; bl _s80146550_1; addi 3,1,8; li 4,2; bl _s80146550_2; b 6f; 5:; li 4,1; li 5,0; addi 3,1,8; bl _s80146550_3; addi 4,1,8; mr 3,31; bl _s80146550_4; addi 3,1,8; li 4,2; bl _s80146550_5; 6:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"

extern "C" void _s80146550_0();
extern "C" void _s80146550_1();
extern "C" void _s80146550_2();
extern "C" void _s80146550_3();
extern "C" void _s80146550_4();
extern "C" void _s80146550_5();

struct TileWalls {
    void GetAdjacentTile_TileWallsSegment();
};

void TileWalls::GetAdjacentTile_TileWallsSegment() {
}
