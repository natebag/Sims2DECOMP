// 0x802FF7D0 ESubModelShader::CanColorBeModified(void) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x8(3); lwz 0,0x14(9); cmpwi 0,0; beq 0f; mr 9,0; b 1f; 0:; lwz 11,0x18(9); li 9,0; cmpwi 11,0; beq 1f; lwz 9,0x14(11); 1:; lwz 0,0xb4(9); lwz 3,0x74(9); or 3,3,0; rlwinm 3,3,27,31,31"

struct ESubModelShader {
    void CanColorBeModified();
};

void ESubModelShader::CanColorBeModified() {
}
