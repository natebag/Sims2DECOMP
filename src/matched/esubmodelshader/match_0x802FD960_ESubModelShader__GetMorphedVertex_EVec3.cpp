// 0x802FD960 ESubModelShader::GetMorphedVertex(EVec3 (332 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); lwz 0,0x30(3); mr 12,4; cmpwi 0,0; beq 0f; extsh 0,0; cmpw 5,0; bge 0f; mulli 5,5,52; lwz 8,0x2c(3); add 9,8,5; lha 0,0x1a(9); cmpw 6,0; blt 1f; 0:; li 3,0; b 4f; 1:; lwz 0,0x10(3); andi. 9,0,16; beq 2f; lwzx 9,8,5; rlwinm 11,6,3,0,28; lis 3,17200; lhax 0,9,11; mr 5,8; add 9,9,11; mr 4,8; xoris 0,0,32768; lha 10,0x2(9); stw 0,0x1c(1); lis 11,-32702; xoris 10,10,32768; lha 6,0x4(9); stw 3,0x18(1); lis 9,-32702; lfd f12,-2512(9); xoris 6,6,32768; lfd f0,0x18(1); addi 7,1,8; stw 10,0x1c(1); lfs f11,-2504(11); fsub f0,f0,f12; stw 3,0x18(1); frsp f0,f0; fmuls f0,f0,f11; lfd f13,0x18(1); stw 6,0x1c(1); stfs f0,0x8(1); fsub f13,f13,f12; stw 3,0x18(1); frsp f13,f13; fmuls f13,f13,f11; lfd f0,0x18(1); stfs f13,0x4(7); fsub f0,f0,f12; frsp f0,f0; lwz 9,0x4(7); fmuls f0,f0,f11; stfs f0,0x8(7); stw 9,0x4(12); lwz 9,0x8(1); lwz 0,0x8(7); stw 9,0x0(12); stw 0,0x8(12); b 3f; 2:; lwzx 9,8,5; rlwinm 10,6,4,0,27; addi 11,1,8; lfsx f13,9,10; add 9,9,10; lfs f12,0x8(9); lfs f0,0x4(9); stfs f13,0x8(1); stfs f0,0x4(11); stfs f12,0x8(11); lwz 10,0x4(11); lwz 0,0x8(11); lwz 9,0x8(1); stw 0,0x8(12); stw 9,0x0(12); stw 10,0x4(12); 3:; li 3,1; 4:; addi 1,1,32"

struct ESubModelShader {
    void GetMorphedVertex();
};

void ESubModelShader::GetMorphedVertex() {
}
