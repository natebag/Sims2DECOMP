// 0x80146CCC TileWalls::SetPattern(WallPattern, (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); mr 29,5; mr 31,3; mr 26,4; mr 28,6; cmpwi 29,255; beq 0f; mr 4,29; bl _s80146CCC_0; 0:; cmpwi 29,16; bne 1f; cmpwi 28,0; bne 1f; li 28,4; b 2f; 1:; cmpwi 29,32; bne 2f; cmpwi 28,0; bne 2f; li 28,1; 2:; addi 30,31,20; addi 27,1,8; li 31,0; 3:; mr 3,31; mr 4,27; bl _s80146CCC_1; and. 0,3,29; beq 4f; lwz 0,0x8(1); cmpw 0,28; bne 4f; sth 26,0x0(30); 4:; addi 31,31,1; addi 30,30,2; cmplwi 31,7; ble 3b; mr 3,29; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"

extern "C" void _s80146CCC_0();
extern "C" void _s80146CCC_1();

struct TileWalls {
    void SetPattern_WallPattern();
};

void TileWalls::SetPattern_WallPattern() {
}
