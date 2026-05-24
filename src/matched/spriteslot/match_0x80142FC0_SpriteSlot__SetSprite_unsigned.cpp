// 0x80142FC0 SpriteSlot::SetSprite(unsigned (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; mr. 7,7; stw 5,0x18(31); stw 6,0x2c(31); beq 0f; addi 0,6,-1; li 9,-1; stw 0,0x30(31); stw 9,0x34(31); b 1f; 0:; li 0,1; stw 7,0x30(31); stw 0,0x34(31); 1:; lwz 3,-21432(13); mr 4,31; bl _s80142FC0_0; li 0,-1; stw 0,0x40(31); stw 0,0x3c(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s80142FC0_0();

struct SpriteSlot {
    void SetSprite();
};

void SpriteSlot::SetSprite() {
}
