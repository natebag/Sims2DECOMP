// 0x800E2E04 cXObjectImpl::SyncObjectIsReady(void) (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lfs f13,-26800(13); lfs f0,0xe0(31); lwz 11,0xdc(31); fadds f0,f0,f13; stfs f0,0xe0(31); lwz 9,0x4(11); lwz 0,0xd4(9); lha 3,0xd0(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x4(31); cmpw 3,0; bne 1f; lis 9,-32706; li 0,0; lfs f0,-20716(9); stw 0,0xe4(31); stfs f0,0xe0(31); lwz 11,0xdc(31); lwz 9,0x4(11); lha 3,0xe0(9); lwz 0,0xe4(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; lwz 11,0xdc(31); lwz 9,0x4(11); lwz 0,0xdc(9); lha 3,0xd8(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x4(31); lwz 9,0x4(11); lha 3,0xd8(9); lwz 0,0xdc(9); add 3,11,3; mtspr 8,0; blrl; 0:; li 3,1; b 3f; 1:; lis 9,-32706; lfs f13,0xe0(31); lfs f0,-20712(9); fcmpu 0,f13,f0; cror 3,2,1; bso 2f; li 3,0; b 3f; 2:; lis 9,-32706; li 0,0; lfs f0,-20716(9); li 3,1; stw 0,0xe4(31); stfs f0,0xe0(31); 3:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

struct cXObjectImpl {
    void SyncObjectIsReady();
};

void cXObjectImpl::SyncObjectIsReady() {
}
