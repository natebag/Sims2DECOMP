// 0x800DE3C4 cXObjectImpl::Place(FTilePt (956 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; mfcr 12; stmw 21,0x3c(1); stw 0,0x6c(1); stw 12,0x38(1); mr. 28,6; mr 31,3; mr 23,4; mr 22,7; mr 24,5; mcrf cr4,cr0; beq cr4,0f; lwz 9,0x4(28); lha 3,0x350(9); lwz 0,0x354(9); add 3,28,3; mtspr 8,0; blrl; mr 24,3; 0:; lwz 0,0x6c(31); addi 3,31,40; lwz 9,0x68(31); li 4,1; srawi 26,0,4; mr 25,3; srawi 27,9,4; bl _s800DE3C4_0; lha 30,0x0(3); li 4,1; addi 3,1,8; bl _s800DE3C4_1; addi 4,1,8; li 5,1; mr 3,31; bl _s800DE3C4_2; lwz 11,0x4(31); lwz 9,0x4(11); lha 3,0x480(9); lwz 0,0x484(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 1f; lis 9,-32702; lis 11,-32702; rlwinm 0,30,2,0,29; addi 9,9,17152; addi 11,11,17188; lwzx 4,9,0; lwzx 5,11,0; lwz 3,0x58(31); add 4,26,4; lwz 6,0x80(31); add 5,27,5; bl _s800DE3C4_3; 1:; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x400(9); lwz 9,0x404(9); add 3,3,0; mtspr 8,9; blrl; mr. 21,3; beq 2f; lwz 5,0x80(31); mr 3,26; mr 4,27; li 6,0; bl _s800DE3C4_4; 2:; addi 30,1,32; mr 29,30; beq cr4,3f; lwz 9,0x4(28); lha 3,0x520(9); lwz 0,0x524(9); add 3,28,3; mtspr 8,0; blrl; b 4f; 3:; li 3,0; 4:; mr 6,3; mr 4,23; mr 5,24; mr 7,22; mr 3,29; bl _s800DE3C4_5; mr 4,30; mr 3,31; li 5,1; bl _s800DE3C4_6; lwz 9,0x2c(1); cmpwi 9,0; beq 5f; lwz 3,0x4(9); lwz 9,0x4(3); lha 0,0x328(9); lwz 9,0x32c(9); add 3,3,0; mtspr 8,9; blrl; b 6f; 5:; li 3,0; 6:; extsh 5,3; li 4,2; mr 3,25; bl _s800DE3C4_7; lha 5,0x32(1); li 4,3; mr 3,25; bl _s800DE3C4_8; lwz 4,0x2c(1); cmpwi 4,0; beq 7f; lwz 3,0x4(31); addi 4,4,104; lwz 5,0x34(1); lwz 9,0x4(3); lha 0,0x330(9); lwz 9,0x334(9); add 3,3,0; mtspr 8,9; blrl; b 8f; 7:; lwz 3,0x4(31); addi 4,1,36; lwz 5,0x34(1); lwz 9,0x4(3); lha 0,0x330(9); lwz 9,0x334(9); add 3,3,0; mtspr 8,9; blrl; 8:; lwz 0,0x6c(31); lwz 9,0x68(31); srawi 26,0,4; lwz 3,0x58(31); srawi 27,9,4; lwz 6,0x80(31); mr 4,26; mr 5,27; bl _s800DE3C4_9; lwz 11,0x4(31); lwz 9,0x4(11); lha 3,0x480(9); lwz 0,0x484(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 9f; lwz 29,0x58(31); li 4,1; mr 3,25; bl _s800DE3C4_10; lha 0,0x0(3); lis 9,-32702; addi 9,9,17152; li 4,1; rlwinm 0,0,2,0,29; mr 3,25; lwzx 30,9,0; add 30,26,30; bl _s800DE3C4_11; lha 0,0x0(3); lis 9,-32702; addi 9,9,17188; lwz 6,0x80(31); rlwinm 0,0,2,0,29; mr 3,29; lwzx 5,9,0; mr 4,30; add 5,27,5; bl _s800DE3C4_12; 9:; mr 3,31; bl _s800DE3C4_13; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x390(9); lwz 9,0x394(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 10f; lwz 3,0x4(31); li 4,9; li 5,0; li 6,0; lwz 9,0x4(3); lha 0,0x100(9); lwz 9,0x104(9); add 3,3,0; mtspr 8,9; blrl; 10:; cmpwi 28,0; beq 11f; lwz 9,0x4(28); li 4,9; li 5,0; li 6,0; lha 3,0x100(9); lwz 0,0x104(9); add 3,28,3; mtspr 8,0; blrl; 11:; cmpwi 21,0; beq 12f; lwz 5,0x80(31); mr 3,26; mr 4,27; li 6,1; bl _s800DE3C4_14; 12:; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x390(9); lwz 9,0x394(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 13f; lwz 9,0x0(31); lwz 10,0x0(9); lwz 11,0x18(10); lha 3,0x98(11); lwz 0,0x9c(11); add 3,10,3; mtspr 8,0; blrl; bl _s800DE3C4_15; 13:; lwz 0,0x6c(1); lwz 12,0x38(1); mtspr 8,0; lmw 21,0x3c(1); mtcrf 8,12; addi 1,1,104"

extern "C" void _s800DE3C4_0();
extern "C" void _s800DE3C4_1();
extern "C" void _s800DE3C4_2();
extern "C" void _s800DE3C4_3();
extern "C" void _s800DE3C4_4();
extern "C" void _s800DE3C4_5();
extern "C" void _s800DE3C4_6();
extern "C" void _s800DE3C4_7();
extern "C" void _s800DE3C4_8();
extern "C" void _s800DE3C4_9();
extern "C" void _s800DE3C4_10();
extern "C" void _s800DE3C4_11();
extern "C" void _s800DE3C4_12();
extern "C" void _s800DE3C4_13();
extern "C" void _s800DE3C4_14();
extern "C" void _s800DE3C4_15();

struct cXObjectImpl {
    void Place_FTilePt();
};

void cXObjectImpl::Place_FTilePt() {
}
