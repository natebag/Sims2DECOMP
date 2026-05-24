// 0x800392C4 EyeToyClient::SetExposure(float) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stw 0,0x4c(1); lwz 0,-32576(13); cmpwi 0,-1; beq 1f; lis 9,-32707; lfs f0,0x16d4(9); fcmpu 0,f1,f0; beq 0f; lis 9,-32707; lfs f0,0x16d8(9); fmuls f0,f1,f0; 0:; stfs f0,0xc(1); lwz 3,-32576(13); li 4,8; addi 5,1,8; bl _s800392C4_0; b 2f; 1:; li 0,1; stfs f1,-25036(13); stw 0,-25040(13); 2:; lwz 0,0x4c(1); mtspr 8,0; addi 1,1,72"

extern "C" void _s800392C4_0();

struct EyeToyClient {
    void SetExposure();
};

void EyeToyClient::SetExposure() {
}
