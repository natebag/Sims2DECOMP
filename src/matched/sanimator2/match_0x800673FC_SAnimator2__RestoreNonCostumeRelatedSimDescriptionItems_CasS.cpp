// 0x800673FC SAnimator2::RestoreNonCostumeRelatedSimDescriptionItems(CasSimDescriptionS2C (420 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 0,0x0(5); addi 10,4,4; addi 9,5,4; li 11,48; sth 0,0x0(4); lbz 0,0x2(5); stb 0,0x2(4); 0:; lwz 0,0x0(9); addic. 11,11,-24; stw 0,0x0(10); lwz 0,0x4(9); stw 0,0x4(10); lwz 0,0x8(9); stw 0,0x8(10); lwz 0,0xc(9); stw 0,0xc(10); lwz 0,0x10(9); stw 0,0x10(10); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(10); addi 10,10,24; bne 0b; lwz 0,0x0(9); cmpwi 7,6,0; addi 8,4,68; addi 11,5,68; stw 0,0x0(10); li 7,48; lwz 0,0x4(9); addi 3,4,284; addi 6,5,284; stw 0,0x4(10); lwz 0,0x8(9); stw 0,0x8(10); lwz 0,0xc(9); stw 0,0xc(10); 1:; lwz 0,0x0(11); addic. 7,7,-24; stw 0,0x0(8); lwz 0,0x4(11); stw 0,0x4(8); lwz 0,0x8(11); stw 0,0x8(8); lwz 0,0xc(11); stw 0,0xc(8); lwz 0,0x10(11); stw 0,0x10(8); lwz 0,0x14(11); addi 11,11,24; stw 0,0x14(8); addi 8,8,24; bne 1b; lwz 0,0x0(11); stw 0,0x0(8); lwz 0,0x4(11); stw 0,0x4(8); lwz 0,0x8(11); stw 0,0x8(8); lwz 0,0xc(11); stw 0,0xc(8); lwz 0,0x84(5); stw 0,0x84(4); bne cr7,2f; lbz 0,0x88(5); stb 0,0x88(4); lbz 9,0x89(5); stb 9,0x89(4); lbz 0,0x8c(5); stb 0,0x8c(4); lbz 9,0x8d(5); stb 9,0x8d(4); lbz 0,0x8e(5); stb 0,0x8e(4); lwz 9,0x90(5); stw 9,0x90(4); lbz 0,0xd4(5); stb 0,0xd4(4); lhz 9,0xf2(5); lbz 0,0xf4(5); sth 9,0xf2(4); stb 0,0xf4(4); lfs f0,0xf8(5); stfs f0,0xf8(4); lfs f13,0xfc(5); stfs f13,0xfc(4); lfs f0,0x100(5); stfs f0,0x100(4); lfs f13,0x104(5); stfs f13,0x104(4); lfs f0,0x108(5); stfs f0,0x108(4); lfs f13,0x10c(5); stfs f13,0x10c(4); lfs f0,0x110(5); stfs f0,0x110(4); lfs f13,0x114(5); stfs f13,0x114(4); 2:; lwz 0,0x11c(5); lbz 9,0x4(6); stw 0,0x11c(4); stb 9,0x4(3); lbz 0,0x121(5); stb 0,0x121(4)"

struct SAnimator2 {
    void RestoreNonCostumeRelatedSimDescriptionItems_CasS();
};

void SAnimator2::RestoreNonCostumeRelatedSimDescriptionItems_CasS() {
}
