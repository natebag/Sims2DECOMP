// 0x80031F94 ESim::DrawPlumbBob(ERC (524 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f31,0x28(1); stmw 29,0x1c(1); stw 0,0x34(1); mr 31,3; bl _s80031F94_0; mr. 30,3; bne 9f; mr 3,31; bl _s80031F94_1; mr 4,3; addi 3,31,968; bl _s80031F94_2; mr. 29,3; beq 9f; lwz 0,0x3ec(31); lis 10,-32707; lfs f31,0x1138(10); cmplwi 0,3; blt 7f; cmplwi 0,4; ble 0f; cmpwi 0,7; beq 4f; b 7f; 0:; lis 9,-32707; lfs f0,0x3f4(31); lfs f13,0x113c(9); fcmpu 0,f0,f13; bge 1f; fdivs f0,f0,f13; fsubs f31,f31,f0; b 7f; 1:; lis 4,20474; mr 3,29; ori 4,4,64824; bl _s80031F94_3; mr 3,29; li 4,0; bl _s80031F94_4; lwz 3,0x3e8(31); cmpwi 3,0; beq 2f; bl _s80031F94_5; stw 30,0x3e8(31); 2:; lis 3,-32692; lis 4,20474; addi 3,3,-27556; ori 4,4,64824; li 5,0; li 6,0; bl _s80031F94_6; lwz 0,0x3ec(31); li 11,9; stw 3,0x3e8(31); cmpwi 0,3; bne 3f; li 11,8; 3:; lis 9,-32707; stw 11,0x3ec(31); lfs f0,0x1140(9); stfs f0,0x3f4(31); b 9f; 4:; lis 9,-32707; lfs f11,0x3f4(31); lfs f13,0x1144(9); fcmpu 0,f11,f13; bge 5f; lis 9,-32707; lfs f0,0x1148(9); fmuls f0,f11,f0; fdivs f31,f0,f13; b 7f; 5:; lis 9,-32707; lfs f0,0x113c(9); fcmpu 0,f11,f0; bge 6f; lis 9,-32707; fsubs f11,f11,f13; lfs f0,0x114c(9); lis 11,-32707; lfs f12,0x1138(10); fdivs f31,f11,f0; lfs f13,0x1150(11); fsubs f0,f12,f31; fmadds f31,f0,f13,f12; b 7f; 6:; stw 30,0x3ec(31); 7:; lis 9,-32697; lwz 11,0x3d0(31); addi 9,9,24012; lwz 0,0xbc(9); cmpw 0,11; beq 8f; lwz 0,0xc0(9); cmpw 0,11; bne 9f; 8:; lwz 9,0x4(11); lwz 0,0x18c(9); lha 3,0x188(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(3); li 4,1; addi 5,1,8; lha 0,0xe0(9); lwz 9,0xe4(9); add 3,3,0; mtspr 8,9; blrl; mr 3,29; li 4,1; bl _s80031F94_7; lwz 8,0x8(1); addi 9,1,8; lwz 10,0x8(9); addi 11,29,296; lwz 0,0x4(9); stw 8,0x128(29); stw 10,0x8(11); stw 0,0x4(11); lwz 9,0x164(29); stfs f31,0x4(9); 9:; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x1c(1); lfd f31,0x28(1); addi 1,1,48"

extern "C" void _s80031F94_0();
extern "C" void _s80031F94_1();
extern "C" void _s80031F94_2();
extern "C" void _s80031F94_3();
extern "C" void _s80031F94_4();
extern "C" void _s80031F94_5();
extern "C" void _s80031F94_6();
extern "C" void _s80031F94_7();

struct ESim {
    void DrawPlumbBob();
};

void ESim::DrawPlumbBob() {
}
