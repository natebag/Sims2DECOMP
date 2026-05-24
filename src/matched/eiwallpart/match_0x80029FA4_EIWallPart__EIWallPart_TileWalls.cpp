// 0x80029FA4 EIWallPart::EIWallPart(TileWalls (816 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-152(1); mfspr 0,8; stmw 24,0x78(1); stw 0,0x9c(1); mr 31,3; mr 27,5; mr 26,6; mr 24,7; mr 25,4; bl _s80029FA4_0; addi 29,31,808; lis 9,-32698; mr 3,29; addi 9,9,-20160; li 30,0; stw 9,0x0(31); li 28,1; bl _s80029FA4_1; li 0,255; stw 30,0x68(31); stw 28,0x10(31); mr 3,29; stw 30,0x3a0(31); mr 4,24; stw 27,0x320(31); stw 26,0x324(31); stw 0,0x330(31); stw 0,0x32c(31); bl _s80029FA4_2; lis 9,-32707; stw 30,0x3ac(31); lwz 29,0xd38(9); mr 4,24; stw 28,0x10(31); mr 3,31; stw 30,0x350(31); mr 5,25; stw 29,0x58(1); mr 6,27; mr 7,26; addi 8,1,88; bl _s80029FA4_3; lwz 4,0x354(31); cmpwi 4,0; beq 6f; li 6,0; li 7,0; li 5,0; mr 3,31; bl _s80029FA4_4; mr 3,31; bl _s80029FA4_5; mr 4,27; mr 5,26; mr 3,25; bl _s80029FA4_6; bl _s80029FA4_7; mr. 3,3; beq 0f; mr 4,3; mr 3,31; bl _s80029FA4_8; 0:; mr 3,25; bl _s80029FA4_9; cmpwi 3,0; beq 1f; lis 9,-32707; stw 29,0x364(31); lfs f0,0xd3c(9); stw 29,0x368(31); stfs f0,0x35c(31); stfs f0,0x360(31); b 2f; 1:; lis 9,-32707; lis 11,-32707; lfs f0,0xd40(9); lfs f13,0xd44(11); stfs f0,0x360(31); stw 29,0x364(31); stfs f13,0x368(31); stw 29,0x35c(31); 2:; mr 3,25; bl _s80029FA4_10; cmpwi 3,0; beq 3f; lis 9,-32707; lis 11,-32707; lfs f0,0xd44(9); lfs f13,0xd48(11); stfs f0,0x378(31); stfs f13,0x374(31); stfs f0,0x36c(31); stfs f13,0x370(31); b 4f; 3:; lis 10,-32707; lis 9,-32707; lis 11,-32707; lfs f12,0xd4c(9); lfs f0,0xd44(10); lfs f13,0xd50(11); stfs f0,0x36c(31); stfs f13,0x374(31); stfs f12,0x378(31); stfs f12,0x370(31); 4:; addi 25,1,72; addi 3,1,8; bl _s80029FA4_11; lbz 0,0x1(24); lis 7,17200; lbz 9,0x0(24); extsb 0,0; mr 8,10; xoris 0,0,32768; extsb 9,9; stw 0,0x74(1); xoris 9,9,32768; lis 29,-32697; lis 11,-32707; stw 7,0x70(1); addi 29,29,24012; lfd f11,0xd58(11); lis 6,-32707; lfd f13,0x70(1); addi 30,1,8; stw 9,0x74(1); addi 26,1,80; lwz 9,0xc8(29); fsub f13,f13,f11; stw 7,0x70(1); frsp f13,f13; lfs f9,0x4c(9); addi 28,1,96; lfd f0,0x70(1); addi 27,1,104; lfs f12,0x50(9); mr 4,25; fsub f0,f0,f11; lfs f10,0xd38(6); frsp f0,f0; mr 3,30; fadds f13,f13,f12; fadds f0,f0,f9; stfs f13,0x48(1); stfs f0,0x4c(1); stfs f10,0x8(25); bl _s80029FA4_12; lfs f1,0x58(1); mr 3,30; bl _s80029FA4_13; mr 4,30; mr 3,31; bl _s80029FA4_14; mr 3,25; bl _s80029FA4_15; mr 3,26; bl _s80029FA4_16; mr 5,26; mr 3,31; mr 4,25; bl _s80029FA4_17; mr 3,28; mr 4,25; crxor 6,6,6; bl _s80029FA4_18; mr 3,27; mr 4,26; crxor 6,6,6; bl _s80029FA4_19; li 4,1; mr 3,28; bl _s80029FA4_20; sth 3,0x358(31); li 4,1; mr 3,27; bl _s80029FA4_21; lha 0,0x358(31); lis 9,-32765; addi 9,9,-25564; sth 3,0x35a(31); stw 0,0x28(31); mr 3,31; stw 9,0x1c(31); bl _s80029FA4_22; lwz 9,0xc8(29); li 5,1; lwz 0,0x3ac(31); lwz 3,0x1c(9); cmpwi 0,0; bne 5f; li 5,0; 5:; mr 4,31; bl _s80029FA4_23; mr 3,26; li 4,2; bl _s80029FA4_24; mr 3,25; li 4,2; bl _s80029FA4_25; 6:; mr 3,31; lwz 0,0x9c(1); mtspr 8,0; lmw 24,0x78(1); addi 1,1,152"

extern "C" void _s80029FA4_0();
extern "C" void _s80029FA4_1();
extern "C" void _s80029FA4_2();
extern "C" void _s80029FA4_3();
extern "C" void _s80029FA4_4();
extern "C" void _s80029FA4_5();
extern "C" void _s80029FA4_6();
extern "C" void _s80029FA4_7();
extern "C" void _s80029FA4_8();
extern "C" void _s80029FA4_9();
extern "C" void _s80029FA4_10();
extern "C" void _s80029FA4_11();
extern "C" void _s80029FA4_12();
extern "C" void _s80029FA4_13();
extern "C" void _s80029FA4_14();
extern "C" void _s80029FA4_15();
extern "C" void _s80029FA4_16();
extern "C" void _s80029FA4_17();
extern "C" void _s80029FA4_18();
extern "C" void _s80029FA4_19();
extern "C" void _s80029FA4_20();
extern "C" void _s80029FA4_21();
extern "C" void _s80029FA4_22();
extern "C" void _s80029FA4_23();
extern "C" void _s80029FA4_24();
extern "C" void _s80029FA4_25();

struct EIWallPart {
    void EIWallPart_TileWalls();
};

void EIWallPart::EIWallPart_TileWalls() {
}
