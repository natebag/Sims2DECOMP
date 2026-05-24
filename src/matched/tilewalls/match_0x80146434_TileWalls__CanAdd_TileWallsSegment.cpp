// 0x80146434 TileWalls::CanAdd(TileWallsSegment) (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; mr 31,3; mr 3,30; bl _s80146434_0; lwz 0,0x0(31); or 0,30,0; andi. 9,0,16; beq 0f; cmpwi 0,16; bne 1f; 0:; andi. 9,0,32; beq 2f; cmpwi 0,32; beq 2f; 1:; li 3,0; b 12f; 2:; lwz 0,0x28(31); cmpwi 0,0; bne 3f; lwz 0,0x2c(31); cmpwi 0,0; bne 3f; lwz 0,0x30(31); cmpwi 0,0; bne 3f; lwz 0,0x34(31); cmpwi 0,0; beq 11f; 3:; lwz 0,0x24(31); li 4,0; cmpwi 0,0; beq 4f; subfic 4,0,4; 4:; cmpwi 4,0; beq 5f; mr 3,30; bl _s80146434_1; b 6f; 5:; mr 3,30; 6:; cmpwi 3,2; beq 10f; bgt 7f; cmpwi 3,1; beq 9f; b 11f; 7:; cmpwi 3,4; beq 8f; cmpwi 3,8; bne 11f; lwz 3,0x28(31); xori 3,3,1; b 12f; 8:; lwz 3,0x2c(31); xori 3,3,1; b 12f; 9:; lwz 3,0x30(31); xori 3,3,1; b 12f; 10:; lwz 3,0x34(31); xori 3,3,1; b 12f; 11:; li 3,1; 12:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s80146434_0();
extern "C" void _s80146434_1();

struct TileWalls {
    void CanAdd_TileWallsSegment();
};

void TileWalls::CanAdd_TileWallsSegment() {
}
