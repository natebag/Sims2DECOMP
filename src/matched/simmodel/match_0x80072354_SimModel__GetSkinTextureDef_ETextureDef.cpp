// 0x80072354 SimModel::GetSkinTextureDef(ETextureDef (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 4,4; beq 0f; lhz 0,-32204(13); b 1f; 0:; lhz 0,-32202(13); 1:; rlwinm 0,0,7,0,24; sth 0,0x10(3); cmpwi 4,0; beq 2f; lhz 0,-32204(13); b 3f; 2:; lhz 0,-32202(13); 3:; rlwinm 0,0,7,0,24; sth 0,0x12(3); lwz 9,0x8(3); li 11,8; li 10,256; li 8,138; ori 9,9,128; li 7,2; rlwinm 9,9,0,0,29; li 0,32; stb 0,0x1b(3); stb 11,0x1a(3); sth 10,0x14(3); stb 8,0x18(3); stw 9,0x8(3); stb 7,0x19(3)"

struct SimModel {
    void GetSkinTextureDef_ETextureDef();
};

void SimModel::GetSkinTextureDef_ETextureDef() {
}
