// 0x8003D248 GameData::CopyrightUpdate(float) (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stmw 29,0xc(1); stw 0,0x24(1); mr 31,3; li 29,0; lwz 0,0x114(31); andi. 9,0,3; beq 3f; lis 9,-32707; lfs f0,0x118(31); lfs f13,0x1e48(9); fcmpu 0,f1,f13; ble 0f; fmr f1,f13; 0:; andi. 9,0,1; beq 1f; lis 9,-32707; fadds f1,f1,f1; lfs f31,0x1e4c(9); fadds f0,f0,f1; fcmpu 0,f0,f31; cror 3,2,1; bns 2f; rlwinm 0,0,0,0,30; lwz 11,-26532(13); ori 0,0,4; lis 4,-32693; stw 0,0x114(31); addi 4,4,-11760; addi 30,31,284; li 29,1; lwz 9,0x0(11); lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; stfs f1,0x4(30); fmr f0,f31; stfs f1,0x11c(31); b 2f; 1:; andi. 9,0,2; beq 2f; lis 9,-32707; fsubs f0,f0,f1; lfs f13,0x1e50(9); fcmpu 0,f0,f13; bge 2f; rlwinm 0,0,0,31,29; fmr f0,f13; ori 0,0,8; li 29,1; stw 0,0x114(31); 2:; stfs f0,0x118(31); 3:; mr 3,29; lwz 0,0x24(1); mtspr 8,0; lmw 29,0xc(1); lfd f31,0x18(1); addi 1,1,32"

struct GameData {
    void CopyrightUpdate();
};

void GameData::CopyrightUpdate() {
}
