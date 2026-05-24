// 0x802D1760 EStream::WriteStructure(EStorable (1540 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-280(1); mfspr 0,8; mfcr 12; stmw 14,0xd0(1); stw 0,0x11c(1); stw 12,0xcc(1); mr 31,3; li 29,1; lwz 9,0x18(31); addi 30,1,8; stw 29,0x0(31); addi 28,1,24; addi 26,1,72; addi 25,1,120; lwz 0,0x2c(9); addi 24,1,136; lha 3,0x28(9); addi 23,1,172; mtspr 8,0; addi 14,1,192; add 3,31,3; mr 27,4; li 20,0; mr 15,30; mr 18,26; mr 16,25; mr 17,24; blrl; stw 3,0xc4(1); li 0,0; stw 0,0x4(30); addi 3,1,24; stw 0,0x8(1); stw 30,0x8(31); stw 29,0x8(30); bl _s802D1760_0; stw 28,0x10(31); mr 4,27; mr 3,30; bl _s802D1760_1; mr 4,27; mr 3,28; bl _s802D1760_2; li 0,-1; stw 0,0x0(3); addi 3,1,40; bl _s802D1760_3; addi 9,1,56; mr 3,26; stw 20,0x4(9); stw 20,0x38(1); stw 9,0x4(31); stw 29,0x8(9); bl _s802D1760_4; lwz 0,0x8(31); mr 3,25; lwz 11,0x4(31); lwz 9,0x10(31); stw 0,0x50(1); stw 29,0x48(1); stw 11,0x4c(1); stw 9,0x58(1); bl _s802D1760_5; mr 3,24; bl _s802D1760_6; b 4f; 0:; lwz 4,0x8(1); mr 3,15; lwz 28,0x0(4); bl _s802D1760_7; lwz 0,0x8(1); stw 0,0x54(1); lwz 9,0x0(28); lha 3,0x10(9); lwz 0,0x14(9); add 3,28,3; mtspr 8,0; blrl; mr 29,3; addi 5,1,160; addi 3,1,40; mr 4,29; bl _s802D1760_8; mr. 30,3; bne 1f; li 3,12; li 27,1; bl _s802D1760_9; mr 9,3; mr 4,29; stw 30,0x0(9); addi 3,1,40; stw 9,0xa0(1); stw 30,0x4(9); stw 27,0x8(9); bl _s802D1760_10; lwz 0,0xa0(1); stw 0,0x0(3); b 2f; 1:; li 27,0; 2:; lwz 3,0xa0(1); mr 4,20; bl _s802D1760_11; addi 3,1,24; mr 4,28; bl _s802D1760_12; stw 20,0x0(3); mr 4,18; addi 20,20,1; lwz 9,0x0(28); lwz 0,0x64(1); lha 3,0x40(9); lwz 9,0x44(9); add 3,28,3; stw 0,0xa4(1); mtspr 8,9; blrl; addi 4,1,164; mr 3,16; bl _s802D1760_13; lwz 0,0x64(1); mr 3,17; lwz 9,0xa4(1); addi 4,1,168; subf 0,9,0; stw 0,0xa8(1); bl _s802D1760_14; cmpwi 27,0; beq 4f; lwz 29,0x18(29); cmpwi 29,0; beq 4f; li 28,1; 3:; addi 3,1,40; mr 4,29; li 5,0; bl _s802D1760_15; mr. 30,3; bne 4f; li 3,12; bl _s802D1760_16; mr 9,3; mr 4,29; stw 30,0x0(9); addi 3,1,40; stw 9,0xa0(1); stw 30,0x4(9); stw 28,0x8(9); bl _s802D1760_17; lwz 0,0xa0(1); stw 0,0x0(3); lwz 29,0x18(29); cmpwi 29,0; bne 3b; 4:; lwz 0,0x8(1); cmpwi 0,0; bne 0b; lwz 9,0x18(31); mr 4,23; stw 20,0xac(1); li 5,4; rlwinm 30,20,2,0,29; li 23,0; lha 3,0x38(9); lwz 0,0x3c(9); add 3,31,3; mtspr 8,0; blrl; mr 3,30; bl _s802D1760_18; mr 22,3; mr 3,30; cmpwi 4,22,0; bl _s802D1760_19; mr. 19,3; mcrf cr3,cr0; mr 25,19; 5:; lwz 28,0x28(1); addi 21,23,1; b 14f; 6:; lwz 29,0x1c(28); lwz 0,0x0(29); cmpwi 0,0; bne 7f; cmpwi 7,23,0; cmpwi 23,1; mfcr 27; rlwinm 27,27,28,0,3; bne 8f; b 12f; 7:; cmpwi 23,0; mfcr 27; beq 13f; 8:; lwz 9,0x0(29); li 26,0; addi 4,1,176; addi 24,1,180; b 10f; 9:; lwz 0,0x0(9); addi 26,26,1; stw 0,0x0(25); addi 25,25,4; lwz 9,0x8(9); 10:; li 0,1; cmpwi 9,0; bne 11f; li 0,0; 11:; cmpwi 0,0; bne 9b; lwz 9,0x18(31); li 5,4; lwz 30,0x18(28); lha 3,0x38(9); lwz 9,0x3c(9); add 3,31,3; lwz 0,0x10(30); mtspr 8,9; stw 0,0xb0(1); blrl; lwz 9,0x18(31); addi 4,1,152; li 5,2; lhz 0,0x14(30); lha 3,0x38(9); lwz 9,0x3c(9); add 3,31,3; sth 0,0x98(1); mtspr 8,9; blrl; lwz 9,0x18(31); mr 4,24; stw 26,0xb4(1); li 5,4; lha 3,0x38(9); lwz 0,0x3c(9); add 3,31,3; mtspr 8,0; blrl; 12:; mtcrf 128,27; beq 13f; cmpwi 29,0; beq 13f; mr 3,29; bl _s802D1760_20; mr 3,29; bl _s802D1760_21; 13:; lwz 28,0x10(28); 14:; li 0,1; cmpwi 28,0; bne 15f; li 0,0; 15:; cmpwi 0,0; bne 6b; mr 23,21; cmpwi 23,1; ble 5b; li 30,0; cmpw 30,20; bge 17f; mr 9,19; 16:; lwz 0,0x0(9); addi 9,9,4; rlwinm 0,0,2,0,29; stwx 30,22,0; addi 30,30,1; cmpw 30,20; blt 16b; 17:; lwz 27,0x38(1); li 25,0; b 21f; 18:; lwz 28,0x0(27); li 30,0; stw 25,0xb8(1); addi 29,1,184; addi 26,1,188; 19:; add 4,28,30; mr 3,18; bl _s802D1760_22; lbz 0,0x0(3); stbx 0,30,29; addi 30,30,1; cmpwi 30,3; ble 19b; lwz 4,0xb8(1); addi 3,1,24; li 30,0; bl _s802D1760_23; lwz 0,0x0(3); rlwinm 0,0,2,0,29; lwzx 9,22,0; addi 9,9,1; stw 9,0xbc(1); 20:; add 4,28,30; mr 3,18; bl _s802D1760_24; lbzx 0,30,26; addi 30,30,1; stb 0,0x0(3); cmpwi 30,3; ble 20b; lwz 27,0x8(27); 21:; li 0,1; cmpwi 27,0; bne 22f; li 0,0; 22:; cmpwi 0,0; bne 18b; cmpwi 20,0; ble 24f; mr 30,20; li 28,183; mr 29,19; 23:; lwz 9,0x0(29); mr 3,18; lwz 11,0x78(1); mr 4,31; lwz 10,0x88(1); rlwinm 9,9,2,0,29; lwzx 5,11,9; addi 29,29,4; lwzx 6,10,9; bl _s802D1760_25; stb 28,0x98(1); addi 4,1,152; li 5,1; lwz 9,0x18(31); lha 3,0x38(9); lwz 0,0x3c(9); add 3,31,3; mtspr 8,0; blrl; addic. 30,30,-1; bne 23b; 24:; lwz 9,0x18(31); mr 4,14; li 5,4; lwz 0,0x0(22); lha 3,0x38(9); lwz 9,0x3c(9); add 3,31,3; stw 0,0xc0(1); mtspr 8,9; blrl; beq cr4,25f; mr 3,22; bl _s802D1760_26; 25:; beq cr3,26f; mr 3,19; bl _s802D1760_27; 26:; lwz 9,0x18(31); li 0,0; stw 0,0x48(1); stw 0,0x0(31); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,31,3; blrl; lwz 0,0xc4(1); li 4,2; subf 30,0,3; mr 3,17; bl _s802D1760_28; mr 3,16; li 4,2; bl _s802D1760_29; li 4,2; mr 3,18; bl _s802D1760_30; addi 3,1,56; bl _s802D1760_31; addi 3,1,40; bl _s802D1760_32; addi 3,1,24; bl _s802D1760_33; mr 3,15; bl _s802D1760_34; mr 3,30; lwz 0,0x11c(1); lwz 12,0xcc(1); mtspr 8,0; lmw 14,0xd0(1); mtcrf 24,12; addi 1,1,280"

extern "C" void _s802D1760_0();
extern "C" void _s802D1760_1();
extern "C" void _s802D1760_2();
extern "C" void _s802D1760_3();
extern "C" void _s802D1760_4();
extern "C" void _s802D1760_5();
extern "C" void _s802D1760_6();
extern "C" void _s802D1760_7();
extern "C" void _s802D1760_8();
extern "C" void _s802D1760_9();
extern "C" void _s802D1760_10();
extern "C" void _s802D1760_11();
extern "C" void _s802D1760_12();
extern "C" void _s802D1760_13();
extern "C" void _s802D1760_14();
extern "C" void _s802D1760_15();
extern "C" void _s802D1760_16();
extern "C" void _s802D1760_17();
extern "C" void _s802D1760_18();
extern "C" void _s802D1760_19();
extern "C" void _s802D1760_20();
extern "C" void _s802D1760_21();
extern "C" void _s802D1760_22();
extern "C" void _s802D1760_23();
extern "C" void _s802D1760_24();
extern "C" void _s802D1760_25();
extern "C" void _s802D1760_26();
extern "C" void _s802D1760_27();
extern "C" void _s802D1760_28();
extern "C" void _s802D1760_29();
extern "C" void _s802D1760_30();
extern "C" void _s802D1760_31();
extern "C" void _s802D1760_32();
extern "C" void _s802D1760_33();
extern "C" void _s802D1760_34();

struct EStream {
    void WriteStructure_EStorable();
};

void EStream::WriteStructure_EStorable() {
}
