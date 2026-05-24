// 0x80146B7C TileWalls::HasDiagonalFence(void) (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x0(31); andi. 9,0,16; beq 3f; li 4,16; bl _s80146B7C_0; cmpwi 3,2; beq 0f; cmpwi 3,12; beq 0f; cmpwi 3,13; beq 0f; cmpwi 3,14; bne 1f; 0:; li 0,1; b 2f; 1:; li 0,0; 2:; cmpwi 0,0; bne 7f; 3:; lwz 0,0x0(31); andi. 9,0,32; beq 8f; mr 3,31; li 4,32; bl _s80146B7C_1; cmpwi 3,2; beq 4f; cmpwi 3,12; beq 4f; cmpwi 3,13; beq 4f; cmpwi 3,14; bne 5f; 4:; li 0,1; b 6f; 5:; li 0,0; 6:; cmpwi 0,0; beq 8f; 7:; li 3,1; b 9f; 8:; li 3,0; 9:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s80146B7C_0();
extern "C" void _s80146B7C_1();

struct TileWalls {
    void HasDiagonalFence();
};

void TileWalls::HasDiagonalFence() {
}
