// 0x80316EE8 ERFont::GetLineSpacing(EWindow (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stw 31,0x44(1); stw 0,0x4c(1); mr 31,3; mr 11,4; mr. 0,5; beq 0f; lis 9,-32702; addi 8,1,40; lfs f0,0x764(9); li 0,0; stw 11,0x8(1); lis 4,-32702; stfs f0,0x4(8); addi 4,4,1840; stfs f0,0x28(1); stw 0,0x18(1); li 5,0; stw 0,0xc(1); li 6,0; stw 0,0x10(1); li 7,0; stw 0,0x14(1); li 9,0; addi 10,1,32; bl _s80316EE8_0; b 1f; 0:; lis 9,-32702; addi 8,1,40; lfs f0,0x764(9); lis 4,-32702; stw 11,0x8(1); addi 4,4,1840; stfs f0,0x4(8); mr 3,31; stfs f0,0x28(1); li 5,0; stw 0,0x18(1); li 6,0; stw 0,0xc(1); li 7,0; stw 0,0x10(1); li 9,0; stw 0,0x14(1); addi 10,1,32; bl _s80316EE8_1; 1:; lwz 0,0x30(31); lis 8,17200; lis 9,-32702; xoris 0,0,32768; lfd f12,0x770(9); stw 0,0x3c(1); lis 9,-32702; lfs f13,0x764(9); lis 11,-32702; stw 8,0x38(1); lfs f11,0x768(11); lfd f0,0x38(1); fsub f0,f0,f12; frsp f0,f0; fcmpu 0,f0,f13; ble 2f; fmr f11,f0; 2:; lwz 11,0x28(31); lwz 0,0x24(31); lfs f0,0x24(1); subf 0,11,0; xoris 0,0,32768; fmuls f0,f0,f11; stw 0,0x3c(1); stw 8,0x38(1); lfd f1,0x38(1); fsub f1,f1,f12; frsp f1,f1; fdivs f1,f0,f1; lwz 0,0x4c(1); mtspr 8,0; lwz 31,0x44(1); addi 1,1,72"

extern "C" void _s80316EE8_0();
extern "C" void _s80316EE8_1();

struct ERFont {
    void GetLineSpacing_EWindow();
};

void ERFont::GetLineSpacing_EWindow() {
}
