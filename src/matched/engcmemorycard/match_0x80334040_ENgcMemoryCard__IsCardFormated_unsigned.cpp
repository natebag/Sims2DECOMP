// 0x80334040 ENgcMemoryCard::IsCardFormated(unsigned (936 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; mfcr 12; stmw 26,0x18(1); stw 0,0x34(1); stw 12,0x14(1); li 0,0; mr 26,3; mr 30,4; mr 27,5; stw 0,0xc(1); stw 0,0x8(1); bl _s80334040_0; addi 28,1,8; addi 29,1,12; 0:; mr 3,30; mr 4,28; mr 5,29; bl _s80334040_1; cmpwi 3,-7; beq 13f; bgt 2f; cmpwi 3,-12; beq 13f; bgt 1f; cmpwi 3,-14; beq 12f; bgt 11f; cmpwi 3,-128; b 13f; 1:; cmpwi 3,-10; beq 13f; blt 10f; cmpwi 3,-9; beq 10f; cmpwi 3,-8; b 13f; 2:; cmpwi 3,-3; beq 6f; bgt 3f; cmpwi 3,-5; beq 8f; bgt 7f; b 9f; 3:; cmpwi 7,3,-1; beq cr7,14f; blt cr7,5f; cmpwi 3,0; beq 4f; cmpwi 3,1; b 14f; 4:; li 31,1; b 15f; 5:; li 31,-9; b 15f; 6:; cmpwi 7,3,-1; li 31,-1; b 15f; 7:; cmpwi 7,3,-1; li 31,-7; b 15f; 8:; li 0,1; cmpwi 7,3,-1; stw 0,-26380(13); li 31,-8; b 15f; 9:; cmpwi 7,3,-1; li 31,-4; b 15f; 10:; cmpwi 7,3,-1; li 31,-3; b 15f; 11:; cmpwi 7,3,-1; li 31,-6; b 15f; 12:; cmpwi 7,3,-1; li 31,-5; b 15f; 13:; cmpwi 7,3,-1; 14:; li 31,0; 15:; beq cr7,0b; cmpwi 31,1; bne 48f; lis 4,-32692; mr 3,30; addi 4,4,29280; li 5,0; bl _s80334040_2; cmpwi 3,-7; beq 28f; bgt 18f; cmpwi 3,-12; beq 28f; bgt 17f; cmpwi 3,-14; beq 27f; bgt 26f; cmpwi 3,-128; 16:; beq 28f; cmpwi 4,3,0; b 29f; 17:; cmpwi 3,-10; beq 28f; blt 25f; cmpwi 3,-9; beq 25f; cmpwi 3,-8; b 16b; 18:; cmpwi 3,-3; beq 21f; bgt 19f; cmpwi 3,-5; beq 23f; bgt 22f; b 24f; 19:; cmpwi 3,-1; beq 28f; blt 20f; cmpwi 4,3,0; beq cr4,30f; cmpwi 3,1; b 29f; 20:; li 31,-9; cmpwi 4,3,0; b 30f; 21:; li 31,-1; cmpwi 4,3,0; b 30f; 22:; li 31,-7; cmpwi 4,3,0; b 30f; 23:; stw 31,-26380(13); cmpwi 4,3,0; li 31,-8; b 30f; 24:; li 31,-4; cmpwi 4,3,0; b 30f; 25:; li 31,-3; cmpwi 4,3,0; b 30f; 26:; li 31,-6; cmpwi 4,3,0; b 30f; 27:; li 31,-5; cmpwi 4,3,0; b 30f; 28:; li 31,0; cmpwi 4,3,0; b 30f; 29:; li 31,0; 30:; beq cr4,31f; cmpwi 3,-6; bne 46f; 31:; mr 3,30; bl _s80334040_3; cmpwi 3,-7; beq 44f; bgt 33f; cmpwi 3,-12; beq 44f; bgt 32f; cmpwi 3,-14; beq 43f; bgt 42f; cmpwi 3,-128; b 44f; 32:; cmpwi 3,-10; beq 44f; blt 41f; cmpwi 3,-9; beq 41f; cmpwi 3,-8; b 44f; 33:; cmpwi 3,-3; beq 37f; bgt 34f; cmpwi 3,-5; beq 39f; bgt 38f; b 40f; 34:; cmpwi 3,-1; beq 44f; blt 36f; cmpwi 4,3,0; beq cr4,35f; cmpwi 3,1; b 45f; 35:; li 31,1; b 46f; 36:; cmpwi 4,3,0; li 31,-9; b 46f; 37:; cmpwi 4,3,0; li 31,-1; b 46f; 38:; cmpwi 4,3,0; li 31,-7; b 46f; 39:; li 0,1; cmpwi 4,3,0; stw 0,-26380(13); li 31,-8; b 46f; 40:; cmpwi 4,3,0; li 31,-4; b 46f; 41:; cmpwi 4,3,0; li 31,-3; b 46f; 42:; cmpwi 4,3,0; li 31,-6; b 46f; 43:; cmpwi 4,3,0; li 31,-5; b 46f; 44:; cmpwi 4,3,0; 45:; li 31,0; 46:; mr 3,30; bl _s80334040_4; li 0,0; bne cr4,47f; li 0,1; 47:; stw 0,0x0(27); 48:; mr 3,26; bl _s80334040_5; mr 3,31; lwz 0,0x34(1); lwz 12,0x14(1); mtspr 8,0; lmw 26,0x18(1); mtcrf 8,12; addi 1,1,48"

extern "C" void _s80334040_0();
extern "C" void _s80334040_1();
extern "C" void _s80334040_2();
extern "C" void _s80334040_3();
extern "C" void _s80334040_4();
extern "C" void _s80334040_5();

struct ENgcMemoryCard {
    void IsCardFormated();
};

void ENgcMemoryCard::IsCardFormated() {
}
