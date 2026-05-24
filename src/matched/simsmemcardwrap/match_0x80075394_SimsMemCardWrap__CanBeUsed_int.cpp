// 0x80075394 SimsMemCardWrap::CanBeUsed(int, (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 28,0x28(1); stw 0,0x3c(1); mr 29,3; mr 28,4; li 30,0; stw 30,0x8(1); addi 4,1,8; bl _s80075394_0; lwz 0,0x8(1); cmpwi 0,0; bne 0f; stw 30,0x0(28); b 7f; 0:; stw 30,0xc(1); mr 3,29; addi 4,1,12; bl _s80075394_1; lwz 31,0xc(1); cmpwi 31,0; beq 1f; stw 30,0x0(28); b 7f; 1:; stw 31,0x10(1); mr 3,29; addi 4,1,16; bl _s80075394_2; lwz 30,0x10(1); cmpwi 30,0; beq 2f; stw 31,0x0(28); b 7f; 2:; stw 30,0x14(1); mr 3,29; addi 4,1,20; bl _s80075394_3; lwz 31,0x14(1); cmpwi 31,0; beq 3f; stw 30,0x0(28); b 7f; 3:; stw 31,0x18(1); mr 3,29; addi 4,1,24; bl _s80075394_4; lwz 0,0x18(1); cmpwi 0,0; bne 4f; stw 31,0x0(28); b 7f; 4:; lis 5,171; stw 31,0x1c(1); mr 3,29; addi 4,1,28; ori 5,5,52719; bl _s80075394_5; lwz 0,0x1c(1); cmpwi 0,0; bne 5f; stw 0,0x20(1); mr 3,29; addi 4,1,32; li 5,0; bl _s80075394_6; lwz 0,0x20(1); cmpwi 0,0; beq 6f; 5:; li 0,1; li 3,1; stw 0,0x0(28); b 7f; 6:; stw 0,0x0(28); 7:; lwz 0,0x3c(1); mtspr 8,0; lmw 28,0x28(1); addi 1,1,56"

extern "C" void _s80075394_0();
extern "C" void _s80075394_1();
extern "C" void _s80075394_2();
extern "C" void _s80075394_3();
extern "C" void _s80075394_4();
extern "C" void _s80075394_5();
extern "C" void _s80075394_6();

struct SimsMemCardWrap {
    void CanBeUsed();
};

void SimsMemCardWrap::CanBeUsed() {
}
