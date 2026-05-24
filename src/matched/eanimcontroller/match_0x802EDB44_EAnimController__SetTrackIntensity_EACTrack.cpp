// 0x802EDB44 EAnimController::SetTrackIntensity(EACTrack (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lis 9,-32702; mr 31,4; lfs f13,-4444(9); fcmpu 0,f1,f13; bge 0f; fmr f1,f13; 0:; lis 9,-32702; lfs f0,-4440(9); fcmpu 0,f1,f0; ble 1f; fmr f1,f0; 1:; fcmpu 0,f1,f13; cror 3,2,1; bso 2f; fmr f1,f13; 2:; cmpwi 5,0; beq 3f; li 0,0; stfs f1,0x60(31); stb 0,0xa0(31); stfs f1,0x64(31); 3:; fcmpu 0,f1,f13; stfs f1,0x50(31); beq 4f; mr 4,31; li 5,1; bl _s802EDB44_0; lis 9,-32702; lfs f0,-4436(9); stfs f0,0x48(31); b 5f; 4:; mr 4,31; li 5,0; bl _s802EDB44_1; 5:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s802EDB44_0();
extern "C" void _s802EDB44_1();

struct EAnimController {
    void SetTrackIntensity();
};

void EAnimController::SetTrackIntensity() {
}
