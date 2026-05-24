// 0x800CA99C Neighbor::InitDefaultValues(void) (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s800CA99C_0; lis 9,-32706; li 0,0; lfs f0,-22820(9); mr 4,30; sth 0,0xee(30); stfs f0,0x150(30); stfs f0,0x110(30); sth 0,0x82(30); sth 0,0x84(30); sth 0,0x86(30); sth 0,0x88(30); sth 0,0x8a(30); sth 0,0x8c(30); sth 0,0x8e(30); sth 0,0x90(30); sth 0,0x92(30); sth 0,0x94(30); sth 0,0xa0(30); sth 0,0xe0(30); sth 0,0xe2(30); lwz 11,-21476(13); lwz 9,0x0(11); lwz 0,0x104(9); lha 3,0x100(9); mtspr 8,0; add 3,11,3; blrl; lhz 0,0x104(30); ori 0,0,96; sth 0,0x104(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s800CA99C_0();

struct Neighbor {
    void InitDefaultValues();
};

void Neighbor::InitDefaultValues() {
}
