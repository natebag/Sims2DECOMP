// 0x800BE8CC IFFResFile2::Update(void) (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-304(1); mfspr 0,8; stmw 26,0x118(1); stw 0,0x134(1); mr 30,3; lwz 9,0xc(30); lha 3,0x60(9); lwz 0,0x64(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; mr 3,30; li 4,-49; bl _s800BE8CC_0; b 1f; 0:; mr 3,30; li 4,0; bl _s800BE8CC_1; 1:; mr 3,30; bl _s800BE8CC_2; cmpwi 3,0; bne 8f; lwz 29,0x138(30); li 26,0; mr 3,29; bl _s800BE8CC_3; mr. 31,3; ble 6f; 2:; mr 4,31; mr 3,29; bl _s800BE8CC_4; addi 27,31,-1; mr 28,3; mr 3,29; mr 4,28; bl _s800BE8CC_5; mr. 31,3; ble 5f; 3:; mr 3,29; mr 4,28; mr 5,31; li 6,0; bl _s800BE8CC_6; lwz 0,0x0(3); cmpwi 0,-1; bne 4f; lwz 9,0xc(30); lwz 4,0xc(3); lha 3,0x108(9); lwz 0,0x10c(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 26,0; bne 4f; mr 3,30; bl _s800BE8CC_7; mr 26,3; 4:; addic. 31,31,-1; bgt 3b; 5:; mr. 31,27; bgt 2b; 6:; cmpwi 26,0; bne 7f; addi 3,30,16; bl _s800BE8CC_8; mr 26,3; 7:; mr 3,30; mr 4,26; bl _s800BE8CC_9; 8:; lwz 0,0x134(1); mtspr 8,0; lmw 26,0x118(1); addi 1,1,304"

extern "C" void _s800BE8CC_0();
extern "C" void _s800BE8CC_1();
extern "C" void _s800BE8CC_2();
extern "C" void _s800BE8CC_3();
extern "C" void _s800BE8CC_4();
extern "C" void _s800BE8CC_5();
extern "C" void _s800BE8CC_6();
extern "C" void _s800BE8CC_7();
extern "C" void _s800BE8CC_8();
extern "C" void _s800BE8CC_9();

struct IFFResFile2 {
    void Update();
};

void IFFResFile2::Update() {
}
