// 0x80343BFC ENgcRenderer::LineList(EGEVert (296 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; lwz 0,0x510(31); mr 30,5; cmpwi 0,0; beq 0f; li 4,0; bl _s80343BFC_0; 0:; lwz 9,0x4d8(31); li 0,0; li 10,1; li 4,0; lwz 11,0x6cc(9); stw 0,0x4c(9); oris 11,11,32768; stw 0,0x4(9); ori 11,11,1; stw 0,0x28(9); stw 11,0x6cc(9); stw 0,0x2c(9); stw 0,0x30(9); stw 0,0x38(9); stw 0,0x3c(9); stw 0,0x40(9); stw 0,0x44(9); stw 0,0x48(9); lwz 11,0x4d8(31); lwz 0,0x6cc(11); stw 10,0x28(11); oris 0,0,32768; ori 0,0,1; stw 0,0x6cc(11); lwz 9,0x4d8(31); lwz 0,0x6cc(9); stw 10,0x30(9); oris 0,0,32768; ori 0,0,1; stw 0,0x6cc(9); lwz 3,0x4d8(31); bl _s80343BFC_1; li 3,168; li 4,2; rlwinm 5,30,0,16,31; bl _s80343BFC_2; cmpwi 30,0; ble 2f; mtspr 9,30; mr 4,29; lis 8,-13311; 1:; lfs f0,0x0(4); lfs f13,0x4(4); lfs f12,0x8(4); stfs f0,-32768(8); stfs f13,-32768(8); stfs f12,-32768(8); lbz 0,0x33(4); lbz 9,0x37(4); lbz 11,0x3b(4); lbz 10,0x3f(4); stb 0,-32768(8); addi 4,4,80; stb 9,-32768(8); stb 11,-32768(8); stb 10,-32768(8); bdnz 1b; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80343BFC_0();
extern "C" void _s80343BFC_1();
extern "C" void _s80343BFC_2();

struct ENgcRenderer {
    void LineList_EGEVert();
};

void ENgcRenderer::LineList_EGEVert() {
}
