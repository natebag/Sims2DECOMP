// 0x800EF4FC ObjectFolderImpl::SaveUserData(iResFile (1260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-464(1); mfspr 0,8; stmw 21,0x1a4(1); stw 0,0x1d4(1); li 0,0; addi 9,1,8; stw 0,0x4(9); addi 11,1,24; stw 0,0x8(9); addi 10,1,32; stw 0,0x18(1); mr 29,9; stw 0,0x4(11); addi 9,1,64; stw 0,0x4(10); addi 11,3,64; stw 0,0x4(9); mr 23,4; stw 0,0x8(9); addi 10,1,48; stw 11,0x40(1); addi 26,1,80; stw 0,0x4(9); lwz 9,0x44(1); cmpwi 9,255; bgt 1f; lwz 11,0x40(1); rlwinm 9,9,2,0,29; lwzx 9,11,9; cmpwi 9,0; beq 0f; stw 9,0x48(1); b 1f; 0:; lwz 9,0x44(1); addi 0,9,1; stw 0,0x44(1); cmpwi 0,255; bgt 1f; lwz 9,0x40(1); rlwinm 0,0,2,0,29; lwzx 0,9,0; cmpwi 0,0; beq 0b; stw 0,0x48(1); 1:; lwz 11,0x40(1); lwz 0,0x44(1); lwz 9,0x48(1); stw 0,0x34(1); stw 9,0x38(1); stw 11,0x30(1); lwz 9,0x8(10); lwz 0,0x4(10); stw 11,0x8(1); stw 0,0x4(29); stw 9,0x8(29); addi 25,3,64; b 19f; 2:; lwz 0,0x8(29); mr 3,0; stw 0,0x188(1); bl _s800EF4FC_0; cmpwi 3,0; li 0,1; bne 3f; li 0,0; 3:; cmpwi 0,0; beq 15f; lwz 11,0x1c(1); addi 27,1,392; lwz 0,0x24(1); mr 30,11; cmpw 11,0; beq 4f; lwz 0,0x188(1); stw 0,0x0(11); lwz 9,0x1c(1); addi 9,9,4; stw 9,0x1c(1); b 15f; 4:; lwz 9,0x18(1); li 0,1; stw 0,0x190(1); subf 9,9,11; addi 0,1,400; srawi 9,9,2; addi 11,1,396; stw 9,0x18c(1); cmplwi 9,1; bge 5f; mr 11,0; 5:; lwz 0,0x0(11); add. 3,9,0; beq 7f; rlwinm 3,3,2,0,29; cmplwi 3,128; mr 28,3; ble 6f; bl _s800EF4FC_1; mr 31,3; b 8f; 6:; bl _s800EF4FC_2; mr 31,3; b 8f; 7:; li 31,0; li 28,0; 8:; lwz 4,0x18(1); cmpw 30,4; beq 9f; subf 30,4,30; mr 3,31; mr 5,30; bl _s800EF4FC_3; add 3,3,30; b 10f; 9:; mr 3,31; 10:; lwz 0,0x190(1); mr 30,3; mtspr 9,0; cmpwi 0,0; beq 12f; 11:; lwz 0,0x0(27); stw 0,0x0(30); addi 30,30,4; bdnz 11b; 12:; lwz 3,0x18(1); lwz 0,0x24(1); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 14f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 13f; bl _s800EF4FC_4; b 14f; 13:; bl _s800EF4FC_5; 14:; add 0,28,31; stw 31,0x18(1); stw 30,0x1c(1); stw 0,0x24(1); 15:; lwz 9,0x8(29); cmpwi 9,0; beq 17f; lwz 0,0xa4(9); cmpwi 0,0; stw 0,0x8(29); bne 16f; lwz 9,0x4(29); addi 9,9,1; stw 9,0x4(29); 16:; lwz 0,0x8(29); cmpwi 0,0; bne 19f; 17:; lwz 9,0x4(29); cmpwi 9,255; bgt 19f; lwz 11,0x0(29); rlwinm 9,9,2,0,29; lwzx 9,11,9; cmpwi 9,0; beq 18f; stw 9,0x8(29); b 19f; 18:; lwz 9,0x4(29); addi 0,9,1; stw 0,0x4(29); cmpwi 0,255; bgt 19f; lwz 9,0x0(29); rlwinm 0,0,2,0,29; lwzx 0,9,0; cmpwi 0,0; beq 18b; stw 0,0x8(29); 19:; li 0,0; li 9,256; stw 0,0x4(26); li 8,0; stw 0,0x8(26); stw 25,0x50(1); stw 9,0x4(26); lwz 0,0x4(29); lwz 9,0x54(1); lwz 10,0x50(1); lwz 11,0x58(1); cmpw 0,9; stw 10,0x28(1); stw 9,0x2c(1); stw 11,0x30(1); bne 20f; lwz 0,0x8(29); cmpw 0,11; bne 20f; lwz 0,0x8(1); xor 8,0,10; subfic 9,8,0; adde 8,9,8; 20:; cmpwi 8,0; beq 2b; lwz 3,0x18(1); lis 5,-32709; lwz 4,0x1c(1); addi 5,5,-32352; li 31,0; li 28,1; bl _s800EF4FC_6; lwz 0,0x1c(1); lwz 9,0x18(1); subf 0,9,0; srawi 24,0,2; cmpw 31,24; bge 24f; addi 21,1,96; addi 27,1,404; addi 22,1,408; 21:; lwz 11,0x18(1); rlwinm 9,31,2,0,29; addi 3,1,100; addi 25,28,1; lwzx 30,11,9; addi 26,31,1; bl _s800EF4FC_7; li 29,288; stw 30,0x19c(1); mr 3,30; bl _s800EF4FC_8; stw 3,0x60(1); mr 3,30; bl _s800EF4FC_9; extsh 6,28; addi 9,1,100; 22:; lwz 0,0x0(3); addic. 29,29,-24; stw 0,0x0(9); lwz 0,0x4(3); stw 0,0x4(9); lwz 0,0x8(3); stw 0,0x8(9); lwz 0,0xc(3); stw 0,0xc(9); lwz 0,0x10(3); stw 0,0x10(9); lwz 0,0x14(3); addi 3,3,24; stw 0,0x14(9); addi 9,9,24; bne 22b; lwz 0,0x0(3); lis 5,21875; lwz 7,-32040(13); mr 4,23; stw 0,0x0(9); ori 5,5,25970; mr 3,21; bl _s800EF4FC_10; mr 3,30; bl _s800EF4FC_11; mr 30,3; stw 29,0x198(1); lwz 3,-21476(13); mr 4,30; mr 5,27; mr 6,22; lwz 9,0x0(3); stw 29,0x194(1); lha 0,0xc8(9); lwz 9,0xcc(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 23f; mr 3,30; mr 4,27; bl _s800EF4FC_12; cmpwi 3,0; beq 23f; lwz 4,0x194(1); lwz 5,0x198(1); lwz 3,-32056(13); bl _s800EF4FC_13; extsh 6,3; lis 5,29800; lwz 7,-32040(13); addi 3,1,412; mr 4,23; ori 5,5,28002; bl _s800EF4FC_14; cmpwi 3,0; bne 23f; lwz 3,-32056(13); mr 6,30; lwz 4,0x194(1); lwz 5,0x198(1); bl _s800EF4FC_15; 23:; mr 31,26; mr 28,25; cmpw 31,24; blt 21b; 24:; lwz 3,0x18(1); cmpwi 3,0; beq 26f; lwz 0,0x24(1); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 25f; bl _s800EF4FC_16; b 26f; 25:; bl _s800EF4FC_17; 26:; lwz 0,0x1d4(1); mtspr 8,0; lmw 21,0x1a4(1); addi 1,1,464"

extern "C" void _s800EF4FC_0();
extern "C" void _s800EF4FC_1();
extern "C" void _s800EF4FC_2();
extern "C" void _s800EF4FC_3();
extern "C" void _s800EF4FC_4();
extern "C" void _s800EF4FC_5();
extern "C" void _s800EF4FC_6();
extern "C" void _s800EF4FC_7();
extern "C" void _s800EF4FC_8();
extern "C" void _s800EF4FC_9();
extern "C" void _s800EF4FC_10();
extern "C" void _s800EF4FC_11();
extern "C" void _s800EF4FC_12();
extern "C" void _s800EF4FC_13();
extern "C" void _s800EF4FC_14();
extern "C" void _s800EF4FC_15();
extern "C" void _s800EF4FC_16();
extern "C" void _s800EF4FC_17();

struct ObjectFolderImpl {
    void SaveUserData();
};

void ObjectFolderImpl::SaveUserData() {
}
