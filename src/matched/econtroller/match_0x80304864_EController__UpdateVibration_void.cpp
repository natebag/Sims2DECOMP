// 0x80304864 EController::UpdateVibration(void) (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lis 9,-32702; lfs f12,-1640(9); lfs f13,0x1e4(31); fcmpu 0,f13,f12; beq 0f; lfs f0,-26800(13); fsubs f0,f13,f0; fcmpu 0,f0,f12; stfs f0,0x1e4(31); cror 3,2,0; bns 0f; stfs f12,0x1e4(31); lwz 9,0x208(31); lha 3,0x58(9); lwz 0,0x5c(9); add 3,31,3; mtspr 8,0; blrl; 0:; lis 9,-32702; lfs f13,0x1e8(31); lfs f12,-1640(9); fcmpu 0,f13,f12; beq 1f; lfs f0,-26800(13); fsubs f0,f13,f0; fcmpu 0,f0,f12; stfs f0,0x1e8(31); cror 3,2,0; bns 1f; stfs f12,0x1e8(31); lwz 9,0x208(31); lha 3,0x68(9); lwz 0,0x6c(9); add 3,31,3; mtspr 8,0; blrl; 1:; li 3,1; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

struct EController {
    void UpdateVibration();
};

void EController::UpdateVibration() {
}
