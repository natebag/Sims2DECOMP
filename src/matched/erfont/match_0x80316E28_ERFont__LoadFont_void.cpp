// 0x80316E28 ERFont::LoadFont(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; li 30,0; lwz 9,0x54(29); lwz 0,0x24(9); cmpw 30,0; bge 2f; lis 27,-32692; li 28,0; 0:; lwz 9,0x54(29); lwz 11,0x20(9); lwzx 31,11,28; lwz 0,0x8(31); cmpwi 0,0; bne 1f; lwz 4,0x4(31); addi 3,27,-17444; li 5,0; li 6,0; bl _s80316E28_0; stw 3,0x8(31); 1:; lwz 9,0x54(29); addi 30,30,1; addi 28,28,4; lwz 0,0x24(9); cmpw 30,0; blt 0b; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s80316E28_0();

struct ERFont {
    void LoadFont();
};

void ERFont::LoadFont() {
}
