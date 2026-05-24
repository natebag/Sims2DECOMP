// 0x8004C7F0 ISimsObjectModel::GetHeightOffset(void) (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); lwz 0,0x3cc(3); andis. 9,0,4096; bne 2f; lwz 11,-21484(13); lwz 10,0x328(3); lwz 9,0x0(11); cmpwi 10,0; lha 0,0x90(9); addi 30,9,144; add 31,11,0; beq 0f; lwz 9,0x4(10); lha 3,0x520(9); lwz 0,0x524(9); add 3,10,3; mtspr 8,0; blrl; b 1f; 0:; li 3,0; 1:; li 4,2; addi 3,3,40; bl _s8004C7F0_0; lwz 0,0x4(30); lha 4,0x0(3); mr 3,31; mtspr 8,0; blrl; mr. 3,3; beq 2f; lwz 9,0x0(3); lwz 3,0x14(9); cmpwi 3,0; beq 2f; lwz 11,0x3d0(3); lwz 9,0x4(11); lwz 0,0x18c(9); lha 3,0x188(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(3); li 4,0; addi 5,1,8; lha 0,0xe0(9); lwz 9,0xe4(9); add 3,3,0; mtspr 8,9; blrl; lis 9,-32707; lfs f13,0x10(1); lfs f0,0x318c(9); fcmpu 0,f13,f0; ble 2f; lis 9,-32707; lfs f1,0x3190(9); fcmpu 0,f13,f1; blt 3f; lis 9,-32707; fmr f1,f13; lfs f0,0x3194(9); fcmpu 0,f13,f0; ble 3f; fmr f1,f0; b 3f; 2:; lis 9,-32707; lfs f1,0x3188(9); 3:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"

extern "C" void _s8004C7F0_0();

struct ISimsObjectModel {
    void GetHeightOffset();
};

void ISimsObjectModel::GetHeightOffset() {
}
