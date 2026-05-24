// 0x800BE264 IFFResFile2::Create(StringBuffer (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-320(1); mfspr 0,8; stmw 29,0x134(1); stw 0,0x144(1); mr 30,3; mr 29,4; lwz 9,0xc(30); lha 3,0x60(9); lwz 0,0x64(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; addi 3,30,16; mr 4,29; bl _s800BE264_0; mr. 31,3; mr 3,31; bne 1f; addi 3,1,8; bl _s800BE264_1; addi 3,1,8; mr 4,29; bl _s800BE264_2; addi 4,1,8; li 5,0; mr 3,30; bl _s800BE264_3; mr 31,3; addi 3,1,8; bl _s800BE264_4; addi 3,1,8; li 4,2; bl _s800BE264_5; mr 3,31; b 1f; 0:; li 3,-47; 1:; lwz 0,0x144(1); mtspr 8,0; lmw 29,0x134(1); addi 1,1,320"

extern "C" void _s800BE264_0();
extern "C" void _s800BE264_1();
extern "C" void _s800BE264_2();
extern "C" void _s800BE264_3();
extern "C" void _s800BE264_4();
extern "C" void _s800BE264_5();

struct IFFResFile2 {
    void Create_StringBuffer();
};

void IFFResFile2::Create_StringBuffer() {
}
