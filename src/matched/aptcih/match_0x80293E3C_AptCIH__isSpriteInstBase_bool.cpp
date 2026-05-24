// 0x80293E3C AptCIH::isSpriteInstBase(bool) (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 30,4; li 28,0; bl _s80293E3C_0; li 29,0; cmpwi 3,13; bne 1f; cmpwi 30,0; bne 0f; mr 3,31; bl _s80293E3C_1; cmpwi 3,0; bne 1f; 0:; li 29,1; 1:; cmpwi 29,0; bne 4f; mr 3,31; li 29,0; bl _s80293E3C_2; cmpwi 3,18; bne 3f; cmpwi 30,0; bne 2f; mr 3,31; bl _s80293E3C_3; cmpwi 3,0; bne 3f; 2:; li 29,1; 3:; cmpwi 29,0; beq 5f; 4:; li 28,1; 5:; mr 3,28; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s80293E3C_0();
extern "C" void _s80293E3C_1();
extern "C" void _s80293E3C_2();
extern "C" void _s80293E3C_3();

struct AptCIH {
    void isSpriteInstBase();
};

void AptCIH::isSpriteInstBase() {
}
