// 0x80316588 ERFont::DoDrawAlign(ERC (676 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-136(1); mfspr 0,8; mfcr 12; stmw 17,0x4c(1); stw 0,0x8c(1); stw 12,0x48(1); li 0,0; xoris 0,0,32768; lis 29,17200; stw 0,0x44(1); lis 11,-32702; lfd f13,0x738(11); addi 31,1,32; stw 29,0x40(1); mr 26,8; addi 0,26,-1; mr 27,3; lfd f0,0x40(1); mr 20,4; mr 24,5; mr 23,6; fsub f0,f0,f13; mr 28,7; frsp f0,f0; mr 25,9; stfs f0,0x20(1); mr 21,10; stfs f0,0x4(31); cmplwi 0,1; lwz 19,0x90(1); lwz 18,0x94(1); lwz 17,0x98(1); lwz 22,0x9c(1); bgt 0f; addi 30,1,40; mr 4,27; mr 3,30; b 1f; 0:; addi 0,25,-1; cmplwi 0,1; bgt 2f; addi 30,1,40; lis 5,-32702; addi 5,5,1840; mr 3,30; mr 4,27; li 6,0; 1:; mr 7,22; li 8,0; bl _s80316588_0; lwz 0,0x28(1); lwz 9,0x4(30); stw 0,0x20(1); stw 9,0x4(31); 2:; lwz 9,0x54(27); lwz 0,0xc(9); cmpwi 0,1; bne 5f; cmpwi 26,1; cmpwi 7,25,1; mfcr 29; rlwinm 29,29,3,31,31; mfcr 30; mcrf cr4,cr7; mfcr 31; rlwinm 31,31,31,31,31; cmpwi 3,22,0; beq cr3,3f; mr 3,27; mr 4,28; mr 5,29; mr 6,31; li 7,0; bl _s80316588_1; b 4f; 3:; mr 3,27; mr 4,28; mr 5,29; mr 6,31; li 7,0; bl _s80316588_2; 4:; xori 29,29,1; xori 31,31,1; b 6f; 5:; cmpwi 26,1; li 31,0; li 29,0; mfcr 30; cmpwi 4,25,1; cmpwi 3,22,0; 6:; mtcrf 128,30; beq 10f; bgt 7f; cmpwi 26,0; beq 8f; b 13f; 7:; cmpwi 26,2; beq 9f; b 13f; 8:; lfs f0,0x0(28); b 12f; 9:; lis 9,-32702; lfs f13,0x20(1); lfs f12,0x740(9); lfs f0,0x0(28); fmuls f13,f13,f12; b 11f; 10:; lfs f0,0x0(28); lfs f13,0x20(1); 11:; fsubs f0,f0,f13; 12:; stfs f0,0x30(1); 13:; beq cr4,17f; bgt cr4,14f; cmpwi 25,0; beq 15f; b 20f; 14:; cmpwi 25,2; beq 16f; b 20f; 15:; lfs f0,0x4(28); b 19f; 16:; lis 9,-32702; lfs f13,0x24(1); lfs f12,0x740(9); lfs f0,0x4(28); fmuls f13,f13,f12; b 18f; 17:; lfs f0,0x4(28); lfs f13,0x24(1); 18:; fsubs f0,f0,f13; 19:; stfs f0,0x34(1); 20:; beq cr3,21f; li 0,0; stw 19,0xc(1); stw 0,0x8(1); mr 3,27; stw 28,0x10(1); mr 4,24; stw 18,0x14(1); mr 5,23; stw 17,0x18(1); mr 6,29; mr 7,31; mr 9,20; mr 10,21; addi 8,1,48; bl _s80316588_3; b 22f; 21:; stw 22,0x8(1); mr 3,27; stw 19,0xc(1); mr 4,24; stw 28,0x10(1); mr 5,23; stw 18,0x14(1); mr 6,29; stw 17,0x18(1); mr 7,31; mr 9,20; mr 10,21; addi 8,1,48; bl _s80316588_4; 22:; lwz 0,0x8c(1); lwz 12,0x48(1); mtspr 8,0; lmw 17,0x4c(1); mtcrf 24,12; addi 1,1,136"

extern "C" void _s80316588_0();
extern "C" void _s80316588_1();
extern "C" void _s80316588_2();
extern "C" void _s80316588_3();
extern "C" void _s80316588_4();

struct ERFont {
    void DoDrawAlign();
};

void ERFont::DoDrawAlign() {
}
