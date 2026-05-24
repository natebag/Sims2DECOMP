// 0x800477D0 EIFloor::CreateFloors(EHouse (1460 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-184(1); mfspr 0,8; stfd f31,0xb0(1); stmw 14,0x68(1); stw 0,0xbc(1); lis 9,-32707; mr 20,3; lfs f0,0x2e40(9); li 9,0; stw 9,0x58(1); stfs f0,0xc(1); stfs f0,0x8(1); bl _s800477D0_0; bl _s800477D0_1; li 4,7312; li 5,0; bl _s800477D0_2; mr 30,3; bl _s800477D0_3; mr 3,30; li 4,304; li 5,24; addi 6,30,16; bl _s800477D0_4; lwz 9,0x1c(20); li 0,0; stw 30,-32508(13); stw 9,0x44(1); addis 9,9,3; stw 0,-32512(13); stw 0,-32488(13); lwz 3,0x44(1); stw 0,-25232(9); bl _s800477D0_5; lwz 9,-21472(13); lis 10,-32696; addi 10,10,19588; stw 9,0x48(1); lis 9,-32697; addi 9,9,25452; stw 9,0x50(1); lwz 9,0x48(1); lwz 11,0x4(9); stw 10,0x54(1); lwz 11,0x8(11); stw 11,0x4c(1); b 27f; 0:; lwz 10,0x4c(1); lwz 4,0x14(10); lwz 0,0x34(4); cmpwi 0,0; beq 26f; mr 3,4; lha 30,0x0(4); bl _s800477D0_6; li 29,0; cmpwi 3,0; mfcr 31; beq 1f; subfic 0,30,0; adde 29,0,30; 1:; lis 9,-32696; mr 4,30; addi 28,9,-29684; li 5,0; mr 3,28; bl _s800477D0_7; mtcrf 128,31; beq 2f; cmpwi 29,0; beq 26f; 2:; mulli 0,30,12; lis 3,-32696; addi 3,3,-28520; lwz 4,0x54(1); add 3,0,3; bl _s800477D0_8; mr. 31,3; beq 26f; li 0,0; li 3,304; stw 0,0x5c(1); bl _s800477D0_9; li 0,0; stw 0,0x60(1); bl _s800477D0_10; lwz 10,0x54(1); mr 27,3; rlwinm 0,31,1,0,30; stw 30,0x7c(27); stw 10,0x10c(27); add 0,0,31; add 10,10,0; lis 9,-32764; stw 10,0x54(1); addi 9,9,30520; stw 30,0x28(27); mr 3,28; stw 31,0x108(27); mr 4,30; stw 9,0x1c(27); mr 5,27; li 6,0; bl _s800477D0_11; lis 9,-32697; lwz 11,0x5ea0(9); lwz 11,0x0(11); cmpwi 11,0; beq 3f; lwz 11,-4(11); stw 11,0x60(1); 3:; lis 9,-32707; lwz 11,0x60(1); lfs f0,0x2e40(9); li 0,1; lwz 10,0x5c(1); li 9,0; stfs f0,0x28(1); stfs f0,0x30(1); cmpw 10,11; stfs f0,0x2c(1); stw 9,0x64(1); stw 0,0x40(1); lwz 0,0x28(1); lwz 9,0x2c(1); lwz 11,0x30(1); stw 0,0x10(1); stw 9,0x14(1); stw 11,0x18(1); stw 0,0x1c(1); stw 9,0x20(1); stw 11,0x24(1); bge 25f; lis 9,-32696; addi 14,27,272; addi 19,9,-29672; addi 15,27,284; 4:; lwz 21,0x0(19); li 25,0; li 22,0; li 18,0; lwz 0,0x14(21); cmpwi 0,0; beq 5f; mr 11,0; b 6f; 5:; lwz 9,0x18(21); li 11,0; cmpwi 9,0; beq 6f; lwz 11,0x14(9); 6:; lbz 0,0x0(11); cmpwi 7,25,0; lwz 10,0x4(19); cmpwi 0,0; beq 11f; mtspr 9,0; addi 9,11,134; 7:; lbz 0,0x0(9); li 7,0; addi 9,9,64; cmpwi 0,3; beq 8f; cmpwi 0,1; bne 9f; 8:; li 7,1; 9:; or. 0,18,7; li 7,1; bne 10f; li 7,0; 10:; mr 18,7; bdnz 7b; 11:; mr. 26,10; beq 23f; lis 9,-32707; rlwinm 0,22,4,0,27; lfs f31,0x2e40(9); addi 16,20,76; lwz 9,0x50(1); addi 17,1,48; add 24,0,9; 12:; lwz 0,0x0(26); lwz 23,0x8(26); stw 0,0x28(1); lbz 29,0x28(1); lwz 0,0x7c(27); xor 28,0,29; subfic 10,28,0; adde. 28,10,28; bne 14f; lwz 3,0x48(1); lhz 4,0x7e(27); bl _s800477D0_12; mr 30,3; mr 4,29; lwz 3,0x48(1); bl _s800477D0_13; mr 31,3; mr 3,30; bl _s800477D0_14; cmpwi 3,0; beq 13f; mr 3,31; bl _s800477D0_15; cmpwi 3,0; beq 13f; li 28,1; 13:; cmpwi 28,0; beq 22f; 14:; lwz 0,0x7c(27); li 7,0; cmpw 29,0; beq 18f; lwz 0,0x80(27); li 10,0; mr 11,0; cmpw 7,0; bge 17f; lhz 0,0x84(27); addi 8,27,132; cmpw 29,0; b 16f; 15:; addi 10,10,1; cmpw 10,11; bge 17f; add 0,10,10; lhzx 9,8,0; cmpw 29,9; 16:; bne 15b; li 7,1; 17:; cmpwi 7,0; bne 18f; add 0,11,11; addi 9,27,132; sthx 29,9,0; addi 11,11,1; stw 11,0x80(27); 18:; cmpwi 25,0; bne 19f; lwz 11,-26392(13); li 4,1; lwz 9,0x0(11); lha 3,0x80(9); lwz 0,0x84(9); add 3,11,3; mtspr 8,0; blrl; mr 25,3; lis 4,-32707; addi 4,4,11816; bl _s800477D0_16; cmpwi 25,0; beq 22f; 19:; cmpwi 20,0; beq 20f; lfs f13,0x4c(20); addi 5,1,48; lfs f0,0x4(16); stfs f13,0x30(1); stfs f0,0x34(1); b 21f; 20:; stfs f31,0x4(17); addi 5,1,48; stfs f31,0x30(1); 21:; lwz 0,0x28(1); mr 6,24; lwz 8,0x1c(20); addi 4,1,56; addi 9,1,16; stw 0,0x38(1); mr 3,25; mr 7,18; addi 10,1,64; addi 24,24,16; bl _s800477D0_17; addi 22,22,1; mr 4,26; addi 3,19,4; bl _s800477D0_18; lwz 9,0x58(1); cmpwi 7,25,0; cmpwi 9,648; addi 9,9,1; stw 9,0x58(1); beq 23f; 22:; mr. 26,23; cmpwi 7,25,0; bne 12b; 23:; beq cr7,24f; lwz 11,-26392(13); mr 4,25; lwz 9,0x0(11); lha 3,0x88(9); lwz 0,0x8c(9); add 3,11,3; mtspr 8,0; blrl; mr 30,3; li 3,20; bl _s800477D0_19; lwz 8,0x5c(1); mr 4,21; lwz 6,0x50(1); mr 5,30; mr 7,22; bl _s800477D0_20; stw 3,0x5c(1); 24:; lwz 10,0x50(1); rlwinm 0,22,4,0,27; lwz 9,0x58(1); add 10,10,0; cmpwi 9,649; stw 10,0x50(1); beq 25f; lwz 10,0x64(1); mr 3,27; lwz 0,0x10(1); addi 4,1,16; addi 10,10,1; lwz 11,0x14(1); lwz 9,0x18(1); addi 19,19,16; stw 10,0x64(1); stw 0,0x110(27); stw 11,0x4(14); stw 9,0x8(14); lwz 0,0x1c(1); lwz 9,0x20(1); lwz 11,0x24(1); stw 0,0x11c(27); stw 9,0x4(15); stw 11,0x8(15); bl _s800477D0_21; lwz 9,0x64(1); lwz 10,0x60(1); cmpw 9,10; blt 4b; 25:; lwz 11,0x5c(1); mr 4,27; li 5,0; stw 11,0x104(27); lwz 3,0x44(1); bl _s800477D0_22; lwz 9,0x58(1); cmpwi 9,649; beq 29f; 26:; lwz 3,0x4c(1); bl _s800477D0_23; stw 3,0x4c(1); 27:; lwz 9,0x48(1); lwz 10,0x4c(1); lwz 0,0x4(9); li 9,1; cmpw 10,0; bne 28f; li 9,0; 28:; cmpwi 9,0; bne 0b; 29:; bl _s800477D0_24; lwz 0,0xbc(1); mtspr 8,0; lmw 14,0x68(1); lfd f31,0xb0(1); addi 1,1,184"

extern "C" void _s800477D0_0();
extern "C" void _s800477D0_1();
extern "C" void _s800477D0_2();
extern "C" void _s800477D0_3();
extern "C" void _s800477D0_4();
extern "C" void _s800477D0_5();
extern "C" void _s800477D0_6();
extern "C" void _s800477D0_7();
extern "C" void _s800477D0_8();
extern "C" void _s800477D0_9();
extern "C" void _s800477D0_10();
extern "C" void _s800477D0_11();
extern "C" void _s800477D0_12();
extern "C" void _s800477D0_13();
extern "C" void _s800477D0_14();
extern "C" void _s800477D0_15();
extern "C" void _s800477D0_16();
extern "C" void _s800477D0_17();
extern "C" void _s800477D0_18();
extern "C" void _s800477D0_19();
extern "C" void _s800477D0_20();
extern "C" void _s800477D0_21();
extern "C" void _s800477D0_22();
extern "C" void _s800477D0_23();
extern "C" void _s800477D0_24();

struct EIFloor {
    void CreateFloors_EHouse();
};

void EIFloor::CreateFloors_EHouse() {
}
