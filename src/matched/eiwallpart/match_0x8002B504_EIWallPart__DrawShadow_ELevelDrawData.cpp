// 0x8002B504 EIWallPart::DrawShadow(ELevelDrawData (392 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 31,4; lwz 0,0x120(30); cmpwi 0,0; beq 6f; lwz 0,0x3ac(30); cmpwi 0,0; beq 6f; lwz 9,0x0(30); lwz 0,0x164(9); lha 3,0x160(9); mtspr 8,0; add 3,30,3; blrl; lwz 0,0xac(31); cmpw 0,3; beq 0f; li 0,0; stw 3,0xac(31); stw 0,0xb4(31); mr 4,3; lwz 11,0x98(31); li 5,1; lwz 9,0x70(11); lha 3,0xe8(9); lwz 0,0xec(9); add 3,11,3; mtspr 8,0; blrl; 0:; lha 9,0x35a(30); lha 0,0x358(30); cmpw 9,0; beq 1f; lfs f13,0x380(30); lis 9,-32707; lfs f11,0x90(31); lfs f0,0x37c(30); lfs f10,0x8c(31); fmuls f13,f13,f11; lfs f12,0xdac(9); fmadds f0,f0,f10,f13; fcmpu 0,f0,f12; blt 6f; 1:; lwz 0,0xb0(31); addi 4,31,64; cmpw 0,4; beq 2f; stw 4,0xb0(31); lis 9,-32707; lwz 11,0x98(31); li 5,0; lfs f1,0xdac(9); lwz 9,0x70(11); lha 3,0xf8(9); lwz 0,0xfc(9); add 3,11,3; mtspr 8,0; blrl; 2:; lbz 9,0x349(30); lwz 0,0x118(30); extsb 9,9; lwz 11,0xa8(31); rlwinm 9,9,4,0,27; add 9,9,0; lwz 9,0x4(9); ori 0,9,1; cmpw 11,0; beq 5f; stw 0,0xa8(31); lwz 4,0x98(31); lwz 3,0x14(9); cmpwi 3,0; beq 3f; mr 11,3; b 4f; 3:; lwz 9,0x18(9); li 11,0; cmpwi 9,0; beq 4f; lwz 11,0x14(9); 4:; lwz 9,0xf0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 5:; lwz 3,0x3ac(30); lwz 4,0x98(31); bl _s8002B504_0; 6:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s8002B504_0();

struct EIWallPart {
    void DrawShadow_ELevelDrawData();
};

void EIWallPart::DrawShadow_ELevelDrawData() {
}
