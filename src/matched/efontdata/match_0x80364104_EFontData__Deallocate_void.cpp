// 0x80364104 EFontData::Deallocate(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; addi 30,29,4; lwz 9,0x4(30); b 2f; 0:; lwz 0,0x8(30); lwz 11,0x0(9); cmpwi 0,0; lwz 31,0x4(9); beq 1f; lwz 9,0x0(11); lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 1:; mr 9,31; 2:; li 0,1; cmpwi 9,0; bne 3f; li 0,0; 3:; cmpwi 0,0; bne 0b; mr 3,30; bl _s80364104_0; addi 3,29,40; bl _s80364104_1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80364104_0();
extern "C" void _s80364104_1();

struct EFontData {
    void Deallocate();
};

void EFontData::Deallocate() {
}
