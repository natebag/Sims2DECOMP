// 0x8003C074 GameData::CreateAFamilyAddFamilyMember(Family (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); lwz 11,-21476(13); li 0,0; mr 30,4; lwz 9,0x0(11); addi 4,1,8; stw 0,0x8(1); lwz 0,0x16c(9); lha 3,0x168(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21476(13); lwz 9,0x0(11); lwz 0,0x194(9); lha 3,0x190(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(3); mr 5,30; lwz 4,0x8(1); lha 0,0x148(9); lwz 9,0x14c(9); add 3,3,0; mtspr 8,9; blrl; lwz 9,0x8(1); li 0,27; sth 0,0xe4(9); lwz 3,0x8(1); bl _s8003C074_0; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"

extern "C" void _s8003C074_0();

struct GameData {
    void CreateAFamilyAddFamilyMember_Family();
};

void GameData::CreateAFamilyAddFamilyMember_Family() {
}
