// 0x80316280 ERFont::DoGetStringSize(void (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stw 31,0x34(1); stw 0,0x3c(1); mr 31,3; mr 11,8; mr 3,4; mr. 0,7; mr 4,5; mr 5,6; beq 0f; lis 9,-32702; addi 8,1,40; lfs f0,0x710(9); li 0,0; stw 11,0x8(1); li 6,0; stfs f0,0x4(8); li 7,0; stfs f0,0x28(1); li 9,0; stw 0,0x18(1); addi 10,1,32; stw 0,0xc(1); stw 0,0x10(1); stw 0,0x14(1); bl _s80316280_0; b 1f; 0:; lis 9,-32702; addi 8,1,40; lfs f0,0x710(9); li 6,0; stw 11,0x8(1); li 7,0; stfs f0,0x4(8); li 9,0; stfs f0,0x28(1); addi 10,1,32; stw 0,0x18(1); stw 0,0xc(1); stw 0,0x10(1); stw 0,0x14(1); bl _s80316280_1; 1:; lfs f13,0x20(1); mr 3,31; lfs f0,0x24(1); stfs f13,0x0(31); stfs f0,0x4(31); lwz 0,0x3c(1); mtspr 8,0; lwz 31,0x34(1); addi 1,1,56"
extern "C" void _s80316280_0();
extern "C" void _s80316280_1();
extern "C" void f_80316280() {}
