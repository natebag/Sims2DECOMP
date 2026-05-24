// 0x803213C8 ERTexture::Select(ERC (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 11,4; lwz 9,0x70(11); lwz 4,0x14(3); lha 3,0x120(9); lwz 0,0x124(9); add 3,11,3; mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

struct ERTexture {
    void Select();
};

void ERTexture::Select() {
}
