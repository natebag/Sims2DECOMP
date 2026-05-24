// 0x800DE788 cXObjectImpl::UpdateChairFacing(void) (860 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; mfcr 12; stmw 17,0x2c(1); stw 0,0x6c(1); stw 12,0x28(1); mr 25,3; addi 30,1,16; lwz 11,0x4(25); addi 3,1,8; addi 23,1,24; mr 19,30; lwz 9,0x4(11); li 21,0; mr 24,19; li 27,0; lwz 0,0x35c(9); lis 17,-32702; lha 4,0x358(9); li 28,0; mtspr 8,0; add 4,11,4; blrl; lwz 11,0x4(25); mr 3,30; lwz 9,0x4(11); lha 4,0x358(9); lwz 0,0x35c(9); add 4,11,4; mtspr 8,0; blrl; addi 3,1,8; bl _s800DE788_0; mr 20,3; addi 3,1,8; bl _s800DE788_1; lis 9,-32702; lwz 26,-21488(13); lwz 31,-21484(13); mr 22,3; addi 18,9,17152; 0:; lwzx 4,28,18; mr 3,24; add 4,20,4; bl _s800DE788_2; addi 9,17,17188; mr 3,24; lwzx 4,9,28; add 4,22,4; bl _s800DE788_3; lwz 9,0x0(26); mr 4,24; lha 3,0x58(9); lwz 0,0x5c(9); add 3,26,3; mtspr 8,0; blrl; cmpwi 3,0; bne 5f; lwz 9,0x0(31); mr 4,19; lwz 11,0x254(9); addi 29,9,144; lha 3,0x250(9); mtspr 8,11; lha 30,0x90(9); add 3,31,3; add 30,31,30; blrl; lwz 0,0x4(29); mr 4,3; mr 3,30; mtspr 8,0; blrl; mr. 11,3; bne 2f; b 3f; 1:; lwz 3,0x4(30); lwz 9,0x4(3); lha 0,0x2f8(9); lwz 9,0x2fc(9); add 3,3,0; mtspr 8,9; blrl; mr. 11,3; beq 3f; 2:; lwz 9,0x4(11); lha 3,0x520(9); lwz 0,0x524(9); add 3,11,3; mtspr 8,0; blrl; mr 30,3; b 4f; 3:; li 30,0; 4:; cmpwi 30,0; beq 5f; lwz 3,0x4(30); lwz 9,0x4(3); lha 0,0x470(9); lwz 9,0x474(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 1b; lwz 11,0x4(30); addi 0,27,4; rlwinm 29,0,0,29,31; lwz 9,0x4(11); lha 3,0x480(9); lwz 0,0x484(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 5f; addi 3,30,40; li 4,1; bl _s800DE788_4; lha 0,0x0(3); cmpw 0,29; bne 5f; li 21,1; b 6f; 5:; addi 27,27,2; addi 28,28,8; cmpwi 27,7; ble 0b; 6:; lwz 4,0x4(25); mr 3,23; li 5,0; bl _s800DE788_5; lwz 0,0x1c(1); cmpwi 0,0; beq 15f; cmpwi 21,0; mfcr 28; 7:; lwz 11,0x1c(1); cmpwi 11,0; beq 8f; lwz 9,0x4(11); lha 3,0x520(9); lwz 0,0x524(9); add 3,11,3; mtspr 8,0; blrl; mr 29,3; b 9f; 8:; li 29,0; 9:; addi 30,29,40; li 4,8; mr 3,30; cmpwi 4,21,0; bl _s800DE788_6; lhz 0,0x0(3); li 4,8; mr 3,30; rlwinm 31,0,24,31,31; bl _s800DE788_7; lha 5,0x0(3); mtcrf 128,28; beq 10f; mr 3,30; ori 5,5,256; li 4,8; bl _s800DE788_8; b 11f; 10:; mr 3,30; li 4,8; rlwinm 5,5,0,24,22; bl _s800DE788_9; 11:; cmpwi 31,0; beq 12f; beq cr4,13f; b 14f; 12:; beq cr4,14f; 13:; lwz 3,0x4(29); li 4,25; lwz 9,0x4(3); lha 0,0x1d0(9); lwz 9,0x1d4(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 14f; lwz 3,0x4(29); li 4,9; li 5,0; li 6,0; lwz 9,0x4(3); lha 0,0x100(9); lwz 9,0x104(9); add 3,3,0; mtspr 8,9; blrl; 14:; mr 3,23; bl _s800DE788_10; lwz 0,0x1c(1); cmpwi 0,0; bne 7b; 15:; mr 3,19; li 4,2; bl _s800DE788_11; addi 3,1,8; li 4,2; bl _s800DE788_12; lwz 0,0x6c(1); lwz 12,0x28(1); mtspr 8,0; lmw 17,0x2c(1); mtcrf 8,12; addi 1,1,104"

extern "C" void _s800DE788_0();
extern "C" void _s800DE788_1();
extern "C" void _s800DE788_2();
extern "C" void _s800DE788_3();
extern "C" void _s800DE788_4();
extern "C" void _s800DE788_5();
extern "C" void _s800DE788_6();
extern "C" void _s800DE788_7();
extern "C" void _s800DE788_8();
extern "C" void _s800DE788_9();
extern "C" void _s800DE788_10();
extern "C" void _s800DE788_11();
extern "C" void _s800DE788_12();

struct cXObjectImpl {
    void UpdateChairFacing();
};

void cXObjectImpl::UpdateChairFacing() {
}
