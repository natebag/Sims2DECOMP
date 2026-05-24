// 0x800C926C Neighbor::GetNumPersistentDataFields(void) (1300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-392(1); mfspr 0,8; stmw 23,0x164(1); stw 0,0x18c(1); lis 23,-32696; addi 31,23,25212; lwz 9,0x627c(23); lwz 0,0x4(31); subf 0,9,0; rlwinm. 9,0,29,3,31; bne 0f; mr 3,31; li 4,43; bl _s800C926C_0; li 29,2; addi 9,1,8; stw 29,0x8(1); li 30,1; mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_1; li 27,3; addi 9,1,16; stw 27,0x10(1); mr 4,9; mr 3,31; stw 30,0x4(9); li 28,4; bl _s800C926C_2; li 26,5; addi 9,1,24; stw 28,0x18(1); mr 4,9; mr 3,31; stw 30,0x4(9); li 25,6; bl _s800C926C_3; li 24,7; addi 9,1,32; stw 26,0x20(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_4; addi 9,1,40; stw 25,0x28(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_5; addi 9,1,48; stw 24,0x30(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_6; li 0,9; addi 9,1,56; stw 0,0x38(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_7; li 0,10; addi 9,1,64; stw 0,0x40(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_8; li 0,11; addi 9,1,72; stw 0,0x48(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_9; li 0,12; addi 9,1,80; stw 0,0x50(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_10; li 0,13; addi 9,1,88; stw 0,0x58(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_11; li 0,14; addi 9,1,96; stw 0,0x60(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_12; li 0,15; addi 9,1,104; stw 0,0x68(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_13; li 0,16; addi 9,1,112; stw 0,0x70(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_14; li 0,17; addi 9,1,120; stw 0,0x78(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_15; li 0,18; addi 9,1,128; stw 0,0x80(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_16; li 0,46; addi 9,1,136; stw 0,0x88(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_17; li 0,47; addi 9,1,144; stw 0,0x90(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_18; li 0,48; addi 9,1,152; stw 0,0x98(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_19; li 0,49; addi 9,1,160; stw 0,0xa0(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_20; li 0,50; addi 9,1,168; stw 0,0xa8(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_21; li 0,51; addi 9,1,176; stw 0,0xb0(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_22; li 0,52; addi 9,1,184; stw 0,0xb8(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_23; li 0,53; addi 9,1,192; stw 0,0xc0(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_24; li 0,54; addi 9,1,200; stw 0,0xc8(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_25; li 0,55; addi 9,1,208; stw 0,0xd0(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_26; li 0,76; addi 9,1,216; stw 0,0xd8(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_27; li 0,77; addi 9,1,224; stw 0,0xe0(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_28; li 0,78; addi 9,1,232; stw 0,0xe8(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_29; li 0,79; addi 9,1,240; stw 0,0xf0(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_30; li 0,58; addi 9,1,248; stw 0,0xf8(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_31; li 0,60; addi 9,1,256; stw 0,0x100(1); mr 4,9; mr 3,31; stw 30,0x4(9); bl _s800C926C_32; li 0,61; addi 9,1,264; stw 0,0x108(1); mr 4,9; stw 30,0x4(9); mr 3,31; bl _s800C926C_33; li 0,56; addi 9,1,272; stw 0,0x110(1); mr 4,9; mr 3,31; stw 29,0x4(9); bl _s800C926C_34; li 0,57; addi 9,1,280; stw 0,0x118(1); mr 4,9; mr 3,31; stw 29,0x4(9); bl _s800C926C_35; li 0,63; addi 9,1,288; stw 0,0x120(1); mr 4,9; stw 29,0x4(9); mr 3,31; bl _s800C926C_36; li 0,65; addi 9,1,296; stw 0,0x128(1); mr 4,9; stw 27,0x4(9); mr 3,31; bl _s800C926C_37; li 0,67; addi 9,1,304; stw 0,0x130(1); mr 4,9; mr 3,31; stw 28,0x4(9); bl _s800C926C_38; li 0,68; addi 9,1,312; stw 0,0x138(1); mr 4,9; stw 28,0x4(9); mr 3,31; bl _s800C926C_39; li 0,69; addi 9,1,320; stw 0,0x140(1); mr 4,9; stw 26,0x4(9); mr 3,31; bl _s800C926C_40; li 0,74; addi 9,1,328; stw 0,0x148(1); mr 4,9; stw 25,0x4(9); mr 3,31; bl _s800C926C_41; li 0,70; addi 9,1,336; stw 0,0x150(1); mr 4,9; stw 24,0x4(9); mr 3,31; bl _s800C926C_42; li 9,20; addi 4,1,344; stw 9,0x158(1); li 0,8; stw 0,0x4(4); mr 3,31; bl _s800C926C_43; 0:; lwz 3,0x4(31); lwz 0,0x627c(23); subf 3,0,3; srawi 3,3,3; lwz 0,0x18c(1); mtspr 8,0; lmw 23,0x164(1); addi 1,1,392"

extern "C" void _s800C926C_0();
extern "C" void _s800C926C_1();
extern "C" void _s800C926C_2();
extern "C" void _s800C926C_3();
extern "C" void _s800C926C_4();
extern "C" void _s800C926C_5();
extern "C" void _s800C926C_6();
extern "C" void _s800C926C_7();
extern "C" void _s800C926C_8();
extern "C" void _s800C926C_9();
extern "C" void _s800C926C_10();
extern "C" void _s800C926C_11();
extern "C" void _s800C926C_12();
extern "C" void _s800C926C_13();
extern "C" void _s800C926C_14();
extern "C" void _s800C926C_15();
extern "C" void _s800C926C_16();
extern "C" void _s800C926C_17();
extern "C" void _s800C926C_18();
extern "C" void _s800C926C_19();
extern "C" void _s800C926C_20();
extern "C" void _s800C926C_21();
extern "C" void _s800C926C_22();
extern "C" void _s800C926C_23();
extern "C" void _s800C926C_24();
extern "C" void _s800C926C_25();
extern "C" void _s800C926C_26();
extern "C" void _s800C926C_27();
extern "C" void _s800C926C_28();
extern "C" void _s800C926C_29();
extern "C" void _s800C926C_30();
extern "C" void _s800C926C_31();
extern "C" void _s800C926C_32();
extern "C" void _s800C926C_33();
extern "C" void _s800C926C_34();
extern "C" void _s800C926C_35();
extern "C" void _s800C926C_36();
extern "C" void _s800C926C_37();
extern "C" void _s800C926C_38();
extern "C" void _s800C926C_39();
extern "C" void _s800C926C_40();
extern "C" void _s800C926C_41();
extern "C" void _s800C926C_42();
extern "C" void _s800C926C_43();

struct Neighbor {
    void GetNumPersistentDataFields();
};

void Neighbor::GetNumPersistentDataFields() {
}
