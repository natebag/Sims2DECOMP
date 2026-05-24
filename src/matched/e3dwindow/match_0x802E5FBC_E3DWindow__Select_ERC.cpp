// 0x802E5FBC E3DWindow::Select(ERC (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; bl _s802E5FBC_0; lfs f13,0x50(30); addi 9,30,80; addi 11,30,560; stfs f13,0x230(30); lfs f0,0x4(9); stfs f0,0x4(11); lfs f13,0x8(9); stfs f13,0x8(11); lfs f0,0xc(9); stfs f0,0xc(11); lwz 9,0x9c(30); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,30,3; blrl; mr 3,30; bl _s802E5FBC_1; lwz 9,0x70(29); addi 4,30,608; lwz 0,0xc4(9); lha 3,0xc0(9); mtspr 8,0; add 3,29,3; blrl; lwz 11,0x70(29); lis 9,-32702; lfs f1,-5036(9); li 5,0; lwz 0,0xfc(11); addi 4,30,160; lha 3,0xf8(11); mtspr 8,0; add 3,29,3; blrl; lwz 9,0x70(29); addi 4,30,352; lha 3,0x100(9); lwz 0,0x104(9); add 3,29,3; mtspr 8,0; blrl; mr 3,30; mr 4,29; bl _s802E5FBC_2; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s802E5FBC_0();
extern "C" void _s802E5FBC_1();
extern "C" void _s802E5FBC_2();

struct E3DWindow {
    void Select();
};

void E3DWindow::Select() {
}
