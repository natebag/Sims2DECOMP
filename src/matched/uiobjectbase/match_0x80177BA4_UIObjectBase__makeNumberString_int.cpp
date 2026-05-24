// 0x80177BA4 UIObjectBase::makeNumberString(int, (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 29,0x2c(1); stw 0,0x3c(1); mr 30,3; mr. 31,4; beq 0f; addi 29,1,8; li 4,0; li 5,32; mr 3,29; crxor 6,6,6; bl _s80177BA4_0; lis 4,-32706; mr 5,30; addi 4,4,9356; mr 3,29; crxor 6,6,6; bl _s80177BA4_1; mr 30,3; mr 5,31; mr 3,29; mr 4,30; bl _s80177BA4_2; add 30,30,30; li 0,0; sthx 0,30,31; li 3,1; b 1f; 0:; li 3,0; 1:; lwz 0,0x3c(1); mtspr 8,0; lmw 29,0x2c(1); addi 1,1,56"

extern "C" void _s80177BA4_0();
extern "C" void _s80177BA4_1();
extern "C" void _s80177BA4_2();

struct UIObjectBase {
    void makeNumberString();
};

void UIObjectBase::makeNumberString() {
}
