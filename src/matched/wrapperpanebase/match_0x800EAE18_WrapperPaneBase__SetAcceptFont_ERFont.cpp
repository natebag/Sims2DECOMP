// 0x800EAE18 WrapperPaneBase::SetAcceptFont(ERFont (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 3,0; cmpwi 3,0; beq 0f; li 30,1; 0:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,0; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x318(9); lwz 9,0x31c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,8; bne 3f; lwz 3,0x4(31); li 4,15; lwz 9,0x4(3); lha 0,0x1d0(9); lwz 9,0x1d4(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 3f; cmpwi 31,0; beq 1f; lwz 9,0x4(31); li 4,6; lwz 3,0x0(9); bl _s800EAE18_0; b 2f; 1:; li 3,0; 2:; cmpwi 3,0; beq 3f; li 30,1; 3:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); addi 3,3,40; bl _s800EAE18_1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; rlwinm 4,4,1,0,30; addi 3,3,22; sthx 5,3,4; blr; lwz 9,0x8(3); rlwinm 4,4,1,0,30; sthx 5,4,9"

extern "C" void _s800EAE18_0();
extern "C" void _s800EAE18_1();

struct WrapperPaneBase {
    void SetAcceptFont_ERFont();
};

void WrapperPaneBase::SetAcceptFont_ERFont() {
}
