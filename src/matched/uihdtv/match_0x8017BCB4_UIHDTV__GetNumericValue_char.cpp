// 0x8017BCB4 UIHDTV::GetNumericValue(char (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 25,5; mr 27,3; mr 29,4; mr 26,6; li 30,0; mr 31,25; b 1f; 0:; addi 30,30,1; addi 31,31,1; 1:; lbzx 4,29,31; mr 3,27; extsb 4,4; bl _s8017BCB4_0; mr. 28,3; bne 0b; stw 30,0x0(26); addi 3,30,1; bl _s8017BCB4_1; mr 31,3; mr 5,30; add 4,29,25; bl _s8017BCB4_2; stbx 28,31,30; mr 3,31; bl _s8017BCB4_3; mr 30,3; cmpwi 31,0; beq 2f; mr 3,31; bl _s8017BCB4_4; 2:; mr 3,30; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"

extern "C" void _s8017BCB4_0();
extern "C" void _s8017BCB4_1();
extern "C" void _s8017BCB4_2();
extern "C" void _s8017BCB4_3();
extern "C" void _s8017BCB4_4();

struct UIHDTV {
    void GetNumericValue();
};

void UIHDTV::GetNumericValue() {
}
