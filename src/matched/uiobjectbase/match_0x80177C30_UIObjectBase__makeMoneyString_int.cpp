// 0x80177C30 UIObjectBase::makeMoneyString(int, (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-544(1); mfspr 0,8; stmw 28,0x210(1); stw 0,0x224(1); mr 29,3; mr 31,5; mr. 28,4; beq 0f; addi 30,1,8; li 5,256; addi 4,30,8; mr 3,30; bl _s80177C30_0; mr 5,31; mr 4,30; mr 3,29; bl _s80177C30_1; mr 3,30; bl _s80177C30_2; mr 4,3; mr 3,28; bl _s80177C30_3; li 3,1; b 1f; 0:; li 3,0; 1:; lwz 0,0x224(1); mtspr 8,0; lmw 28,0x210(1); addi 1,1,544"

extern "C" void _s80177C30_0();
extern "C" void _s80177C30_1();
extern "C" void _s80177C30_2();
extern "C" void _s80177C30_3();

struct UIObjectBase {
    void makeMoneyString();
};

void UIObjectBase::makeMoneyString() {
}
