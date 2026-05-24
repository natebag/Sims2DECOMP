// 0x80363BF8 EFontSize::Deallocate(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lwz 30,0x10(31); addi 29,31,16; b 1f; 0:; lwz 11,0x10(30); lwz 30,0x4(30); lwz 9,0x0(11); lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 1:; li 0,1; cmpwi 30,0; bne 2f; li 0,0; 2:; cmpwi 0,0; bne 0b; mr 3,29; bl _s80363BF8_0; mr 3,31; bl _s80363BF8_1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80363BF8_0();
extern "C" void _s80363BF8_1();

struct EFontSize {
    void Deallocate();
};

void EFontSize::Deallocate() {
}
