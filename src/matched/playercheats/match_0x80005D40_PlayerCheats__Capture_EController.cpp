// 0x80005D40 PlayerCheats::Capture(EController (544 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 18,0x10(1); stw 0,0x4c(1); mr 29,3; li 19,0; mr 3,4; li 4,-1; bl _s80005D40_0; rlwinm 31,3,0,16,31; mr 3,29; mr 4,31; bl _s80005D40_1; cmpwi 3,0; beq 0f; lis 9,-32697; lis 18,-32697; lhz 0,0x5dcc(9); and. 9,31,0; bne 1f; 0:; li 0,1; li 3,0; stw 0,0x18(29); b 13f; 1:; lwz 11,-26532(13); mr 4,29; lwz 9,0x0(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lis 9,-32707; lfs f0,0x10(29); lfs f13,-19648(9); fmuls f1,f1,f13; fadds f0,f0,f13; stfs f1,0x10(29); fcmpu 7,f1,f0; cror 31,30,29; mfcr 0; rlwinm 0,0,0,31,31; cmpwi 0,0; beq 2f; li 0,1; stw 0,0x18(29); 2:; lwz 0,0x18(29); cmpwi 0,0; beq 3f; mr 3,29; bl _s80005D40_2; 3:; lwz 0,0x14(29); addi 9,29,28; mr 26,9; mr 3,29; add 0,0,0; li 27,0; sthx 31,9,0; bl _s80005D40_3; lis 9,-32697; mr 20,3; addi 21,9,24146; addi 23,21,-132; mr 22,23; 4:; add 11,27,27; addi 24,27,1; lhzx 9,21,11; and 0,20,9; cmpw 0,9; bne 11f; lwz 0,0x14(29); stw 0,0xc(1); addi 25,1,12; b 10f; 5:; lwz 11,0xc(1); add 0,11,11; lhzx 9,26,0; cmpwi 9,0; beq 10f; mulli 9,27,12; lhzx 0,23,9; cmpwi 0,0; beq 10f; stw 11,0x8(1); add 31,9,22; li 28,0; li 30,0; b 7f; 6:; lwz 0,0x8(1); add 0,0,0; lhzx 9,26,0; cmpw 11,9; bne 9f; mr 3,29; addi 4,1,8; bl _s80005D40_4; addi 30,30,1; 7:; cmpwi 7,30,6; bgt cr7,9f; lhz 0,0x0(31); addi 31,31,2; mr 11,0; cmpwi 11,0; beq 8f; bne cr7,6b; 8:; li 28,1; 9:; cmpwi 28,0; beq 10f; li 19,1; addi 3,18,24012; mr 4,27; bl _s80005D40_5; 10:; mr 3,29; mr 4,25; bl _s80005D40_6; lwz 0,0x14(29); cmpw 3,0; bne 5b; 11:; mr 27,24; cmpwi 27,10; ble 4b; cmpwi 19,0; bne 12f; mr 3,29; addi 4,3,20; bl _s80005D40_7; li 3,0; b 13f; 12:; mr 3,29; bl _s80005D40_8; li 3,1; 13:; lwz 0,0x4c(1); mtspr 8,0; lmw 18,0x10(1); addi 1,1,72"

extern "C" void _s80005D40_0();
extern "C" void _s80005D40_1();
extern "C" void _s80005D40_2();
extern "C" void _s80005D40_3();
extern "C" void _s80005D40_4();
extern "C" void _s80005D40_5();
extern "C" void _s80005D40_6();
extern "C" void _s80005D40_7();
extern "C" void _s80005D40_8();

struct PlayerCheats {
    void Capture_EController();
};

void PlayerCheats::Capture_EController() {
}
