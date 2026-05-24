// 0x800293A0 ERoomWall::GetWallMeterValue(int (480 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f31,0x28(1); stmw 28,0x18(1); stw 0,0x34(1); lwz 30,-21472(13); mr 28,3; li 29,0; lwz 9,0x4(30); lwz 31,0x8(9); b 2f; 0:; lwz 3,0x14(31); lwz 0,0x34(3); cmpwi 0,0; beq 1f; bl _s800293A0_0; cmpwi 3,0; bne 1f; addi 29,29,1; 1:; mr 3,31; bl _s800293A0_1; mr 31,3; 2:; lwz 0,0x4(30); li 9,1; cmpw 31,0; bne 3f; li 9,0; 3:; cmpwi 9,0; bne 0b; stw 29,0x0(28); xoris 0,29,32768; lis 10,17200; lwz 11,0x4(30); lis 8,-32707; stw 0,0x14(1); lis 7,-32707; lwz 0,0x8(11); li 29,0; stw 10,0x10(1); stw 0,0x8(1); mr 31,0; lfd f0,0x10(1); lfd f13,0xcf8(8); lwz 0,0x4(30); fsub f0,f0,f13; lfs f12,0xd00(7); frsp f0,f0; cmpw 31,0; fdivs f31,f0,f12; stw 0,0x8(1); beq 6f; 4:; lwz 3,0x14(31); cmpwi 3,0; beq 5f; lwz 0,0x34(3); cmpwi 0,0; beq 5f; bl _s800293A0_2; cmpwi 3,0; bne 5f; lhz 0,0x10(31); cmplw 0,29; ble 5f; mr 29,0; 5:; mr 3,31; bl _s800293A0_3; lwz 0,0x4(30); mr 31,3; cmpw 31,0; stw 0,0x8(1); bne 4b; 6:; lis 0,17200; stw 29,0x14(1); mr 11,9; lwz 6,-32652(13); lis 8,-32707; stw 0,0x10(1); mr 10,9; lwz 4,-32648(13); lis 7,-32707; lfd f11,0x10(1); lis 5,-32707; stw 6,0x14(1); lis 9,-32707; lfd f12,0xd08(8); stw 0,0x10(1); lfs f0,0xd14(7); fsub f11,f11,f12; lfd f13,0x10(1); frsp f11,f11; stw 4,0x14(1); fsub f13,f13,f12; lfs f9,0xd18(5); stw 0,0x10(1); frsp f13,f13; fdivs f13,f13,f0; lfs f10,0xd10(9); lfd f0,0x10(1); fsub f0,f0,f12; frsp f0,f0; fdivs f0,f0,f9; fmr f12,f13; fdivs f11,f11,f10; fcmpu 0,f0,f13; ble 7f; fmr f12,f0; 7:; fmr f0,f11; fcmpu 0,f12,f11; ble 8f; fmr f0,f12; 8:; fmr f1,f31; fcmpu 0,f0,f31; ble 9f; fmr f1,f0; 9:; lwz 0,0x34(1); mtspr 8,0; lmw 28,0x18(1); lfd f31,0x28(1); addi 1,1,48"

extern "C" void _s800293A0_0();
extern "C" void _s800293A0_1();
extern "C" void _s800293A0_2();
extern "C" void _s800293A0_3();

struct ERoomWall {
    void GetWallMeterValue();
};

void ERoomWall::GetWallMeterValue() {
}
