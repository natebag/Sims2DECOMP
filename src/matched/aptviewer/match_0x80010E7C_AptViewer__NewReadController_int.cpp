// 0x80010E7C AptViewer::NewReadController(int, (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 31,0; 0:; lwz 3,-26524(13); li 4,0; bl _s80010E7C_0; cmpwi 3,0; beq 1f; lwz 3,-26524(13); li 4,0; bl _s80010E7C_1; cmpw 3,31; bne 1f; mr 3,30; li 4,0; b 2f; 1:; lwz 3,-26524(13); li 4,1; bl _s80010E7C_2; cmpwi 3,0; beq 3f; lwz 3,-26524(13); li 4,1; bl _s80010E7C_3; cmpw 3,31; bne 3f; mr 3,30; li 4,1; 2:; mr 5,31; bl _s80010E7C_4; b 4f; 3:; lwz 4,0x3ac(30); cmpwi 4,-1; beq 4f; mr 3,30; mr 5,31; bl _s80010E7C_5; 4:; addi 31,31,1; cmpwi 31,4; blt 0b; li 3,0; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s80010E7C_0();
extern "C" void _s80010E7C_1();
extern "C" void _s80010E7C_2();
extern "C" void _s80010E7C_3();
extern "C" void _s80010E7C_4();
extern "C" void _s80010E7C_5();

struct AptViewer {
    void NewReadController();
};

void AptViewer::NewReadController() {
}
