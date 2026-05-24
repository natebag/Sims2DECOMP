// 0x800D6774 NghResFile::SaveHouseContents(unsigned (972 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-128(1); mfspr 0,8; stmw 14,0x38(1); stw 0,0x84(1); mr 18,3; mr 15,4; stw 5,0x2c(1); bl _s800D6774_0; cmpwi 3,0; bne 0f; li 3,0; b 4f; 0:; lwz 9,0x24(18); addi 29,1,16; mr 4,15; mr 3,18; addi 9,9,1; stw 9,0x30(1); bl _s800D6774_1; lis 9,-32696; addi 19,1,20; addi 14,9,25388; addi 20,1,24; lwz 9,0x4(14); addi 21,1,28; addi 23,1,32; addi 22,1,36; addi 24,1,40; lwz 16,0x7c(9); bl _s800D6774_2; li 6,0; li 7,0; mr 4,16; li 5,64; bl _s800D6774_3; mr 17,3; mr 5,16; li 4,0; bl _s800D6774_4; lis 4,16754; mr 3,18; ori 4,4,29305; bl _s800D6774_5; lwz 3,0x0(3); mr 4,29; bl _s800D6774_6; addi 3,3,3; lis 4,28514; rlwinm 28,3,0,0,29; lwz 30,0x10(1); ori 4,4,27252; mr 3,18; bl _s800D6774_7; lwz 3,0x0(3); mr 4,29; bl _s800D6774_8; lwz 0,0x10(1); add 28,28,3; addi 9,28,3; lis 4,20322; add 30,30,0; rlwinm 28,9,0,0,29; ori 4,4,27213; mr 3,18; bl _s800D6774_9; lwz 3,0x0(3); mr 4,29; bl _s800D6774_10; lwz 0,0x10(1); add 28,28,3; addi 9,28,3; lis 4,17493; add 30,30,0; rlwinm 28,9,0,0,29; ori 4,4,19792; mr 3,18; bl _s800D6774_11; lwz 3,0x0(3); mr 4,29; bl _s800D6774_12; lwz 9,0x10(1); add 28,28,3; addi 0,28,3; add 30,30,9; rlwinm 28,0,0,0,29; mulli 29,30,14; addi 0,29,3; rlwinm 29,0,0,0,29; bl _s800D6774_13; addi 25,29,28; add 4,28,25; li 5,64; li 6,0; li 7,0; bl _s800D6774_14; mr 31,3; rlwinm 11,30,2,0,29; addi 26,31,28; li 0,3; stw 0,0x0(31); add 10,28,29; add 27,26,11; li 0,0; add 28,27,11; li 29,28; li 9,8; stw 0,0xc(31); stw 0,0x10(31); add 11,28,11; stw 10,0x8(31); lis 5,16754; stw 9,0x14(31); mr 3,18; stw 30,0x18(31); mr 4,31; stw 29,0x4(31); ori 5,5,29305; stw 29,0x28(1); mr 6,19; stw 25,0x24(1); mr 7,20; stw 11,0x20(1); mr 8,21; stw 24,0x8(1); mr 9,23; stw 26,0x14(1); mr 10,22; stw 27,0x18(1); stw 28,0x1c(1); bl _s800D6774_15; lis 5,28514; stw 24,0x8(1); mr 3,18; mr 4,31; ori 5,5,27252; mr 6,19; mr 7,20; mr 8,21; mr 9,23; mr 10,22; bl _s800D6774_16; lis 5,20322; stw 24,0x8(1); mr 3,18; mr 4,31; ori 5,5,27213; mr 6,19; mr 7,20; mr 8,21; mr 9,23; mr 10,22; bl _s800D6774_17; lis 5,17493; mr 3,18; stw 24,0x8(1); mr 6,19; mr 7,20; mr 8,21; mr 9,23; mr 10,22; mr 4,31; ori 5,5,19792; bl _s800D6774_18; lwz 3,0x4(31); lwz 4,0x8(31); add 30,17,3; subf 6,3,16; add 3,31,3; mr 5,30; bl _s800D6774_19; mr. 0,3; bgt 1f; bl _s800D6774_20; mr 4,31; bl _s800D6774_21; bl _s800D6774_22; mr 4,17; bl _s800D6774_23; li 3,-4; b 4f; 1:; lwz 3,0x4(31); mr 4,31; stw 0,0xc(31); mr 5,3; subf 3,3,30; crxor 6,6,6; bl _s800D6774_24; bl _s800D6774_25; mr 4,31; bl _s800D6774_26; lwz 0,0xc(17); li 9,0; lwz 4,0x4(17); mr 3,17; stw 9,0x10(17); add 4,0,4; bl _s800D6774_27; lwz 0,0x2c(1); lwz 11,0xc(17); lwz 9,0x4(17); cmpwi 0,0; stw 3,0x10(17); add 31,11,9; addi 0,31,1023; rlwinm 31,0,0,0,21; beq 2f; lwz 3,0x2c(1); mr 5,16; mr 4,17; li 31,1; bl _s800D6774_28; b 3f; 2:; addi 0,15,-1; lwz 9,0x4(14); mullw 0,0,16; lwz 30,0x80(9); add 30,30,0; mr 3,18; bl _s800D6774_29; mr 7,31; mr 4,14; mr 6,30; mr 5,17; bl _s800D6774_30; subfic 0,3,0; adde 31,0,3; cmpwi 31,1; beq 3f; lhz 9,0x184(18); addi 9,9,-1; sth 9,0x184(18); 3:; bl _s800D6774_31; mr 4,17; bl _s800D6774_32; lwz 4,0x30(1); mr 3,18; bl _s800D6774_33; mr 3,31; 4:; lwz 0,0x84(1); mtspr 8,0; lmw 14,0x38(1); addi 1,1,128"

extern "C" void _s800D6774_0();
extern "C" void _s800D6774_1();
extern "C" void _s800D6774_2();
extern "C" void _s800D6774_3();
extern "C" void _s800D6774_4();
extern "C" void _s800D6774_5();
extern "C" void _s800D6774_6();
extern "C" void _s800D6774_7();
extern "C" void _s800D6774_8();
extern "C" void _s800D6774_9();
extern "C" void _s800D6774_10();
extern "C" void _s800D6774_11();
extern "C" void _s800D6774_12();
extern "C" void _s800D6774_13();
extern "C" void _s800D6774_14();
extern "C" void _s800D6774_15();
extern "C" void _s800D6774_16();
extern "C" void _s800D6774_17();
extern "C" void _s800D6774_18();
extern "C" void _s800D6774_19();
extern "C" void _s800D6774_20();
extern "C" void _s800D6774_21();
extern "C" void _s800D6774_22();
extern "C" void _s800D6774_23();
extern "C" void _s800D6774_24();
extern "C" void _s800D6774_25();
extern "C" void _s800D6774_26();
extern "C" void _s800D6774_27();
extern "C" void _s800D6774_28();
extern "C" void _s800D6774_29();
extern "C" void _s800D6774_30();
extern "C" void _s800D6774_31();
extern "C" void _s800D6774_32();
extern "C" void _s800D6774_33();

struct NghResFile {
    void SaveHouseContents();
};

void NghResFile::SaveHouseContents() {
}
