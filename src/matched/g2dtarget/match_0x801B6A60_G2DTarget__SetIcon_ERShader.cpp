// 0x801B6A60 G2DTarget::SetIcon(ERShader (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 11,5; mr. 5,4; beq 1f; lwz 0,0x14(5); cmpwi 0,0; bne 0f; lwz 9,0x18(5); li 0,0; cmpwi 9,0; beq 0f; lwz 0,0x14(9); 0:; cmpwi 0,0; beq 1f; lwz 0,0x0(3); lis 9,-32705; addi 4,9,3620; sth 11,0xd0(3); sth 6,0xd2(3); cmpwi 0,0; beq 2f; lwz 0,0x1c(3); cmpwi 0,0; beq 2f; lwz 6,0x7c(3); li 7,0; mr 3,0; bl _s801B6A60_0; b 2f; 1:; lwz 0,0x0(3); lis 9,-32705; addi 4,9,3620; cmpwi 0,0; beq 2f; lwz 0,0x1c(3); cmpwi 0,0; beq 2f; lwz 6,0x7c(3); lis 5,-24685; mr 3,0; ori 5,5,65396; li 7,0; bl _s801B6A60_1; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s801B6A60_0();
extern "C" void _s801B6A60_1();

struct G2DTarget {
    void SetIcon_ERShader();
};

void G2DTarget::SetIcon_ERShader() {
}
