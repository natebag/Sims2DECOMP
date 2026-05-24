// 0x802E4658 E3DWindow::SetLookAt(EVec3 (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; addi 29,30,224; mr 3,29; bl _s802E4658_0; mr 4,29; addi 3,30,160; bl _s802E4658_1; mr 3,30; bl _s802E4658_2; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s802E4658_0();
extern "C" void _s802E4658_1();
extern "C" void _s802E4658_2();

struct E3DWindow {
    void SetLookAt();
};

void E3DWindow::SetLookAt() {
}
