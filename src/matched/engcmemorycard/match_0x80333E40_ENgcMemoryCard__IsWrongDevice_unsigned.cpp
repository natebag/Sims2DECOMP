// 0x80333E40 ENgcMemoryCard::IsWrongDevice(unsigned (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); li 0,0; mr 27,3; mr 28,4; stw 0,0xc(1); stw 0,0x8(1); bl _s80333E40_0; addi 29,1,8; addi 30,1,12; 0:; mr 3,28; mr 4,29; mr 5,30; bl _s80333E40_1; cmpwi 3,-7; beq 13f; bgt 2f; cmpwi 3,-12; beq 13f; bgt 1f; cmpwi 3,-14; beq 12f; bgt 11f; cmpwi 3,-128; b 13f; 1:; cmpwi 3,-10; beq 13f; blt 10f; cmpwi 3,-9; beq 10f; cmpwi 3,-8; b 13f; 2:; cmpwi 3,-3; beq 6f; bgt 3f; cmpwi 3,-5; beq 8f; bgt 7f; b 9f; 3:; cmpwi 7,3,-1; beq cr7,14f; blt cr7,5f; cmpwi 3,0; beq 4f; cmpwi 3,1; b 14f; 4:; li 31,1; b 15f; 5:; li 31,-9; b 15f; 6:; cmpwi 7,3,-1; li 31,-1; b 15f; 7:; cmpwi 7,3,-1; li 31,-7; b 15f; 8:; li 0,1; cmpwi 7,3,-1; stw 0,-26380(13); li 31,-8; b 15f; 9:; cmpwi 7,3,-1; li 31,-4; b 15f; 10:; cmpwi 7,3,-1; li 31,-3; b 15f; 11:; cmpwi 7,3,-1; li 31,-6; b 15f; 12:; cmpwi 7,3,-1; li 31,-5; b 15f; 13:; cmpwi 7,3,-1; 14:; li 31,0; 15:; beq cr7,0b; mr 3,27; bl _s80333E40_2; subfic 3,31,-9; subfic 0,3,0; adde 3,0,3; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"

extern "C" void _s80333E40_0();
extern "C" void _s80333E40_1();
extern "C" void _s80333E40_2();

struct ENgcMemoryCard {
    void IsWrongDevice();
};

void ENgcMemoryCard::IsWrongDevice() {
}
