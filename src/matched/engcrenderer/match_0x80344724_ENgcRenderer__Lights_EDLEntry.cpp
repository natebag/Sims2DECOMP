// 0x80344724 ENgcRenderer::Lights(EDLEntry (400 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); lbz 0,0x1(4); stb 0,0x768(3); lbz 9,0x2(4); stb 9,0x769(3); lwz 0,0x4(4); cmpwi 0,0; beq 5f; addi 9,3,1616; mr 11,0; mr 8,9; li 10,240; 0:; lwz 0,0x0(11); addic. 10,10,-24; stw 0,0x0(9); lwz 0,0x4(11); stw 0,0x4(9); lwz 0,0x8(11); stw 0,0x8(9); lwz 0,0xc(11); stw 0,0xc(9); lwz 0,0x10(11); stw 0,0x10(9); lwz 0,0x14(11); addi 11,11,24; stw 0,0x14(9); addi 9,9,24; bne 0b; lwz 0,0x0(11); li 10,0; stw 0,0x0(9); lwz 0,0x4(11); stw 0,0x4(9); lbz 0,0x768(3); cmpw 10,0; bge 2f; lfs f11,-26164(13); addi 9,3,1632; 1:; lfs f0,0x0(9); addi 10,10,1; lfs f13,0x4(9); lfs f12,0x8(9); fmuls f0,f0,f11; fmuls f13,f13,f11; stfs f0,0x0(9); fmuls f12,f12,f11; stfs f13,0x4(9); stfs f12,0x8(9); addi 9,9,24; lbz 0,0x768(3); cmpw 10,0; blt 1b; 2:; lbz 0,0x769(3); li 10,0; cmpw 10,0; bge 4f; lfs f11,-26164(13); addi 9,3,1744; 3:; lfs f0,0x0(9); addi 10,10,1; lfs f13,0x4(9); lfs f12,0x8(9); fmuls f0,f0,f11; fmuls f13,f13,f11; stfs f0,0x0(9); fmuls f12,f12,f11; stfs f13,0x4(9); stfs f12,0x8(9); addi 9,9,32; lbz 0,0x769(3); cmpw 10,0; blt 3b; 4:; lfs f12,-26164(13); lfs f0,0x650(3); fmuls f0,f0,f12; stfs f0,0x650(3); lfs f13,0x4(8); lfs f0,0x8(8); fmuls f13,f13,f12; fmuls f0,f0,f12; stfs f13,0x4(8); stfs f0,0x8(8); b 6f; 5:; lis 11,-32702; addi 9,1,8; lfs f0,0x1de4(11); addi 8,3,1616; stfs f0,0x8(9); stfs f0,0x4(9); stfs f0,0x8(1); lwz 0,0x8(1); lwz 11,0x8(9); lwz 10,0x4(9); stw 0,0x650(3); stw 11,0x8(8); stw 10,0x4(8); 6:; li 0,1; stw 0,0x510(3); addi 1,1,24"

struct ENgcRenderer {
    void Lights_EDLEntry();
};

void ENgcRenderer::Lights_EDLEntry() {
}
