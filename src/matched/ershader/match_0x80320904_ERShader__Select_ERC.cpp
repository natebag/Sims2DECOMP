// 0x80320904 ERShader::Select(ERC (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 9,3; lwz 3,0x14(9); cmpwi 3,0; beq 0f; mr 11,3; b 1f; 0:; lwz 3,0x18(9); li 11,0; cmpwi 3,0; beq 1f; lwz 11,0x14(3); 1:; lwz 9,0xf0(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

struct ERShader {
    void Select();
};

void ERShader::Select() {
}
