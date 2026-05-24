// 0x80299600 AptDisplayListState::insert(int, (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 25,3; mr 24,4; lwz 3,-23016(13); mr 27,6; mr 26,7; mr 29,5; li 4,100; li 28,0; bl _s80299600_0; mr 30,3; li 5,0; mr 4,29; bl _s80299600_1; lis 9,-32704; addi 3,30,12; addi 9,9,23568; stw 9,0x8(30); bl _s80299600_2; stw 27,0x4c(30); lis 9,-32704; lwz 0,0x5c(30); lis 11,-32704; lfs f13,0x74c0(9); mr 3,30; rlwinm 0,0,0,18,15; li 4,1; stfs f13,0x10(30); rlwimi 0,28,12,18,19; lfs f0,0x74c4(11); stw 0,0x5c(30); stw 28,0x48(30); sth 28,0x5c(30); stfs f13,0x34(30); stfs f0,0x44(30); stfs f0,0x14(30); stfs f0,0x18(30); stfs f13,0x1c(30); stfs f0,0x20(30); stfs f0,0x24(30); stfs f13,0x28(30); stfs f13,0x2c(30); stfs f13,0x30(30); stfs f0,0x38(30); stfs f0,0x3c(30); stfs f0,0x40(30); bl _s80299600_3; lwz 11,0x58(30); mr 3,25; lwz 0,0x5c(30); mr 4,26; lwz 9,0x0(30); ori 11,11,32766; ori 0,0,2048; rlwimi 11,24,15,0,16; rlwinm 0,0,0,22,20; rlwimi 9,28,26,5,5; stw 28,0x60(30); mr 5,30; stw 27,0x4c(30); stw 9,0x0(30); stw 0,0x5c(30); stw 11,0x58(30); bl _s80299600_4; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"

extern "C" void _s80299600_0();
extern "C" void _s80299600_1();
extern "C" void _s80299600_2();
extern "C" void _s80299600_3();
extern "C" void _s80299600_4();

struct AptDisplayListState {
    void insert();
};

void AptDisplayListState::insert() {
}
