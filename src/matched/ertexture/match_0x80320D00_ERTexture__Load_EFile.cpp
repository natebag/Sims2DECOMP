// 0x80320D00 ERTexture::Load(EFile (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 28,0x20(1); stw 0,0x34(1); mr 28,3; mr 29,4; addi 3,1,8; bl _s80320D00_0; lis 5,21592; addi 3,1,8; mr 4,29; ori 5,5,17996; li 6,9; li 7,9; bl _s80320D00_1; cmpwi 3,0; bne 0f; addi 3,1,8; li 4,2; bl _s80320D00_2; b 2f; 0:; addi 3,1,8; bl _s80320D00_3; lwz 30,0x18(1); lwz 0,0x10(28); rlwimi 0,30,8,0,23; stw 0,0x10(28); bl _s80320D00_4; mr 4,30; li 5,0; bl _s80320D00_5; mr. 31,3; bne 1f; bl _s80320D00_6; mr 4,30; li 5,0; bl _s80320D00_7; mr 31,3; 1:; lwz 9,0x28(29); mr 4,31; lwz 5,0x18(1); lha 3,0x18(9); lwz 0,0x1c(9); add 3,29,3; mtspr 8,0; blrl; mr 4,31; mr 3,28; bl _s80320D00_8; bl _s80320D00_9; mr 4,31; bl _s80320D00_10; addi 3,1,8; li 4,2; bl _s80320D00_11; 2:; lwz 0,0x34(1); mtspr 8,0; lmw 28,0x20(1); addi 1,1,48"

extern "C" void _s80320D00_0();
extern "C" void _s80320D00_1();
extern "C" void _s80320D00_2();
extern "C" void _s80320D00_3();
extern "C" void _s80320D00_4();
extern "C" void _s80320D00_5();
extern "C" void _s80320D00_6();
extern "C" void _s80320D00_7();
extern "C" void _s80320D00_8();
extern "C" void _s80320D00_9();
extern "C" void _s80320D00_10();
extern "C" void _s80320D00_11();

struct ERTexture {
    void Load_EFile();
};

void ERTexture::Load_EFile() {
}
