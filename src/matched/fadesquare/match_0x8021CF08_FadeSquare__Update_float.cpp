// 0x8021CF08 FadeSquare::Update(float) (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stw 31,0xc(1); stw 0,0x1c(1); mr 31,3; fmr f31,f1; lwz 0,0xc(31); cmpwi 0,0; bne 0f; lis 3,-32692; lis 4,-27018; addi 3,3,-27556; ori 4,4,24810; bl _s8021CF08_0; stw 3,0xc(31); 0:; lwz 0,0x14(31); cmpwi 0,0; beq 1f; lfs f0,0x10(31); lwz 0,0x18(31); fsubs f1,f0,f31; cmpwi 0,0; stfs f1,0x10(31); beq 1f; lis 9,-32704; lfs f0,-9136(9); fcmpu 0,f1,f0; cror 3,2,0; bns 1f; lis 9,-32704; li 0,0; lfs f0,-9132(9); stw 0,0x18(31); fadds f0,f1,f0; stfs f0,0x10(31); 1:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0xc(1); lfd f31,0x10(1); addi 1,1,24"

extern "C" void _s8021CF08_0();

struct FadeSquare {
    void Update();
};

void FadeSquare::Update() {
}
