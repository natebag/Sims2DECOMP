// 0x800BC24C HouseImpl::GetHouseStats(HouseStats (468 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 31,4; li 0,0; stw 0,0x24(31); mr 26,3; stw 0,0x0(31); stw 0,0x4(31); stw 0,0x8(31); stw 0,0xc(31); stw 0,0x14(31); stw 0,0x18(31); stw 0,0x1c(31); stw 0,0x20(31); lwz 27,-21472(13); lwz 9,0x4(27); lwz 29,0x8(9); b 5f; 0:; lwz 30,0x14(29); cmpwi 30,0; beq 4f; lwz 0,0x34(30); cmpwi 0,0; beq 4f; mr 3,30; bl _s800BC24C_0; cmpwi 3,0; bne 4f; mr 3,30; bl _s800BC24C_1; lwz 0,0x0(31); rlwinm 9,3,3,0,28; add 9,9,3; li 11,1; add 0,0,9; stw 0,0x0(31); lwz 9,0x70(30); cmpwi 9,0; bgt 1f; li 11,0; 1:; cmpwi 11,0; beq 2f; lwz 9,0xc(31); addi 9,9,1; stw 9,0xc(31); 2:; lwz 0,0x6c(30); li 9,1; cmpwi 0,0; bgt 3f; li 9,0; 3:; cmpwi 9,0; beq 4f; lwz 9,0x8(31); addi 9,9,1; stw 9,0x8(31); 4:; mr 3,29; bl _s800BC24C_2; mr 29,3; 5:; lwz 0,0x4(27); li 28,1; cmpw 29,0; bne 6f; li 28,0; 6:; cmpwi 28,0; bne 0b; lwz 11,-21488(13); li 29,1; stw 29,0x10(31); lwz 9,0x0(11); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21488(13); mr 30,3; lwz 9,0x0(11); lha 3,0x38(9); lwz 0,0x3c(9); add 3,11,3; mtspr 8,0; blrl; mullw 30,30,3; cmpwi 30,1599; bgt 7f; stw 28,0x14(31); b 9f; 7:; cmpwi 30,2499; bgt 8f; stw 29,0x14(31); b 9f; 8:; li 0,2; stw 0,0x14(31); 9:; lwz 11,-21484(13); mr 5,31; lwz 4,-21472(13); lwz 9,0x0(11); lwz 0,0x20c(9); lha 3,0x208(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x14(26); lwz 9,0x0(11); lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; stw 3,0x4(31); lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"

extern "C" void _s800BC24C_0();
extern "C" void _s800BC24C_1();
extern "C" void _s800BC24C_2();

struct HouseImpl {
    void GetHouseStats_HouseStats();
};

void HouseImpl::GetHouseStats_HouseStats() {
}
