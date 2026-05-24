// 0x8004FC8C ISimsObjectModel::UpdateAnimController(void) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 31,0x1c(1); stw 0,0x24(1); lwz 0,-32048(13); mr 31,3; cmpwi 0,0; bne 1f; lwz 11,0x328(31); cmpwi 11,0; beq 1f; lwz 9,0x4(11); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,11,3; blrl; lha 0,0x12(3); cmpwi 0,12; bne 1f; lwz 0,-32344(13); li 9,1; cmpwi 0,0; bne 0f; li 9,0; 0:; cmpwi 9,0; bne 2f; 1:; lis 9,-32707; addi 11,1,8; lfs f0,0x3230(9); addi 3,31,820; mr 6,11; li 4,0; stfs f0,0x8(11); li 5,0; stfs f0,0x4(11); stfs f0,0x8(1); bl _s8004FC8C_0; 2:; lwz 0,0x24(1); mtspr 8,0; lwz 31,0x1c(1); addi 1,1,32"

extern "C" void _s8004FC8C_0();

struct ISimsObjectModel {
    void UpdateAnimController();
};

void ISimsObjectModel::UpdateAnimController() {
}
