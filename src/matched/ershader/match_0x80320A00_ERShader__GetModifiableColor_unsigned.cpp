// 0x80320A00 ERShader::GetModifiableColor(unsigned (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x14(3); cmpwi 9,0; bne 0f; lwz 3,0x18(3); li 9,0; cmpwi 3,0; beq 0f; lwz 9,0x14(3); 0:; rlwinm 0,4,2,0,29; addi 9,9,64; lwzx 3,9,0"

struct ERShader {
    void GetModifiableColor();
};

void ERShader::GetModifiableColor() {
}
