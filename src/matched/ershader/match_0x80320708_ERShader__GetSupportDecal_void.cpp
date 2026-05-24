// 0x80320708 ERShader::GetSupportDecal(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s80320708_0; cmpwi 3,0; bne 0f; lwz 3,0x58(31); b 1f; 0:; lwz 9,0x18(31); lwz 3,0x58(9); 1:; rlwinm 3,3,25,31,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s80320708_0();

struct ERShader {
    void GetSupportDecal();
};

void ERShader::GetSupportDecal() {
}
