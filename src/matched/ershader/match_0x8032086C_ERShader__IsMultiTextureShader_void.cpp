// 0x8032086C ERShader::IsMultiTextureShader(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x58(3); andi. 9,0,2; beq 0f; li 3,0; blr; 0:; lwz 0,0x14(3); cmpwi 0,0; beq 1f; mr 9,0; b 2f; 1:; lwz 3,0x18(3); li 9,0; cmpwi 3,0; beq 2f; lwz 9,0x14(3); 2:; lwz 3,0x4(9); rlwinm 3,3,6,31,31"

struct ERShader {
    void IsMultiTextureShader();
};

void ERShader::IsMultiTextureShader() {
}
