// 0x8006F408 SimImageMaker::PoseSim(ERC (304 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-136(1); mfspr 0,8; stmw 28,0x78(1); stw 0,0x8c(1); mr 29,3; mr 28,4; lwz 0,0x88(29); addi 31,29,16; li 11,0; cmpwi 0,0; beq 0f; li 11,4; 0:; addi 9,13,-21272; mr 3,31; lwzx 4,11,9; li 5,5; li 6,0; li 30,-1; bl _s8006F408_0; lis 9,-32707; lwz 5,0x218(29); lfs f1,0x5320(9); li 7,0; li 4,1; li 6,-1; mr 3,31; bl _s8006F408_1; lis 11,-32707; addi 3,1,72; lfs f0,0x5328(11); lis 9,-32707; lfs f12,0x532c(9); addi 11,1,88; stfs f0,0x48(1); lis 10,-32707; stfs f0,0x4(3); addi 9,1,104; stfs f0,0x8(3); mr 4,11; stfs f0,0x58(1); mr 5,9; stfs f0,0x8(11); addi 6,1,8; stfs f0,0x4(11); lfs f13,0x5324(10); stfs f12,0x68(1); stfs f13,0x58(31); stfs f12,0x8(9); stfs f12,0x4(9); bl _s8006F408_2; lwz 5,-26812(13); mr 3,31; stw 30,0x34(31); addi 4,1,8; stw 30,0x30(31); bl _s8006F408_3; stw 30,0x30(31); stw 30,0x34(31); lwz 5,0x34(29); cmpwi 5,0; beq 1f; lwz 5,0x18(5); b 2f; 1:; li 5,0; 2:; lwz 9,0x70(28); lwz 4,0x20(29); lha 3,0xd8(9); lwz 0,0xdc(9); add 3,28,3; mtspr 8,0; blrl; lwz 0,0x8c(1); mtspr 8,0; lmw 28,0x78(1); addi 1,1,136"

extern "C" void _s8006F408_0();
extern "C" void _s8006F408_1();
extern "C" void _s8006F408_2();
extern "C" void _s8006F408_3();

struct SimImageMaker {
    void PoseSim();
};

void SimImageMaker::PoseSim() {
}
