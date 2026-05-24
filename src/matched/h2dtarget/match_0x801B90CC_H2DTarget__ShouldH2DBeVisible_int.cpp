// 0x801B90CC H2DTarget::ShouldH2DBeVisible(int) (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32697; addi 9,9,23428; lwz 0,0x44(9); cmpwi 0,0; beq 3f; lwz 0,-21496(13); cmpwi 0,0; beq 3f; lwz 0,0x90(9); cmpwi 0,0; beq 3f; lwz 0,0x8c(9); cmpwi 0,0; beq 3f; lis 9,-32697; rlwinm 0,4,2,0,29; addi 9,9,24012; mr 3,0; addi 9,9,280; lwzx 4,9,0; cmpwi 4,0; beq 2f; lwz 0,0x160(4); li 9,0; cmpwi 0,0; beq 0f; cmpwi 0,8; beq 0f; li 9,1; 0:; cmpwi 9,0; beq 1f; lis 9,-32697; addi 9,9,24012; addi 9,9,280; lwzx 11,9,3; lwz 0,0x234(11); cmpwi 0,0; bne 3f; 1:; lis 9,-32697; addi 9,9,24012; addi 9,9,280; lwzx 3,9,3; cmpwi 3,0; beq 2f; bl _s801B90CC_0; cmpwi 3,0; bne 3f; 2:; lis 9,-32697; addi 9,9,24012; lwz 0,0x458(9); cmpwi 0,0; bne 3f; lwz 0,0x454(9); cmpwi 0,0; bne 3f; lis 9,-32697; lwz 11,0x5bc8(9); lbz 0,0x100(11); cmpwi 0,0; beq 4f; 3:; li 3,0; b 5f; 4:; li 3,1; 5:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s801B90CC_0();

struct H2DTarget {
    void ShouldH2DBeVisible();
};

void H2DTarget::ShouldH2DBeVisible() {
}
