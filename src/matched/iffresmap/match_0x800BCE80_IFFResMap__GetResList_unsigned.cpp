// 0x800BCE80 IFFResMap::GetResList(unsigned (732 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 24,0x30(1); stw 0,0x54(1); mr 28,3; lwz 9,0x4(28); lwz 3,0x0(28); b 1f; 0:; addi 3,3,24; 1:; cmpw 3,9; beq 2f; lwz 0,0x10(3); cmpw 0,4; bne 0b; 2:; cmpwi 5,0; beq 27f; lwz 0,0x4(28); cmpw 3,0; bne 27f; li 0,0; addi 29,1,8; stw 0,0x8(1); addi 9,29,8; stw 0,0x4(29); mr 24,29; lwz 11,0xc(28); stw 0,0x4(9); stw 4,0x10(29); cmpw 3,11; stw 0,0x14(29); beq 3f; mr 4,24; bl _s800BCE80_0; lwz 9,0x4(28); addi 9,9,24; stw 9,0x4(28); b 22f; 3:; lwz 0,0x0(28); mr 27,3; lis 9,-21846; li 11,1; ori 9,9,43691; subf 0,0,27; mullw 0,0,9; stw 11,0x2c(1); addi 10,1,44; addi 11,1,40; srawi 9,0,3; stw 9,0x28(1); cmplwi 9,1; bge 4f; mr 11,10; 4:; lwz 0,0x0(11); add. 0,9,0; beq 6f; mulli 0,0,24; mr 26,0; cmplwi 0,128; ble 5f; mr 3,26; bl _s800BCE80_1; b 7f; 5:; mr 3,26; bl _s800BCE80_2; b 7f; 6:; li 3,0; li 26,0; 7:; mr 30,3; lwz 31,0x0(28); mr 25,30; cmpw 31,27; beq 9f; 8:; mr 3,30; mr 4,31; bl _s800BCE80_3; addi 31,31,24; addi 30,30,24; cmpw 31,27; bne 8b; 9:; lwz 0,0x2c(1); cmpwi 0,1; bne 10f; mr 3,30; mr 4,29; bl _s800BCE80_4; addi 30,30,24; b 13f; 10:; mr 31,30; mr. 30,0; beq 12f; 11:; mr 3,31; mr 4,29; bl _s800BCE80_5; addi 31,31,24; addic. 30,30,-1; bne 11b; 12:; mr 30,31; 13:; lwz 27,0x4(28); lwz 11,0x0(28); cmpw 11,27; beq 19f; lis 31,-17874; ori 31,31,35747; 14:; lwz 9,0x0(11); addi 29,11,24; lwz 0,0x4(11); mr 3,9; cmpw 9,0; beq 16f; 15:; addi 9,9,88; cmpw 9,0; bne 15b; 16:; cmpwi 3,0; beq 18f; lwz 0,0xc(11); subf 0,3,0; mullw 0,0,31; srawi 0,0,3; mulli 4,0,88; cmplwi 4,128; ble 17f; bl _s800BCE80_6; b 18f; 17:; bl _s800BCE80_7; 18:; mr 11,29; cmpw 11,27; bne 14b; 19:; lwz 3,0x0(28); lis 9,-21846; lwz 0,0xc(28); ori 9,9,43691; cmpwi 3,0; subf 0,3,0; mullw 0,0,9; srawi 0,0,3; beq 21f; mulli 4,0,24; cmplwi 4,128; ble 20f; bl _s800BCE80_8; b 21f; 20:; bl _s800BCE80_9; 21:; add 0,26,25; stw 25,0x0(28); stw 30,0x4(28); stw 0,0xc(28); 22:; lwz 0,0x4(24); lwz 9,0x8(1); cmpw 9,0; beq 24f; 23:; addi 9,9,88; cmpw 9,0; bne 23b; 24:; lwz 3,0x0(24); cmpwi 3,0; beq 26f; lwz 0,0xc(24); lis 9,-17874; ori 9,9,35747; subf 0,3,0; mullw 0,0,9; srawi 0,0,3; mulli 4,0,88; cmplwi 4,128; ble 25f; bl _s800BCE80_10; b 26f; 25:; bl _s800BCE80_11; 26:; lwz 11,0x0(28); lis 9,-21846; lwz 0,0x4(28); ori 9,9,43691; subf 0,11,0; mullw 0,0,9; srawi 0,0,3; mulli 0,0,24; add 11,11,0; addi 3,11,-24; 27:; lwz 0,0x54(1); mtspr 8,0; lmw 24,0x30(1); addi 1,1,80"

extern "C" void _s800BCE80_0();
extern "C" void _s800BCE80_1();
extern "C" void _s800BCE80_2();
extern "C" void _s800BCE80_3();
extern "C" void _s800BCE80_4();
extern "C" void _s800BCE80_5();
extern "C" void _s800BCE80_6();
extern "C" void _s800BCE80_7();
extern "C" void _s800BCE80_8();
extern "C" void _s800BCE80_9();
extern "C" void _s800BCE80_10();
extern "C" void _s800BCE80_11();

struct IFFResMap {
    void GetResList();
};

void IFFResMap::GetResList() {
}
