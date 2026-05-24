// 0x800F03E4 ObjectFolderImpl::PrepareForModuleSave(iResFile (1184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-168(1); mfspr 0,8; stmw 17,0x6c(1); stw 0,0xac(1); mr 23,3; li 9,0; lwz 0,0x670(23); addi 31,23,1648; mr 28,31; mr 17,4; stw 0,0x674(23); li 19,1; stw 9,0x48(1); addi 22,1,72; lwz 30,0x4(31); lwz 0,0xc(31); cmpw 30,0; beq 0f; stw 9,0x0(30); addi 29,1,8; addi 26,1,40; addi 20,23,64; lwz 9,0x4(28); addi 24,1,24; addi 21,1,56; addi 18,1,96; addi 9,9,4; stw 9,0x4(28); b 11f; 0:; lwz 0,0x670(23); li 9,1; stw 9,0x50(1); addi 10,1,80; subf 0,0,30; addi 11,1,76; srawi 9,0,2; stw 9,0x4c(1); cmplwi 9,1; bge 1f; mr 11,10; 1:; lwz 0,0x0(11); add. 0,9,0; beq 3f; rlwinm 0,0,2,0,29; mr 25,0; cmplwi 0,128; ble 2f; mr 3,25; bl _s800F03E4_0; mr 27,3; b 4f; 2:; mr 3,25; bl _s800F03E4_1; mr 27,3; b 4f; 3:; li 27,0; li 25,0; 4:; lwz 4,0x0(31); cmpw 30,4; beq 5f; subf 30,4,30; mr 3,27; mr 5,30; bl _s800F03E4_2; add 0,3,30; b 6f; 5:; mr 0,27; 6:; lwz 9,0x50(1); mr 30,0; addi 29,1,8; addi 26,1,40; mtspr 9,9; addi 20,23,64; addi 24,1,24; addi 21,1,56; addi 18,1,96; cmpwi 9,0; beq 8f; 7:; lwz 0,0x0(22); stw 0,0x0(30); addi 30,30,4; bdnz 7b; 8:; lwz 3,0x0(31); lwz 0,0xc(31); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 10f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 9f; bl _s800F03E4_3; b 10f; 9:; bl _s800F03E4_4; 10:; add 0,25,27; stw 27,0x0(31); stw 0,0xc(31); stw 30,0x4(31); 11:; li 0,0; stw 0,0x4(29); stw 0,0x8(29); stw 0,0x4(26); stw 0,0x8(26); stw 20,0x28(1); stw 0,0x4(26); lwz 9,0x2c(1); cmpwi 9,255; bgt 13f; lwz 11,0x28(1); rlwinm 9,9,2,0,29; lwzx 9,11,9; cmpwi 9,0; beq 12f; stw 9,0x30(1); b 13f; 12:; lwz 9,0x2c(1); addi 0,9,1; stw 0,0x2c(1); cmpwi 0,255; bgt 13f; lwz 9,0x28(1); rlwinm 0,0,2,0,29; lwzx 0,9,0; cmpwi 0,0; beq 12b; stw 0,0x30(1); 13:; lwz 11,0x28(1); mr 25,21; lwz 9,0x2c(1); li 21,0; lwz 0,0x30(1); mr 22,28; stw 9,0x1c(1); stw 0,0x20(1); stw 11,0x18(1); lwz 9,0x8(24); lwz 0,0x4(24); stw 11,0x8(1); stw 0,0x4(29); stw 9,0x8(29); b 31f; 14:; lwz 11,0x8(29); lwz 0,0x68(11); cmpwi 0,0; ble 26f; mr 9,19; addi 26,1,84; sth 9,0x6c(11); addi 9,9,1; lwz 3,0x8(29); extsh 19,9; bl _s800F03E4_5; lwz 9,0x4(22); lwz 0,0xc(22); stw 3,0x54(1); cmpw 9,0; beq 15f; stw 3,0x0(9); lwz 9,0x4(28); addi 9,9,4; stw 9,0x4(28); b 27f; 15:; lwz 30,0x4(28); li 9,1; lwz 0,0x670(23); addi 11,1,92; stw 9,0x5c(1); addi 10,1,88; subf 0,0,30; srawi 9,0,2; stw 9,0x58(1); cmplwi 9,1; bge 16f; mr 10,11; 16:; lwz 0,0x0(10); add. 3,9,0; beq 18f; rlwinm 3,3,2,0,29; cmplwi 3,128; mr 27,3; ble 17f; bl _s800F03E4_6; mr 31,3; b 19f; 17:; bl _s800F03E4_7; mr 31,3; b 19f; 18:; li 31,0; li 27,0; 19:; lwz 4,0x0(28); cmpw 30,4; beq 20f; subf 30,4,30; mr 3,31; mr 5,30; bl _s800F03E4_8; add 0,3,30; b 21f; 20:; mr 0,31; 21:; lwz 9,0x5c(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 23f; 22:; lwz 0,0x0(26); stw 0,0x0(30); addi 30,30,4; bdnz 22b; 23:; lwz 3,0x0(28); lwz 0,0xc(28); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 25f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 24f; bl _s800F03E4_9; b 25f; 24:; bl _s800F03E4_10; 25:; add 0,27,31; stw 31,0x0(28); stw 30,0x4(28); stw 0,0xc(28); b 27f; 26:; sth 21,0x6c(11); 27:; lwz 9,0x8(29); cmpwi 9,0; beq 29f; lwz 0,0xa4(9); cmpwi 0,0; stw 0,0x8(29); bne 28f; lwz 9,0x4(29); addi 9,9,1; stw 9,0x4(29); 28:; lwz 0,0x8(29); cmpwi 0,0; bne 31f; 29:; lwz 9,0x4(29); cmpwi 9,255; bgt 31f; lwz 11,0x0(29); rlwinm 9,9,2,0,29; lwzx 9,11,9; cmpwi 9,0; beq 30f; stw 9,0x8(29); b 31f; 30:; lwz 9,0x4(29); addi 0,9,1; stw 0,0x4(29); cmpwi 0,255; bgt 31f; lwz 9,0x0(29); rlwinm 0,0,2,0,29; lwzx 0,9,0; cmpwi 0,0; beq 30b; stw 0,0x8(29); 31:; stw 21,0x4(25); li 0,256; stw 21,0x8(25); li 8,0; stw 20,0x38(1); stw 0,0x4(25); lwz 9,0x3c(1); lwz 10,0x38(1); lwz 11,0x40(1); stw 10,0x18(1); stw 9,0x1c(1); stw 11,0x20(1); lwz 0,0x4(29); cmpw 0,9; bne 32f; lwz 0,0x8(29); cmpw 0,11; bne 32f; lwz 0,0x8(1); xor 8,0,10; subfic 9,8,0; adde 8,9,8; 32:; cmpwi 8,0; beq 14b; lwz 5,-31844(13); mr 3,18; lha 6,-31838(13); mr 4,17; stw 23,0x60(1); li 7,2; bl _s800F03E4_11; lwz 0,0xac(1); mtspr 8,0; lmw 17,0x6c(1); addi 1,1,168"

extern "C" void _s800F03E4_0();
extern "C" void _s800F03E4_1();
extern "C" void _s800F03E4_2();
extern "C" void _s800F03E4_3();
extern "C" void _s800F03E4_4();
extern "C" void _s800F03E4_5();
extern "C" void _s800F03E4_6();
extern "C" void _s800F03E4_7();
extern "C" void _s800F03E4_8();
extern "C" void _s800F03E4_9();
extern "C" void _s800F03E4_10();
extern "C" void _s800F03E4_11();

struct ObjectFolderImpl {
    void PrepareForModuleSave();
};

void ObjectFolderImpl::PrepareForModuleSave() {
}
