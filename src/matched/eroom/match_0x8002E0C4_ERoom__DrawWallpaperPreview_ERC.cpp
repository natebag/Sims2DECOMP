// 0x8002E0C4 ERoom::DrawWallpaperPreview(ERC (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,4; mr 29,3; lwz 9,0x70(31); mr 30,5; mr 27,6; li 28,0; lha 3,0xf0(9); lwz 0,0xf4(9); add 3,31,3; mtspr 8,0; blrl; addi 3,29,148; mr 4,30; li 5,0; bl _s8002E0C4_0; mr. 3,3; beq 1f; lwz 3,0x1c(3); cmpwi 3,0; beq 1f; lwz 30,0x0(3); cmpwi 30,0; beq 1f; 0:; lwz 3,0x0(30); mr 4,31; mr 5,27; bl _s8002E0C4_1; lwz 30,0x8(30); add 28,28,3; cmpwi 30,0; bne 0b; 1:; mr 3,28; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s8002E0C4_0();
extern "C" void _s8002E0C4_1();

struct ERoom {
    void DrawWallpaperPreview();
};

void ERoom::DrawWallpaperPreview() {
}
