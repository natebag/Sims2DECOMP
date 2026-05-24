// 0x8002CE4C ERoomWall::DrawWall(ERC (940 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stfd f30,0x58(1); stfd f31,0x60(1); stmw 26,0x40(1); stw 0,0x6c(1); mr 29,3; mr 27,4; addi 3,1,8; mr 4,29; bl _s8002CE4C_0; addi 30,1,24; addi 4,29,3; mr 3,30; bl _s8002CE4C_1; lwz 3,0x20(29); mr 6,30; lwz 4,0x24(29); addi 5,1,8; bl _s8002CE4C_2; addi 9,1,8; lfs f13,0x8(1); lfs f12,0x8(9); addi 3,1,40; lfs f0,0x4(9); lfs f11,0x18(1); lfs f10,0x1c(1); lfs f9,0x20(1); fsubs f13,f13,f11; fsubs f0,f0,f10; stfs f13,0x28(1); fsubs f12,f12,f9; stfs f0,0x2c(1); stfs f12,0x30(1); bl _s8002CE4C_3; fctiwz f0,f1; stfd f0,0x38(1); lwz 26,0x3c(1); cmpwi 26,1; bge 0f; li 26,1; 0:; mr 3,27; li 4,320; li 5,32; bl _s8002CE4C_4; lwz 0,0x20(29); mr 31,3; cmpwi 0,4; beq 4f; bgt 1f; cmpwi 0,1; beq 5f; cmpwi 0,2; beq 6f; b 17f; 1:; cmpwi 0,16; beq 12f; bgt 2f; cmpwi 0,8; beq 3f; b 17f; 2:; cmpwi 0,32; beq 8f; b 17f; 3:; li 9,0; li 0,128; b 11f; 4:; li 9,0; li 0,128; b 9f; 5:; li 9,0; li 0,128; b 7f; 6:; li 9,128; li 0,0; 7:; stw 9,0x34(31); stw 0,0x38(31); stw 9,0x30(31); b 14f; 8:; lwz 0,0x24(29); cmpwi 0,1; bne 10f; li 9,128; li 0,0; 9:; stw 0,0x34(31); stw 9,0x38(31); stw 9,0x30(31); b 14f; 10:; li 9,128; li 0,0; 11:; stw 0,0x30(31); stw 9,0x38(31); stw 9,0x34(31); b 14f; 12:; lwz 0,0x24(29); cmpwi 0,2; li 0,128; bne 13f; li 0,0; 13:; stw 0,0x38(31); stw 0,0x30(31); stw 0,0x34(31); 14:; li 9,127; li 11,0; li 0,68; stw 9,0x14(31); stw 0,0x3c(31); lis 10,-32707; stw 11,0x1c(31); lis 9,-32707; stw 11,0x10(31); addi 30,31,80; stw 11,0x18(31); mr 4,31; lfs f31,0xdfc(9); mr 3,30; lfs f30,0xdf8(10); addi 29,31,160; lfs f13,0x8(1); addi 28,31,240; lfs f0,0xc(1); stfs f30,0x8(31); stfs f31,0xc(31); stfs f13,0x0(31); stfs f0,0x4(31); bl _s8002CE4C_5; lfs f0,0x18(1); mr 4,31; lfs f13,0x1c(1); mr 3,29; stfs f0,0x50(31); stfs f30,0x8(30); stfs f31,0xc(30); stfs f13,0x4(30); bl _s8002CE4C_6; lfs f13,0x8(1); lis 9,-32707; lfs f0,0xc(1); mr 4,31; lfs f30,0xe00(9); mr 3,28; stfs f13,0xa0(31); stfs f31,0xc(29); stfs f30,0x8(29); stfs f0,0x4(29); bl _s8002CE4C_7; neg 0,26; xoris 0,0,32768; lis 10,17200; stw 0,0x3c(1); lis 8,-32707; lfs f11,0x18(1); lis 6,-32707; stw 10,0x38(1); addi 11,31,32; lfd f0,0xe08(8); addi 10,31,112; lfd f13,0x38(1); addi 8,31,192; lfs f12,0x1c(1); addi 7,31,272; stfs f11,0xf0(31); fsub f13,f13,f0; stfs f12,0x4(28); frsp f13,f13; stfs f30,0x8(28); stfs f31,0xc(28); lfs f0,0xe10(6); stfs f31,0x20(31); stfs f0,0xc(11); stfs f13,0x4(11); stfs f0,0x8(11); stfs f31,0x70(31); stfs f0,0xc(10); stfs f0,0x4(10); stfs f0,0x8(10); stfs f0,0xc0(31); stfs f13,0x4(8); stfs f0,0xc(8); stfs f0,0x8(8); stfs f0,0x110(31); stfs f0,0xc(7); stfs f0,0x4(7); stfs f0,0x8(7); lwz 9,0x70(27); lha 3,0xf0(9); lwz 0,0xf4(9); add 3,27,3; mtspr 8,0; blrl; lis 9,-32697; lwz 9,0x5ec8(9); lwz 3,0x14(9); cmpwi 3,0; beq 15f; mr 11,3; b 16f; 15:; lwz 9,0x18(9); li 11,0; cmpwi 9,0; beq 16f; lwz 11,0x14(9); 16:; lwz 9,0xf0(11); mr 4,27; li 5,0; lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x70(27); li 4,1; li 5,2; li 7,0; lwz 0,0x1cc(9); li 6,0; lha 3,0x1c8(9); mtspr 8,0; add 3,27,3; blrl; lwz 9,0x70(27); mr 4,31; li 5,4; lha 3,0x18(9); lwz 0,0x1c(9); add 3,27,3; mtspr 8,0; blrl; 17:; lwz 0,0x6c(1); mtspr 8,0; lmw 26,0x40(1); lfd f30,0x58(1); lfd f31,0x60(1); addi 1,1,104"

extern "C" void _s8002CE4C_0();
extern "C" void _s8002CE4C_1();
extern "C" void _s8002CE4C_2();
extern "C" void _s8002CE4C_3();
extern "C" void _s8002CE4C_4();
extern "C" void _s8002CE4C_5();
extern "C" void _s8002CE4C_6();
extern "C" void _s8002CE4C_7();

struct ERoomWall {
    void DrawWall();
};

void ERoomWall::DrawWall() {
}
