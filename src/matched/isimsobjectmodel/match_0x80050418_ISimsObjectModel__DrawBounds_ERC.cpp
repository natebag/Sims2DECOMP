// 0x80050418 ISimsObjectModel::DrawBounds(ERC (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 30,4; mr 29,3; lwz 9,0x70(30); li 4,0; li 5,0; lwz 0,0x124(9); lha 3,0x120(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x70(30); lha 3,0xf0(9); lwz 0,0xf4(9); add 3,30,3; mtspr 8,0; blrl; lis 9,-32697; addi 11,1,8; lfs f12,0x6290(9); mr 3,30; addi 9,9,25232; addi 4,29,60; lfs f11,0xc(9); mr 5,11; lfs f13,0x4(9); lfs f0,0x8(9); stfs f12,0x8(1); stfs f13,0x4(11); stfs f0,0x8(11); stfs f11,0xc(11); bl _s80050418_0; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"

extern "C" void _s80050418_0();

struct ISimsObjectModel {
    void DrawBounds();
};

void ISimsObjectModel::DrawBounds() {
}
