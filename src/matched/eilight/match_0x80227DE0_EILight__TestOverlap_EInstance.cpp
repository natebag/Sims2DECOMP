// 0x80227DE0 EILight::TestOverlap(EInstance (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); stw 31,0x3c(1); lwz 0,0x3c(3); addi 9,3,60; lwz 11,0x4(9); addi 31,1,8; lwz 6,0x8(9); addi 10,3,72; stw 0,0x8(1); addi 12,1,20; addi 5,4,60; addi 7,4,72; lwz 8,0x48(3); stw 11,0x4(31); li 3,0; stw 6,0x8(31); lwz 11,0x8(10); lwz 0,0x4(10); stw 8,0x14(1); lwz 9,0x48(4); stw 0,0x4(12); stw 11,0x8(12); stw 9,0x2c(1); lwz 9,0x4(5); lwz 10,0x8(5); lwz 8,0x8(7); lwz 0,0x3c(4); lwz 11,0x4(7); lfs f13,0x8(1); lfs f0,0x2c(1); stw 0,0x20(1); fcmpu 0,f13,f0; stw 9,0x24(1); stw 10,0x28(1); stw 11,0x30(1); stw 8,0x34(1); cror 3,2,0; bns 0f; lfs f13,0x14(1); lfs f0,0x20(1); fcmpu 0,f13,f0; cror 3,2,1; bns 0f; lfs f13,0x4(31); lfs f0,0x30(1); fcmpu 0,f13,f0; cror 3,2,0; bns 0f; lfs f13,0x4(12); lfs f0,0x24(1); fcmpu 0,f13,f0; cror 3,2,1; bns 0f; lfs f13,0x8(31); lfs f0,0x34(1); fcmpu 0,f13,f0; cror 3,2,0; bns 0f; lfs f13,0x8(12); lfs f0,0x28(1); fcmpu 0,f13,f0; cror 3,2,1; bns 0f; li 3,1; 0:; lwz 31,0x3c(1); addi 1,1,64"

struct EILight {
    void TestOverlap_EInstance();
};

void EILight::TestOverlap_EInstance() {
}
