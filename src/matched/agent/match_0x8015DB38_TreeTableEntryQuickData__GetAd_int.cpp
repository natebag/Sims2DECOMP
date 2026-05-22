// 0x8015DB38 TreeTableEntryQuickData::GetAd(int) (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; lwz 3,0x8(30); lwz 0,0xc(30); subf 0,3,0; srawi 0,0,2; cmpw 4,0; bge 0f; rlwinm 9,4,2,0,29; lwzx 3,3,9; mr 29,9; cmpwi 3,0; bne 9f; lwz 3,0x4(30); bl _s8015DB38_0; mr. 31,3; bne 1f; 0:; li 3,0; b 9f; 1:; lha 0,0x2(31); cmpwi 0,0; bne 5f; lha 0,0x0(31); cmpwi 0,0; bne 5f; lha 0,0x4(31); cmpwi 0,0; bne 5f; lwz 30,0x8(30); lwz 31,-31588(13); lwzx 0,30,29; cmpw 31,0; beq 4f; cmpwi 31,0; beq 2f; lwz 9,0x0(31); lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; 2:; lwzx 11,30,29; cmpwi 11,0; beq 3f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 3:; stwx 31,30,29; 4:; lwz 3,-31588(13); b 9f; 5:; li 3,12; bl _s8015DB38_1; mr 4,31; bl _s8015DB38_2; lwz 30,0x8(30); mr 31,3; lwzx 0,30,29; cmpw 31,0; beq 8f; cmpwi 31,0; beq 6f; lwz 9,0x0(31); lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; 6:; lwzx 11,30,29; cmpwi 11,0; beq 7f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 7:; stwx 31,30,29; 8:; mr 3,31; 9:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8015DB38_0();
extern "C" void _s8015DB38_1();
extern "C" void _s8015DB38_2();
extern "C" void f_8015DB38() {}
