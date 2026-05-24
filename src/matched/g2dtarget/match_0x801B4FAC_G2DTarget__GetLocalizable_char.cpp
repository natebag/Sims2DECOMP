// 0x801B4FAC G2DTarget::GetLocalizable(char (368 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,4; mr 28,3; lbz 3,0x0(30); extsb 3,3; bl _s801B4FAC_0; cmpwi 3,0; beq 0f; addi 30,30,1; 0:; li 3,8192; bl _s801B4FAC_1; mr 29,3; li 0,0; lis 3,-32705; sth 0,0x0(29); addi 3,3,2932; mr 4,30; li 5,7; bl _s801B4FAC_2; cmpwi 3,0; bne 5f; addi 3,30,7; bl _s801B4FAC_3; mr 31,3; cmplwi 31,2; ble 1f; lis 3,-32705; mr 4,30; addi 3,3,2940; crxor 6,6,6; bl _s801B4FAC_4; 1:; cmpwi 31,1; beq 3f; ble 2f; cmpwi 31,2; beq 4f; 2:; addi 3,28,260; b 7f; 3:; addi 3,28,264; b 7f; 4:; addi 3,28,268; b 7f; 5:; lis 3,-32705; mr 4,30; addi 3,3,2992; bl _s801B4FAC_5; cmpwi 3,0; bne 6f; addi 3,28,252; b 7f; 6:; lis 3,-32705; mr 4,30; addi 3,3,3008; bl _s801B4FAC_6; cmpwi 3,0; bne 8f; addi 3,28,256; 7:; bl _s801B4FAC_7; mr 4,3; mr 3,29; bl _s801B4FAC_8; b 9f; 8:; lis 3,-32705; mr 4,30; addi 3,3,3024; crxor 6,6,6; bl _s801B4FAC_9; 9:; mr 3,29; bl _s801B4FAC_10; mr 3,29; bl _s801B4FAC_11; mr 3,29; bl _s801B4FAC_12; mr 3,29; bl _s801B4FAC_13; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s801B4FAC_14; mr 30,3; mr 4,29; bl _s801B4FAC_15; mr 3,29; bl _s801B4FAC_16; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s801B4FAC_0();
extern "C" void _s801B4FAC_1();
extern "C" void _s801B4FAC_2();
extern "C" void _s801B4FAC_3();
extern "C" void _s801B4FAC_4();
extern "C" void _s801B4FAC_5();
extern "C" void _s801B4FAC_6();
extern "C" void _s801B4FAC_7();
extern "C" void _s801B4FAC_8();
extern "C" void _s801B4FAC_9();
extern "C" void _s801B4FAC_10();
extern "C" void _s801B4FAC_11();
extern "C" void _s801B4FAC_12();
extern "C" void _s801B4FAC_13();
extern "C" void _s801B4FAC_14();
extern "C" void _s801B4FAC_15();
extern "C" void _s801B4FAC_16();

struct G2DTarget {
    void GetLocalizable();
};

void G2DTarget::GetLocalizable() {
}
