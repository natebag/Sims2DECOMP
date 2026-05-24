// 0x8002CDD8 ERoomWall::AddTile(CTilePt (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 27,3; mr 31,4; mr 30,8; mr 26,5; mr 29,6; mr 28,7; addi 3,27,3; bl _s8002CDD8_0; cmpwi 30,0; beq 0f; li 3,952; bl _s8002CDD8_1; mr 4,26; mr 5,29; mr 6,28; mr 7,31; bl _s8002CDD8_2; mr 4,3; addi 3,27,20; bl _s8002CDD8_3; 0:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"

extern "C" void _s8002CDD8_0();
extern "C" void _s8002CDD8_1();
extern "C" void _s8002CDD8_2();
extern "C" void _s8002CDD8_3();

struct ERoomWall {
    void AddTile_CTilePt();
};

void ERoomWall::AddTile_CTilePt() {
}
