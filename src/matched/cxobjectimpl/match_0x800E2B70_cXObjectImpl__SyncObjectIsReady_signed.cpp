// 0x800E2B70 cXObjectImpl::SyncObjectIsReady(signed (452 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; li 30,0; addi 5,1,8; addi 6,1,10; sth 30,0xc(1); bl _s800E2B70_0; lha 5,0xa(1); li 7,0; lha 4,0x8(1); addi 8,1,12; li 6,0; mr 3,31; bl _s800E2B70_1; lwz 3,-21484(13); lha 4,0xc(1); lwz 9,0x0(3); lha 0,0x90(9); lwz 9,0x94(9); add 3,3,0; mtspr 8,9; blrl; mr. 3,3; beq 0f; lwz 0,0x4(31); cmpw 3,0; bne 1f; 0:; lis 9,-32706; li 3,-1; lfs f0,-20728(9); li 4,-1; stw 30,0xe4(31); stw 30,0xdc(31); b 7f; 1:; lwz 0,0xdc(31); cmpw 0,3; beq 2f; lis 9,-32706; li 0,1; lfs f0,-20728(9); stw 3,0xdc(31); stfs f0,0xe0(31); stw 0,0xe4(31); b 3f; 2:; lfs f0,0xe0(31); lfs f13,-26800(13); fadds f0,f0,f13; stfs f0,0xe0(31); 3:; lwz 11,0xdc(31); lwz 9,0x4(11); lwz 0,0xd4(9); lha 3,0xd0(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x4(31); cmpw 3,0; bne 5f; lis 9,-32706; li 0,0; lfs f0,-20728(9); stw 0,0xe4(31); stfs f0,0xe0(31); lwz 11,0xdc(31); lwz 9,0x4(11); lha 3,0xe0(9); lwz 0,0xe4(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; bne 4f; lwz 11,0xdc(31); lwz 9,0x4(11); lwz 0,0xdc(9); lha 3,0xd8(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x4(31); lwz 9,0x4(11); lha 3,0xd8(9); lwz 0,0xdc(9); add 3,11,3; mtspr 8,0; blrl; 4:; li 3,0; li 4,1; b 8f; 5:; lis 9,-32706; lfs f13,0xe0(31); lfs f0,-20724(9); fcmpu 0,f13,f0; cror 3,2,1; bso 6f; li 3,0; li 4,2; b 8f; 6:; lis 9,-32706; li 0,0; lfs f0,-20728(9); li 3,0; stw 0,0xe4(31); li 4,1; 7:; stfs f0,0xe0(31); 8:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"

extern "C" void _s800E2B70_0();
extern "C" void _s800E2B70_1();

struct cXObjectImpl {
    void SyncObjectIsReady_signed();
};

void cXObjectImpl::SyncObjectIsReady_signed() {
}
