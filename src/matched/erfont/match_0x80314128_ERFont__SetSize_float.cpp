// 0x80314128 ERFont::SetSize(float, (368 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lis 9,-32702; lfs f13,-22636(13); lfs f12,0x6c0(9); lfs f0,-22640(13); fmuls f1,f1,f13; fcmpu 0,f0,f12; beq 0f; fdivs f0,f13,f0; fmuls f2,f2,f0; 0:; cmpwi 4,0; beq 6f; lwz 5,0x18(3); fmr f10,f12; li 4,0; cmpwi 5,0; beq 5f; lwz 6,0x0(5); lis 11,17200; lis 9,-32702; lwz 0,0x4(6); lfd f13,0x6c8(9); xoris 0,0,32768; stw 0,0xc(1); stw 11,0x8(1); lfd f0,0x8(1); fsub f0,f0,f13; frsp f0,f0; fsubs f11,f0,f1; fcmpu 0,f11,f10; bne 1f; mr 4,6; b 5f; 1:; cmpwi 4,0; beq 3f; lis 9,-32702; lfs f12,0x6c0(9); fcmpu 0,f11,f12; bge 2f; fcmpu 0,f11,f10; ble 4f; b 3f; 2:; fabs f13,f11; fabs f0,f10; fcmpu 0,f13,f0; blt 3f; fcmpu 0,f10,f12; bge 4f; lwz 0,0x4(6); lis 10,17200; lis 9,-32702; xoris 0,0,32768; lfd f13,0x6c8(9); stw 0,0xc(1); lis 9,-32702; lfs f12,0x6d0(9); stw 10,0x8(1); lfd f0,0x8(1); fsub f0,f0,f13; frsp f0,f0; fdivs f0,f0,f1; fcmpu 0,f0,f12; cror 3,2,0; bns 4f; 3:; fmr f10,f11; mr 4,6; 4:; lwz 5,0x8(5); cmpwi 5,0; beq 5f; lwz 7,0x0(5); lis 10,17200; lis 9,-32702; lwz 0,0x4(7); lis 11,-32702; lfd f13,0x6c8(9); mr 6,7; xoris 0,0,32768; lfs f12,0x6c0(11); stw 0,0xc(1); stw 10,0x8(1); lfd f0,0x8(1); fsub f0,f0,f13; frsp f0,f0; fsubs f11,f0,f1; fcmpu 0,f11,f12; bne 1b; mr 4,7; 5:; stw 4,0x54(3); 6:; stfs f2,0x50(3); stfs f1,0x4c(3); addi 1,1,16"

struct ERFont {
    void SetSize();
};

void ERFont::SetSize() {
}
