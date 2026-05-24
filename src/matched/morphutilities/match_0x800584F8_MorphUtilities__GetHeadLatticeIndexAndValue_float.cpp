// 0x800584F8 MorphUtilities::GetHeadLatticeIndexAndValue(float, (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stfd f31,0x30(1); stmw 27,0x1c(1); stw 0,0x3c(1); li 27,-1; mr 31,5; lis 9,-32707; stw 27,0x0(31); lfs f0,0x3c70(9); mr 29,7; stw 27,0x0(29); mr 30,4; fmr f31,f1; mr 28,6; stfs f0,0x0(30); fcmpu 0,f31,f0; stfs f0,0x0(28); blt 5f; lis 9,-32707; lfs f0,0x3c74(9); fcmpu 0,f31,f0; bgt 5f; bl _s800584F8_0; fctiwz f0,f1; stfd f0,0x10(1); fmr f1,f31; lwz 9,0x14(1); stw 9,0x0(31); bl _s800584F8_1; lis 9,-32707; fsubs f1,f31,f1; lfs f13,0x3c78(9); fsubs f1,f13,f1; stfs f1,0x0(30); lwz 9,0x0(31); cmpwi 9,6; bgt 0f; addi 0,9,1; stw 0,0x0(29); lfs f0,0x0(30); fsubs f0,f13,f0; stfs f0,0x0(28); 0:; lwz 9,0x0(31); cmpwi 9,3; bne 1f; stw 27,0x0(31); b 2f; 1:; ble 2f; addi 0,9,-1; stw 0,0x0(31); 2:; lwz 9,0x0(29); cmpwi 9,3; bne 3f; li 0,-1; b 4f; 3:; ble 5f; addi 0,9,-1; 4:; stw 0,0x0(29); 5:; lwz 0,0x3c(1); mtspr 8,0; lmw 27,0x1c(1); lfd f31,0x30(1); addi 1,1,56"

extern "C" void _s800584F8_0();
extern "C" void _s800584F8_1();

struct MorphUtilities {
    void GetHeadLatticeIndexAndValue();
};

void MorphUtilities::GetHeadLatticeIndexAndValue() {
}
