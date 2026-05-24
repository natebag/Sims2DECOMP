// 0x801D5370 PCTTarget::on_selection_changed(void) (1196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; mfcr 12; stmw 25,0x1c(1); stw 0,0x3c(1); stw 12,0x18(1); mr 31,3; bl _s801D5370_0; lwz 0,0xd8(31); lis 5,-24685; ori 5,5,65396; cmpwi 0,0; beq 0f; lwz 0,0xcc(31); lis 9,-32705; addi 9,9,17008; rlwinm 0,0,2,0,29; lwzx 5,9,0; 0:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,17612; cmpwi 0,0; beq 1f; lwz 3,0x1c(31); cmpwi 3,0; beq 1f; lwz 6,0x7c(31); li 7,0; bl _s801D5370_1; 1:; lwz 0,0xdc(31); lis 5,-24685; ori 5,5,65396; cmpwi 0,0; beq 2f; lwz 0,0xd0(31); lis 9,-32705; addi 9,9,17008; rlwinm 0,0,2,0,29; lwzx 5,9,0; 2:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,17628; cmpwi 0,0; beq 3f; lwz 3,0x1c(31); cmpwi 3,0; beq 3f; lwz 6,0x7c(31); li 7,0; bl _s801D5370_2; 3:; lwz 0,0xe0(31); lis 5,-24685; ori 5,5,65396; cmpwi 0,0; beq 4f; lwz 0,0xd4(31); lis 9,-32705; addi 9,9,17008; rlwinm 0,0,2,0,29; lwzx 5,9,0; 4:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,17644; cmpwi 0,0; beq 5f; lwz 3,0x1c(31); cmpwi 3,0; beq 5f; lwz 6,0x7c(31); li 7,0; bl _s801D5370_3; 5:; lwz 4,0xb8(31); mr 3,31; bl _s801D5370_4; li 0,0; mr 26,3; stw 0,0xc8(31); mr 3,31; stw 0,0xc4(31); bl _s801D5370_5; cmpwi 3,0; beq 7f; cmpwi 26,0; beq 7f; lwz 0,0x0(26); cmpwi 0,1; bne 6f; stw 0,0xc8(31); b 7f; 6:; ble 7f; cmpwi 0,4; bgt 7f; li 0,1; stw 0,0xc4(31); 7:; lis 5,-24685; cmpwi 4,26,0; ori 5,5,65396; beq cr4,8f; lis 5,-28296; ori 5,5,207; 8:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,17660; cmpwi 0,0; beq 9f; lwz 3,0x1c(31); cmpwi 3,0; beq 9f; lwz 6,0x7c(31); li 7,0; bl _s801D5370_6; 9:; mr 3,31; lis 30,-32705; bl _s801D5370_7; stw 3,0x20c(31); addi 4,30,18288; lwz 5,0xc4(31); mr 3,31; bl _s801D5370_8; lwz 0,0xc4(31); cmpwi 0,0; bne 10f; lwz 3,0x1c(31); addi 4,30,18288; bl _s801D5370_9; cmpwi 3,0; beq 10f; lwz 0,0x0(31); addi 4,30,18288; cmpwi 0,0; beq 10f; lwz 3,0x1c(31); cmpwi 3,0; beq 10f; bl _s801D5370_10; 10:; lis 30,-32705; lwz 5,0xc8(31); mr 3,31; addi 4,30,18304; bl _s801D5370_11; lwz 0,0xc8(31); cmpwi 0,0; bne 11f; lwz 3,0x20(31); addi 4,30,18304; bl _s801D5370_12; cmpwi 3,0; beq 11f; lwz 0,0x0(31); addi 4,30,18304; cmpwi 0,0; beq 11f; lwz 3,0x20(31); cmpwi 3,0; beq 11f; bl _s801D5370_13; 11:; lis 4,-32705; li 5,16; addi 4,4,17468; mr 3,31; bl _s801D5370_14; lis 4,-32705; li 5,14; addi 4,4,17492; mr 3,31; bl _s801D5370_15; lis 4,-32705; li 5,14; addi 4,4,17480; mr 3,31; bl _s801D5370_16; lis 4,-32705; li 5,14; addi 4,4,17512; mr 3,31; bl _s801D5370_17; lis 4,-32705; li 5,14; addi 4,4,17532; mr 3,31; bl _s801D5370_18; lis 4,-32705; mr 3,31; addi 4,4,17552; li 5,14; bl _s801D5370_19; beq cr4,24f; lwz 0,0x10(26); cmpwi 0,0; beq 23f; lwz 11,0x218(31); lwz 4,0x4(26); lwz 9,0x0(11); lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,11,3; blrl; extsh 0,3; sth 3,0x8(1); cmpwi 0,-1; beq 23f; addi 29,31,540; lwz 3,0x21c(31); lwz 4,0x4(29); addi 5,1,8; bl _s801D5370_20; lwz 0,0x4(29); cmpw 3,0; bne 23f; lwz 0,0xc(29); addi 25,1,8; cmpw 3,0; beq 12f; lhz 0,0x8(1); sth 0,0x0(3); lwz 9,0x4(29); addi 9,9,2; stw 9,0x4(29); b 23f; 12:; lwz 0,0x21c(31); li 9,1; mr 30,3; stw 9,0x10(1); subf 0,0,30; addi 10,1,16; srawi 9,0,1; addi 11,1,12; stw 9,0xc(1); cmplwi 9,1; bge 13f; mr 11,10; 13:; lwz 0,0x0(11); add. 0,9,0; beq 15f; add 0,0,0; mr 27,0; cmplwi 0,128; ble 14f; mr 3,27; bl _s801D5370_21; mr 28,3; b 16f; 14:; mr 3,27; bl _s801D5370_22; mr 28,3; b 16f; 15:; li 28,0; li 27,0; 16:; lwz 4,0x0(29); cmpw 30,4; beq 17f; subf 30,4,30; mr 3,28; mr 5,30; bl _s801D5370_23; add 0,3,30; b 18f; 17:; mr 0,28; 18:; lwz 9,0x10(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 20f; 19:; lhz 0,0x0(25); sth 0,0x0(30); addi 30,30,2; bdnz 19b; 20:; lwz 3,0x0(29); lwz 0,0xc(29); cmpwi 3,0; subf 0,3,0; srawi 0,0,1; beq 22f; add 4,0,0; cmplwi 4,128; ble 21f; bl _s801D5370_24; b 22f; 21:; bl _s801D5370_25; 22:; add 0,27,28; stw 28,0x0(29); stw 0,0xc(29); stw 30,0x4(29); 23:; beq cr4,24f; mr 3,26; bl _s801D5370_26; stw 3,0x210(31); b 25f; 24:; li 0,0; stw 0,0x210(31); 25:; li 3,1; lwz 0,0x3c(1); lwz 12,0x18(1); mtspr 8,0; lmw 25,0x1c(1); mtcrf 8,12; addi 1,1,56"

extern "C" void _s801D5370_0();
extern "C" void _s801D5370_1();
extern "C" void _s801D5370_2();
extern "C" void _s801D5370_3();
extern "C" void _s801D5370_4();
extern "C" void _s801D5370_5();
extern "C" void _s801D5370_6();
extern "C" void _s801D5370_7();
extern "C" void _s801D5370_8();
extern "C" void _s801D5370_9();
extern "C" void _s801D5370_10();
extern "C" void _s801D5370_11();
extern "C" void _s801D5370_12();
extern "C" void _s801D5370_13();
extern "C" void _s801D5370_14();
extern "C" void _s801D5370_15();
extern "C" void _s801D5370_16();
extern "C" void _s801D5370_17();
extern "C" void _s801D5370_18();
extern "C" void _s801D5370_19();
extern "C" void _s801D5370_20();
extern "C" void _s801D5370_21();
extern "C" void _s801D5370_22();
extern "C" void _s801D5370_23();
extern "C" void _s801D5370_24();
extern "C" void _s801D5370_25();
extern "C" void _s801D5370_26();

struct PCTTarget {
    void on_selection_changed();
};

void PCTTarget::on_selection_changed() {
}
