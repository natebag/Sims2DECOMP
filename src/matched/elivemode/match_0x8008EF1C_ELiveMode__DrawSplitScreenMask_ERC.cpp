// 0x8008EF1C ELiveMode::DrawSplitScreenMask(ERC (668 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-120(1); mfspr 0,8; stmw 29,0x6c(1); stw 0,0x7c(1); lis 30,-32697; mr 29,6; addi 30,30,24012; rlwinm 0,29,2,0,29; addi 9,30,280; mr 31,4; lwzx 4,9,0; mr 3,30; bl _s8008EF1C_0; lis 9,-32697; rlwinm 11,29,4,0,27; addi 9,9,23428; mr 3,30; add 11,11,9; lwz 4,0x100(11); bl _s8008EF1C_1; lwz 9,0xfc(30); lwz 3,0x14(9); cmpwi 3,0; beq 0f; mr 11,3; b 1f; 0:; lwz 9,0x18(9); li 11,0; cmpwi 9,0; beq 1f; lwz 11,0x14(9); 1:; lwz 9,0xf0(11); mr 4,31; li 5,0; addi 30,1,48; lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x70(31); li 7,0; li 4,1; li 5,1; lwz 0,0x1cc(9); li 6,0; lha 3,0x1c8(9); mtspr 8,0; add 3,31,3; blrl; lwz 11,0x70(31); lis 9,-32707; lfs f1,0x7e3c(9); li 6,0; lwz 0,0x1d4(11); li 4,0; lha 3,0x1d0(11); li 5,5; mtspr 8,0; add 3,31,3; blrl; lwz 9,0x70(31); li 4,1; li 5,0; lwz 0,0x204(9); lha 3,0x200(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x70(31); li 4,64; li 5,0; lwz 0,0x154(9); lha 3,0x150(9); mtspr 8,0; add 3,31,3; blrl; li 0,3; mtspr 9,0; 2:; bdnz 2b; li 0,3; mtspr 9,0; 3:; bdnz 3b; xoris 0,29,32768; stw 0,0x64(1); lis 11,17200; lis 10,-32707; lis 8,-32707; stw 11,0x60(1); lis 7,-32707; lfd f11,0x7e48(10); li 4,2; lfd f0,0x60(1); li 5,0; lfs f13,0x7e40(8); li 6,0; fsub f0,f0,f11; lfs f12,0x7e50(7); frsp f0,f0; stfs f13,0x48(1); fsubs f11,f13,f0; stfs f12,0x4c(1); stfs f11,0x50(1); stfs f13,0x8(1); stfs f13,0xc(1); stfs f0,0x10(1); stfs f12,0x14(1); stfs f13,0x18(1); stfs f0,0x1c(1); stfs f12,0x20(1); stfs f12,0x24(1); stfs f0,0x28(1); stfs f13,0x30(1); stfs f13,0x34(1); stfs f11,0x38(1); stfs f12,0x3c(1); stfs f12,0x40(1); stfs f11,0x44(1); lwz 9,0x70(31); lwz 0,0x1dc(9); lha 3,0x1d8(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x70(31); addi 5,1,8; li 7,0; li 4,3; lwz 0,0x324(9); li 6,0; lha 3,0x320(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x70(31); li 4,2; li 5,0; li 6,0; lwz 0,0x1dc(9); lha 3,0x1d8(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x70(31); mr 5,30; li 4,3; li 6,0; lwz 0,0x324(9); li 7,0; lha 3,0x320(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x70(31); li 4,0; li 5,0; li 6,0; lha 3,0x1d8(9); lwz 0,0x1dc(9); add 3,31,3; mtspr 8,0; blrl; lwz 0,0x7c(1); mtspr 8,0; lmw 29,0x6c(1); addi 1,1,120"

extern "C" void _s8008EF1C_0();
extern "C" void _s8008EF1C_1();

struct ELiveMode {
    void DrawSplitScreenMask();
};

void ELiveMode::DrawSplitScreenMask() {
}
