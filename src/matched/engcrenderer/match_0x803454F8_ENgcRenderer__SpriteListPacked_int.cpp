// 0x803454F8 ENgcRenderer::SpriteListPacked(int, (696 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 25,0x2c(1); stw 0,0x4c(1); lwz 0,-26252(13); li 31,0; mr 28,3; mr 25,4; mr 27,5; mr 29,6; mr 30,7; cmpwi 0,0; stw 31,-26196(13); beq 3f; lwz 0,0x510(28); cmpwi 0,0; beq 0f; li 4,0; bl _s803454F8_0; 0:; lwz 9,0x4d8(28); li 11,15; li 10,1; li 4,0; lwz 0,0x6cc(9); li 26,0; stw 11,0x0(9); oris 0,0,32768; stw 0,0x6cc(9); lwz 11,0x4d8(28); lwz 0,0x6cc(11); oris 0,0,32768; stw 0,0x6cc(11); lwz 9,0x4d8(28); lwz 0,0x6cc(9); stw 31,0x4c(9); oris 0,0,32768; stw 31,0x4(9); ori 0,0,1; stw 31,0x28(9); stw 0,0x6cc(9); stw 31,0x2c(9); stw 31,0x30(9); stw 31,0x38(9); stw 31,0x3c(9); stw 31,0x40(9); stw 31,0x44(9); stw 31,0x48(9); lwz 11,0x4d8(28); lwz 0,0x6cc(11); stw 10,0x28(11); oris 0,0,32768; ori 0,0,1; stw 0,0x6cc(11); lwz 9,0x4d8(28); lwz 0,0x6cc(9); stw 10,0x30(9); oris 0,0,32768; ori 0,0,1; stw 0,0x6cc(9); lwz 11,0x4d8(28); lwz 0,0x6cc(11); stw 10,0x38(11); oris 0,0,32768; ori 0,0,1; stw 0,0x6cc(11); lwz 3,0x4d8(28); bl _s803454F8_1; li 3,128; li 4,7; rlwinm 5,25,1,16,30; bl _s803454F8_2; cmpw 26,25; bge 2f; lis 31,-13311; 1:; lwz 3,0x4d8(28); mr 4,27; addi 5,1,8; addi 26,26,2; addi 3,3,2144; bl _s803454F8_3; lwz 3,0x4d8(28); addi 4,27,16; addi 5,1,24; addi 27,27,32; addi 3,3,2144; bl _s803454F8_4; lfs f11,0x8(1); cmpw 26,25; lfs f9,0xc(1); stfs f11,-32768(31); lfs f12,0x10(1); stfs f9,-32768(31); stfs f12,-32768(31); lbz 0,0x0(30); lbz 9,0x1(30); lbz 11,0x2(30); lbz 10,0x3(30); lfs f10,0x1c(1); stb 0,-32768(31); stb 9,-32768(31); stb 11,-32768(31); stb 10,-32768(31); lfs f0,0x0(29); lfs f13,0x4(29); stfs f0,-32768(31); stfs f13,-32768(31); stfs f11,-32768(31); stfs f10,-32768(31); stfs f12,-32768(31); lbz 0,0x0(30); lbz 9,0x1(30); lbz 11,0x2(30); lbz 10,0x3(30); stb 0,-32768(31); stb 9,-32768(31); stb 11,-32768(31); stb 10,-32768(31); lfs f0,0x0(29); lfs f13,0xc(29); stfs f0,-32768(31); stfs f13,-32768(31); lfs f12,0x18(1); lfs f11,0x20(1); stfs f12,-32768(31); stfs f10,-32768(31); stfs f11,-32768(31); lbz 0,0x4(30); lbz 9,0x5(30); lbz 11,0x6(30); lbz 10,0x7(30); stb 0,-32768(31); stb 9,-32768(31); stb 11,-32768(31); stb 10,-32768(31); lfs f0,0x8(29); lfs f13,0xc(29); stfs f0,-32768(31); stfs f13,-32768(31); stfs f12,-32768(31); stfs f9,-32768(31); stfs f11,-32768(31); lbz 0,0x4(30); lbz 9,0x5(30); lbz 11,0x6(30); lbz 10,0x7(30); stb 0,-32768(31); addi 30,30,8; stb 9,-32768(31); stb 11,-32768(31); stb 10,-32768(31); lfs f0,0x8(29); lfs f13,0x4(29); stfs f0,-32768(31); addi 29,29,16; stfs f13,-32768(31); blt 1b; 2:; lwz 9,0x4d8(28); li 11,12; lwz 0,0x6cc(9); stw 11,0x0(9); oris 0,0,32768; stw 0,0x6cc(9); lwz 11,0x4d8(28); lwz 0,0x6cc(11); oris 0,0,32768; stw 0,0x6cc(11); 3:; lwz 9,0x4dc(28); addi 9,9,24; stw 9,0x4dc(28); lwz 0,0x4c(1); mtspr 8,0; lmw 25,0x2c(1); addi 1,1,72"

extern "C" void _s803454F8_0();
extern "C" void _s803454F8_1();
extern "C" void _s803454F8_2();
extern "C" void _s803454F8_3();
extern "C" void _s803454F8_4();

struct ENgcRenderer {
    void SpriteListPacked();
};

void ENgcRenderer::SpriteListPacked() {
}
