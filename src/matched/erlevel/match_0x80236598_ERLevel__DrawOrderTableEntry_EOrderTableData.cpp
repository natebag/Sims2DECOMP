// 0x80236598 ERLevel::DrawOrderTableEntry(EOrderTableData (544 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stmw 28,0x8(1); stw 0,0x24(1); mr 30,4; mr 29,3; lwz 31,0x24(30); mr 28,5; mr 3,31; bl _s80236598_0; lis 9,-32704; fmr f31,f1; lfs f0,-2728(9); fcmpu 0,f31,f0; bgt 0f; lwz 0,0x68(31); cmpwi 0,0; bne 9f; 0:; lwz 0,0x14(30); lis 9,-32733; addi 9,9,-12148; cmpw 0,9; bne 1f; lwz 0,0x1c(30); cmpwi 0,0; bne 2f; 1:; addis 9,29,3; lwz 8,0xc(30); addi 10,9,-24160; mr 31,9; lwz 0,0xac(10); cmpw 0,8; beq 6f; li 0,0; stw 8,0xac(10); stw 0,0xb4(10); mr 4,8; lwz 11,0x98(10); li 5,1; lwz 9,0x70(11); lha 3,0xe8(9); lwz 0,0xec(9); add 3,11,3; mtspr 8,0; blrl; b 6f; 2:; addis 9,29,3; lwz 11,0xc(30); addi 10,9,-24160; mr 31,9; lwz 0,0xb4(10); rlwinm 4,11,0,0,30; rlwinm 9,11,0,31,31; cmpw 0,4; beq 6f; li 0,0; stw 4,0xb4(10); stw 0,0xac(10); lwz 5,0x24(4); lwz 4,0x10(4); cmpwi 5,0; beq 3f; lwz 5,0x18(5); b 4f; 3:; li 5,0; 4:; cmpwi 9,0; beq 5f; lwz 3,0x98(10); lwz 9,0x70(3); lha 0,0xd8(9); lwz 9,0xdc(9); add 3,3,0; mtspr 8,9; blrl; b 6f; 5:; lwz 3,0x98(10); lwz 9,0x70(3); lha 0,0xe8(9); lwz 9,0xec(9); add 3,3,0; mtspr 8,9; blrl; 6:; lwz 0,0x34(30); andi. 9,0,1; beq 7f; lwz 9,0x70(28); lis 4,-32695; lis 5,-32695; addi 4,4,-29628; lwz 0,0x174(9); addi 5,5,-29616; lha 3,0x170(9); mtspr 8,0; lfs f1,-23756(13); add 3,28,3; blrl; li 0,0; stw 0,-23976(31); b 8f; 7:; addi 11,31,-24160; lwz 9,0x10(30); lwz 0,0xb8(11); cmpw 0,9; beq 8f; stw 9,0xb8(11); mr 4,9; lwz 3,0x98(11); lwz 9,0x70(3); lha 0,0x168(9); lwz 9,0x16c(9); add 3,3,0; mtspr 8,9; blrl; 8:; lwz 9,0x70(28); fmr f1,f31; lwz 0,0x25c(9); lha 3,0x258(9); mtspr 8,0; add 3,28,3; blrl; lwz 9,0x14(30); addi 3,31,-24160; mr 4,30; li 0,1; mtspr 8,9; stw 0,-28428(13); blrl; li 0,0; stw 0,-28428(13); 9:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x8(1); lfd f31,0x18(1); addi 1,1,32"

extern "C" void _s80236598_0();

struct ERLevel {
    void DrawOrderTableEntry_EOrderTableData();
};

void ERLevel::DrawOrderTableEntry_EOrderTableData() {
}
