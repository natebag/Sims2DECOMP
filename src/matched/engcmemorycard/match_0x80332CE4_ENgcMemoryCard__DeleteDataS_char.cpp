// 0x80332CE4 ENgcMemoryCard::DeleteDataS(char (776 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); li 9,0; mr 26,3; mr 27,4; mr 30,5; stw 9,0xc(1); stw 9,0x8(1); bl _s80332CE4_0; addi 28,1,8; addi 29,1,12; 0:; mr 3,30; mr 4,28; mr 5,29; bl _s80332CE4_1; mr 9,3; cmpwi 9,-7; beq 13f; bgt 2f; cmpwi 9,-12; beq 13f; bgt 1f; cmpwi 9,-14; beq 12f; bgt 11f; cmpwi 9,-128; b 13f; 1:; cmpwi 9,-10; beq 13f; blt 10f; cmpwi 9,-9; beq 10f; cmpwi 9,-8; b 13f; 2:; cmpwi 9,-3; beq 6f; bgt 3f; cmpwi 9,-5; beq 8f; bgt 7f; b 9f; 3:; cmpwi 7,9,-1; beq cr7,14f; blt cr7,5f; cmpwi 9,0; beq 4f; cmpwi 9,1; b 14f; 4:; li 31,1; b 15f; 5:; li 31,-9; b 15f; 6:; cmpwi 7,9,-1; li 31,-1; b 15f; 7:; cmpwi 7,9,-1; li 31,-7; b 15f; 8:; li 0,1; cmpwi 7,9,-1; stw 0,-26380(13); li 31,-8; b 15f; 9:; cmpwi 7,9,-1; li 31,-4; b 15f; 10:; cmpwi 7,9,-1; li 31,-3; b 15f; 11:; cmpwi 7,9,-1; li 31,-6; b 15f; 12:; cmpwi 7,9,-1; li 31,-5; b 15f; 13:; cmpwi 7,9,-1; 14:; li 31,0; 15:; beq cr7,0b; cmpwi 31,1; bne 35f; lis 4,-32692; mr 3,30; addi 4,4,29280; li 5,0; bl _s80332CE4_2; mr. 9,3; beq 16f; cmpwi 9,-6; beq 16f; cmpwi 9,-13; bne 35f; 16:; mr 4,27; mr 3,30; bl _s80332CE4_3; mr 9,3; cmpwi 9,-7; beq 21f; bgt 18f; cmpwi 9,-12; beq 21f; bgt 17f; cmpwi 9,-14; beq 21f; bgt 21f; cmpwi 9,-128; b 21f; 17:; cmpwi 9,-10; beq 21f; blt 21f; cmpwi 9,-9; beq 21f; cmpwi 9,-8; b 21f; 18:; cmpwi 9,-3; beq 21f; bgt 19f; cmpwi 9,-5; beq 20f; b 21f; 19:; cmpwi 9,-1; beq 21f; blt 21f; cmpwi 9,0; beq 21f; cmpwi 9,1; b 21f; 20:; li 0,1; stw 0,-26380(13); 21:; mr 3,30; bl _s80332CE4_4; mr 9,3; cmpwi 9,-7; beq 34f; bgt 23f; cmpwi 9,-12; beq 34f; bgt 22f; cmpwi 9,-14; beq 33f; bgt 32f; cmpwi 9,-128; b 34f; 22:; cmpwi 9,-10; beq 34f; blt 31f; cmpwi 9,-9; beq 31f; cmpwi 9,-8; b 34f; 23:; cmpwi 9,-3; beq 27f; bgt 24f; cmpwi 9,-5; beq 29f; bgt 28f; b 30f; 24:; cmpwi 9,-1; beq 34f; blt 26f; cmpwi 9,0; beq 25f; cmpwi 9,1; b 34f; 25:; li 31,1; b 35f; 26:; li 31,-9; b 35f; 27:; li 31,-1; b 35f; 28:; li 31,-7; b 35f; 29:; li 0,1; li 31,-8; stw 0,-26380(13); b 35f; 30:; li 31,-4; b 35f; 31:; li 31,-3; b 35f; 32:; li 31,-6; b 35f; 33:; li 31,-5; b 35f; 34:; li 31,0; 35:; mr 3,26; bl _s80332CE4_5; mr 3,31; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"

extern "C" void _s80332CE4_0();
extern "C" void _s80332CE4_1();
extern "C" void _s80332CE4_2();
extern "C" void _s80332CE4_3();
extern "C" void _s80332CE4_4();
extern "C" void _s80332CE4_5();

struct ENgcMemoryCard {
    void DeleteDataS();
};

void ENgcMemoryCard::DeleteDataS() {
}
