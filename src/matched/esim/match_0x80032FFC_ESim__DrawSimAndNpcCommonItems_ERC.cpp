// 0x80032FFC ESim::DrawSimAndNpcCommonItems(ERC (384 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 30,0x48(1); stw 0,0x54(1); mr 31,3; mr 30,4; lwz 0,0x42c(31); cmpwi 0,0; beq 0f; lwz 0,0x430(31); cmpwi 0,0; beq 0f; lwz 9,0x0(31); addi 4,1,8; lwz 0,0x114(9); lha 3,0x110(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x42c(31); addi 3,1,8; lfs f1,0x88(9); bl _s80032FFC_0; lis 9,-32707; lis 11,-32707; lfs f0,0x438(31); addi 4,1,8; lfs f13,0x119c(9); li 5,1; lfs f12,0x11a0(11); lis 9,-32707; fmuls f13,f0,f13; lfs f9,0x1198(9); fmuls f12,f0,f12; lis 11,-32707; fmuls f13,f13,f0; lfs f10,0x1194(11); fmuls f12,f12,f0; lfs f11,0x40(1); fmadds f13,f13,f0,f12; lwz 9,0x70(30); fmadds f0,f0,f9,f13; fadds f0,f0,f0; fsubs f0,f0,f10; fadds f11,f11,f0; stfs f11,0x40(1); lha 3,0xe8(9); lwz 0,0xec(9); add 3,30,3; mtspr 8,0; blrl; lwz 3,0x42c(31); mr 4,30; bl _s80032FFC_1; 0:; lis 9,-32697; li 10,0; addi 9,9,24012; lwz 0,0xcc(9); cmpwi 0,0; bne 1f; lwz 0,0x32c(31); cmpwi 0,1; bne 1f; lwz 9,0x118(9); lwz 0,0x160(9); xori 0,0,8; subfic 9,0,0; adde 0,9,0; xori 10,0,1; 1:; lis 9,-32697; li 11,0; addi 9,9,24012; lwz 0,0xcc(9); cmpwi 0,1; bne 2f; lwz 0,0x32c(31); cmpwi 0,8; bne 2f; lwz 9,0x11c(9); lwz 0,0x160(9); xori 0,0,8; subfic 9,0,0; adde 0,9,0; xori 11,0,1; 2:; cmpwi 10,0; bne 3f; cmpwi 11,0; beq 4f; 3:; mr 3,31; mr 4,30; bl _s80032FFC_2; 4:; lwz 0,0x54(1); mtspr 8,0; lmw 30,0x48(1); addi 1,1,80"

extern "C" void _s80032FFC_0();
extern "C" void _s80032FFC_1();
extern "C" void _s80032FFC_2();

struct ESim {
    void DrawSimAndNpcCommonItems();
};

void ESim::DrawSimAndNpcCommonItems() {
}
