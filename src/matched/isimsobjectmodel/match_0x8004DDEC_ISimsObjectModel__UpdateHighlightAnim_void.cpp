// 0x8004DDEC ISimsObjectModel::UpdateHighlightAnim(void) (328 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,-26812(13); lwz 0,-32456(13); cmpw 11,0; beq 3f; lis 9,-32707; lfs f13,-26800(13); lfs f0,-32452(13); addi 8,9,12756; lfs f11,0x31d4(9); addi 10,13,-32464; stw 11,-32456(13); li 9,0; fmuls f13,f13,f0; 0:; rlwinm 0,9,2,0,29; addi 11,9,1; lfsx f0,10,0; fadds f0,f0,f13; fcmpu 0,f0,f11; stfsx f0,10,0; ble 2f; lfs f12,0x0(8); addi 9,13,-32464; 1:; lfsx f0,9,0; fsubs f0,f0,f12; stfsx f0,9,0; fcmpu 0,f0,f12; bgt 1b; 2:; mr 9,11; cmpwi 9,1; ble 0b; 3:; lis 9,-32697; lwz 0,0x5e98(9); cmpwi 0,0; bne 5f; lwz 0,0x32c(3); andi. 9,0,1; beq 5f; lis 9,-32707; lfs f13,0x3f8(3); lfs f0,0x31d8(9); fcmpu 0,f13,f0; bne 4f; lis 9,-32707; lfs f0,-32436(13); lfs f13,0x31dc(9); fmuls f0,f0,f13; stfs f0,-32464(13); 4:; lfs f0,-26800(13); lfs f12,-32452(13); lfs f13,0x3f8(3); fmadds f0,f0,f12,f13; b 6f; 5:; lis 9,-32707; lfs f0,0x31d8(9); 6:; stfs f0,0x3f8(3); lis 9,-32697; lwz 0,0x5e98(9); cmpwi 0,1; bne 8f; lwz 0,0x32c(3); andi. 9,0,8; beq 8f; lis 9,-32707; lfs f13,0x3fc(3); lfs f0,0x31d8(9); fcmpu 0,f13,f0; bne 7f; lis 9,-32707; lfs f0,-32436(13); lfs f13,0x31dc(9); fmuls f0,f0,f13; stfs f0,-32460(13); 7:; lfs f0,-26800(13); lfs f12,-32452(13); lfs f13,0x3fc(3); fmadds f0,f0,f12,f13; stfs f0,0x3fc(3); blr; 8:; lis 9,-32707; lfs f0,0x31d8(9); stfs f0,0x3fc(3)"

struct ISimsObjectModel {
    void UpdateHighlightAnim();
};

void ISimsObjectModel::UpdateHighlightAnim() {
}
