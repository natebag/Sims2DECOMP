// 0x800D8330 NghResFile::CopyDefaultNghToCard(char (692 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-392(1); mfspr 0,8; stmw 20,0x158(1); stw 0,0x18c(1); addi 29,1,8; mr 25,3; mr 30,4; mr 21,5; mr 20,6; addi 4,29,8; li 5,260; mr 3,29; bl _s800D8330_0; mr 4,30; mr 5,29; mr 3,25; bl _s800D8330_1; mr 3,29; bl _s800D8330_2; lis 4,-32706; addi 4,4,-21732; bl _s800D8330_3; mr. 24,3; li 3,-7; beq 9f; li 4,0; li 5,2; mr 3,24; li 23,1; bl _s800D8330_4; mr 3,24; bl _s800D8330_5; mr 30,3; li 4,0; mr 3,24; li 5,0; bl _s800D8330_6; li 0,0; sth 0,0x184(25); mr 26,30; lis 29,-32696; li 27,0; addi 29,29,25388; lwz 30,0x14(29); bl _s800D8330_7; mr 4,30; li 5,64; li 6,0; li 7,0; bl _s800D8330_8; stw 29,0x118(1); addi 9,1,280; li 0,0; mr 31,3; stw 0,0xc(9); stw 0,0x4(9); stw 0,0x8(9); mr 22,9; b 5f; 0:; lis 9,-32696; addi 28,9,25388; lwz 11,0x4(28); lwz 0,0x68(11); cmpw 27,0; bne 1f; addi 30,1,296; mr 4,31; li 5,28; mr 3,30; bl _s800D8330_9; mr 3,30; bl _s800D8330_10; addi 3,1,300; bl _s800D8330_11; addi 3,1,304; bl _s800D8330_12; addi 3,1,308; bl _s800D8330_13; addi 3,1,312; bl _s800D8330_14; addi 3,1,316; bl _s800D8330_15; addi 3,1,320; bl _s800D8330_16; 1:; li 0,0; addi 30,1,328; stw 0,0x148(1); mr 3,28; stw 0,0x4(30); mr 4,27; addi 5,1,336; addi 6,1,340; bl _s800D8330_17; cmpwi 3,0; bne 2f; mr 3,25; bl _s800D8330_18; mr 4,28; mr 5,31; mr 6,27; mr 7,29; bl _s800D8330_19; cmpwi 3,0; beq 3f; b 6f; 2:; stw 31,0x4(30); mr 6,30; stw 29,0x148(1); mr 3,25; lwz 4,0x150(1); lwz 5,0x154(1); bl _s800D8330_20; 3:; lwz 6,0x11c(1); subf 26,29,26; lwz 8,0x118(1); add 27,27,29; mulli 10,6,24; lwz 11,0x124(1); lwz 9,0x4(8); lwz 7,0x120(1); add 9,10,9; lwz 0,0x4(9); add 11,11,0; stw 11,0x124(1); lwz 9,0x4(8); lwzx 9,9,10; addi 0,9,-1; cmpw 7,0; bge 4f; addi 0,7,1; stw 0,0x120(1); b 5f; 4:; cmpwi 9,0; ble 5f; addi 0,6,1; li 9,0; stw 0,0x11c(1); stw 9,0x8(22); 5:; cmpwi 26,0; beq 7f; lwz 9,0x11c(1); mr 3,31; lwz 11,0x118(1); li 4,1; mulli 9,9,24; mr 6,24; lwz 0,0x4(11); add 9,9,0; lwz 29,0x4(9); mr 5,29; bl _s800D8330_21; cmpw 29,3; beq 0b; 6:; li 23,0; 7:; bl _s800D8330_22; mr 4,31; bl _s800D8330_23; cmpwi 23,1; bne 8f; mr 4,21; addi 3,25,40; bl _s800D8330_24; li 0,0; stb 20,0x134(25); stw 0,0x20(25); 8:; mr 3,24; bl _s800D8330_25; mr 3,23; 9:; lwz 0,0x18c(1); mtspr 8,0; lmw 20,0x158(1); addi 1,1,392"

extern "C" void _s800D8330_0();
extern "C" void _s800D8330_1();
extern "C" void _s800D8330_2();
extern "C" void _s800D8330_3();
extern "C" void _s800D8330_4();
extern "C" void _s800D8330_5();
extern "C" void _s800D8330_6();
extern "C" void _s800D8330_7();
extern "C" void _s800D8330_8();
extern "C" void _s800D8330_9();
extern "C" void _s800D8330_10();
extern "C" void _s800D8330_11();
extern "C" void _s800D8330_12();
extern "C" void _s800D8330_13();
extern "C" void _s800D8330_14();
extern "C" void _s800D8330_15();
extern "C" void _s800D8330_16();
extern "C" void _s800D8330_17();
extern "C" void _s800D8330_18();
extern "C" void _s800D8330_19();
extern "C" void _s800D8330_20();
extern "C" void _s800D8330_21();
extern "C" void _s800D8330_22();
extern "C" void _s800D8330_23();
extern "C" void _s800D8330_24();
extern "C" void _s800D8330_25();

struct NghResFile {
    void CopyDefaultNghToCard();
};

void NghResFile::CopyDefaultNghToCard() {
}
