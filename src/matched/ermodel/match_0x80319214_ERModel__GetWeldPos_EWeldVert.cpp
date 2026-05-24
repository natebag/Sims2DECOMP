// 0x80319214 ERModel::GetWeldPos(EWeldVert (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lwz 0,0x18(4); cmpwi 0,0; beq 0f; lwz 9,0x0(5); lis 6,17200; mr 7,8; lha 0,0x0(9); lis 4,-32702; lha 11,0x2(9); mr 5,8; xoris 0,0,32768; lha 10,0x4(9); stw 0,0xc(1); xoris 11,11,32768; lfd f12,0x8b0(4); xoris 10,10,32768; stw 6,0x8(1); lfd f0,0x8(1); stw 11,0xc(1); fsub f0,f0,f12; stw 6,0x8(1); frsp f0,f0; stfs f0,0x0(3); lfd f13,0x8(1); stw 10,0xc(1); fsub f13,f13,f12; stw 6,0x8(1); frsp f13,f13; stfs f13,0x4(3); lfd f0,0x8(1); fsub f0,f0,f12; frsp f0,f0; b 1f; 0:; lwz 9,0x0(5); lfs f0,0x0(9); stfs f0,0x0(3); lfs f13,0x4(9); stfs f13,0x4(3); lfs f0,0x8(9); 1:; stfs f0,0x8(3); addi 1,1,16"

struct ERModel {
    void GetWeldPos_EWeldVert();
};

void ERModel::GetWeldPos_EWeldVert() {
}
