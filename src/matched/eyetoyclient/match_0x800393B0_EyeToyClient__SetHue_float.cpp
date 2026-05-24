// 0x800393B0 EyeToyClient::SetHue(float) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32707; lfs f0,0x16e8(9); fcmpu 0,f1,f0; bge 2f; lis 9,-32707; lfs f0,0x16ec(9); fcmpu 0,f1,f0; bne 0f; lis 9,-32707; lfs f0,0x16f0(9); b 1f; 0:; lis 9,-32707; lfs f0,0x16f4(9); 1:; fadds f1,f1,f0; 2:; lis 11,-32707; lis 10,-32707; lfs f13,0x16e8(11); lis 9,-32697; lfs f0,0x16f8(10); addi 9,9,23136; fsubs f1,f1,f13; mr 4,9; fmuls f0,f1,f0; li 3,0; stfs f0,0x18(9); bl _s800393B0_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s800393B0_0();

struct EyeToyClient {
    void SetHue();
};

void EyeToyClient::SetHue() {
}
