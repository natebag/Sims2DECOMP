// 0x8003DAA0 GameData::StageEndFrame(char (328 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 0,-21460(13); mr 31,5; mr 29,6; cmpw 31,0; bgt 1f; cmpw 29,0; bgt 1f; lwz 11,-26532(13); lis 30,-32693; addi 30,30,-11760; lwz 9,0x0(11); mr 4,30; lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26532(13); mr 4,30; lwz 9,0x0(11); lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; lfs f13,-25008(13); lis 9,-32707; lfs f0,0x1eac(9); fsubs f1,f1,f13; fcmpu 0,f1,f0; ble 0f; lfs f0,-21452(13); fcmpu 0,f1,f0; ble 0f; stfs f1,-21452(13); stw 31,-21448(13); stw 29,-21464(13); 0:; cmpw 31,29; beq 1f; lwz 11,-26532(13); lis 30,-32693; addi 30,30,-11760; lwz 9,0x0(11); mr 4,30; lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26532(13); mr 4,30; lwz 9,0x0(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lfs f0,-25016(13); lis 9,-32688; lwz 11,-26532(13); addi 9,9,-18824; rlwinm 0,31,2,0,29; fsubs f1,f1,f0; stfsx f1,9,0; mr 4,30; lwz 9,0x0(11); lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; stfs f1,-25016(13); stw 29,-21468(13); 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

struct GameData {
    void StageEndFrame();
};

void GameData::StageEndFrame() {
}
