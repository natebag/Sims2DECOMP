// 0x802E7078 E3DWindow::GetFrustrumQuadAtZ(float, (408 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stfd f31,0x38(1); stmw 28,0x28(1); stw 0,0x44(1); mr 30,3; addi 28,1,24; lis 3,-32702; mr 29,4; fmr f31,f1; addi 3,3,-4936; crxor 6,6,6; bl _s802E7078_0; addi 4,1,8; li 5,1; mr 3,30; bl _s802E7078_1; lis 3,-32702; addi 3,3,-4928; crxor 6,6,6; bl _s802E7078_2; addi 5,1,8; fmr f1,f31; mr 3,30; mr 4,28; bl _s802E7078_3; lwz 11,0x18(1); addi 4,1,8; lwz 9,0x1c(1); li 5,0; lwz 0,0x20(1); mr 3,30; stw 11,0x0(29); stw 9,0x4(29); stw 0,0x8(29); bl _s802E7078_4; lis 3,-32702; addi 3,3,-4924; crxor 6,6,6; bl _s802E7078_5; addi 5,1,8; fmr f1,f31; mr 3,30; mr 4,28; bl _s802E7078_6; lwz 11,0x18(1); addi 9,29,12; lwz 10,0x1c(1); addi 4,1,8; lwz 0,0x20(1); li 5,2; stw 11,0xc(29); mr 3,30; stw 0,0x8(9); stw 10,0x4(9); bl _s802E7078_7; lis 3,-32702; addi 3,3,-4920; crxor 6,6,6; bl _s802E7078_8; addi 5,1,8; fmr f1,f31; mr 3,30; mr 4,28; bl _s802E7078_9; lwz 11,0x18(1); addi 9,29,24; lwz 10,0x1c(1); addi 4,1,8; lwz 0,0x20(1); li 5,3; stw 11,0x18(29); mr 3,30; stw 0,0x8(9); stw 10,0x4(9); bl _s802E7078_10; lis 3,-32702; addi 3,3,-4916; crxor 6,6,6; bl _s802E7078_11; mr 3,30; mr 4,28; fmr f1,f31; addi 5,1,8; bl _s802E7078_12; lwz 11,0x18(1); addi 9,29,36; lwz 10,0x1c(1); lis 3,-32702; lwz 0,0x20(1); addi 3,3,-4912; stw 11,0x24(29); stw 0,0x8(9); stw 10,0x4(9); crxor 6,6,6; bl _s802E7078_13; lwz 0,0x44(1); mtspr 8,0; lmw 28,0x28(1); lfd f31,0x38(1); addi 1,1,64"

extern "C" void _s802E7078_0();
extern "C" void _s802E7078_1();
extern "C" void _s802E7078_2();
extern "C" void _s802E7078_3();
extern "C" void _s802E7078_4();
extern "C" void _s802E7078_5();
extern "C" void _s802E7078_6();
extern "C" void _s802E7078_7();
extern "C" void _s802E7078_8();
extern "C" void _s802E7078_9();
extern "C" void _s802E7078_10();
extern "C" void _s802E7078_11();
extern "C" void _s802E7078_12();
extern "C" void _s802E7078_13();

struct E3DWindow {
    void GetFrustrumQuadAtZ();
};

void E3DWindow::GetFrustrumQuadAtZ() {
}
