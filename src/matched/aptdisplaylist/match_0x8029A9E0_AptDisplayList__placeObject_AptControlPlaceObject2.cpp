// 0x8029A9E0 AptDisplayList::placeObject(AptControlPlaceObject2 (724 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 27,0x3c(1); stw 0,0x54(1); mr 31,4; mr 29,3; lwz 0,0x0(31); mr 30,5; andi. 9,0,2; beq 1f; lwz 9,0x4c(30); lis 8,-32700; lwz 10,0x8(31); addi 5,8,-6476; lwz 6,0x8(9); addi 28,1,24; lhz 11,-6476(8); rlwinm 10,10,2,0,29; lwz 7,0x4(6); li 4,0; addi 11,11,1; lwz 9,0x18(7); lwzx 27,10,9; sth 11,-6476(8); stw 5,0x18(1); lwz 0,0x0(31); andi. 9,0,32; beq 5f; lwz 4,0x30(31); addi 3,1,32; bl _s8029A9E0_0; lwz 11,0x20(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x18(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 0f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8029A9E0_1; 0:; lwz 4,0x20(1); b 3f; 1:; andi. 9,0,1; beq 14f; lwz 4,0x4(31); li 5,0; lwz 3,0x0(29); addi 6,1,48; addi 7,1,52; bl _s8029A9E0_2; lwz 4,0x34(1); cmpwi 4,0; bne 10f; lwz 9,0x4c(30); lis 8,-32700; lwz 10,0x8(31); addi 5,8,-6476; lwz 6,0x8(9); addi 28,1,24; lhz 11,-6476(8); rlwinm 10,10,2,0,29; lwz 7,0x4(6); li 4,0; addi 11,11,1; lwz 9,0x18(7); lwzx 27,10,9; sth 11,-6476(8); stw 5,0x18(1); lwz 0,0x0(31); andi. 9,0,32; beq 5f; lwz 4,0x30(31); addi 3,1,40; bl _s8029A9E0_3; lwz 11,0x28(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x18(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 2f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8029A9E0_4; 2:; lwz 4,0x28(1); 3:; stw 4,0x18(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 4f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8029A9E0_5; 4:; mr 4,28; 5:; lwz 0,0x0(31); lwz 5,0x4(31); andi. 0,0,8; lwz 10,0x34(31); lfs f1,0x2c(31); beq 6f; addi 0,31,36; 6:; stw 0,0x8(1); lwz 0,0x0(31); andi. 0,0,4; beq 7f; addi 0,31,12; 7:; stw 0,0xc(1); lwz 0,0x0(31); andi. 0,0,128; beq 8f; lwz 0,0x38(31); 8:; stw 0,0x10(1); mr 7,4; li 9,0; li 4,0; mr 3,29; mr 6,27; mr 8,30; bl _s8029A9E0_6; lwz 4,0x18(1); mr 31,3; lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 9f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8029A9E0_7; 9:; mr 3,31; b 15f; 10:; lwz 0,0x5c(4); andi. 9,0,32768; bne 14f; lwz 0,0x0(31); lfs f1,0x2c(31); andi. 0,0,8; beq 11f; addi 0,31,36; 11:; stw 0,0x8(1); lwz 0,0x0(31); andi. 0,0,4; beq 12f; addi 0,31,12; 12:; stw 0,0xc(1); lwz 0,0x0(31); andi. 0,0,128; beq 13f; lwz 0,0x38(31); 13:; stw 0,0x10(1); mr 3,29; mr 8,30; li 5,0; li 6,0; li 7,0; li 9,0; li 10,-1; bl _s8029A9E0_8; b 15f; 14:; li 3,0; 15:; lwz 0,0x54(1); mtspr 8,0; lmw 27,0x3c(1); addi 1,1,80"

extern "C" void _s8029A9E0_0();
extern "C" void _s8029A9E0_1();
extern "C" void _s8029A9E0_2();
extern "C" void _s8029A9E0_3();
extern "C" void _s8029A9E0_4();
extern "C" void _s8029A9E0_5();
extern "C" void _s8029A9E0_6();
extern "C" void _s8029A9E0_7();
extern "C" void _s8029A9E0_8();

struct AptDisplayList {
    void placeObject_AptControlPlaceObject2();
};

void AptDisplayList::placeObject_AptControlPlaceObject2() {
}
