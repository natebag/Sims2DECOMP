// 0x801C09A0 M2MTarget::SelectionCallback(int) (764 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; li 28,1; stw 28,0x180(30); lis 3,-32705; mr 31,4; addi 3,3,-2032; bl _s801C09A0_0; lwz 0,0x11c(30); mr 29,3; cmpwi 0,9; beq 18f; bgt 1f; cmpwi 0,4; beq 27f; bgt 0f; cmpwi 0,3; beq 31f; b 36f; 0:; cmpwi 0,6; beq 18f; b 36f; 1:; cmpwi 0,12; beq 12f; bgt 2f; cmpwi 0,11; beq 3f; b 36f; 2:; cmpwi 0,15; bgt 36f; cmpwi 0,14; blt 36f; b 20f; 3:; cmpwi 31,1; beq 6f; bgt 4f; cmpwi 31,0; beq 5f; b 36f; 4:; cmpwi 31,3; bgt 36f; b 9f; 5:; li 0,15; stw 28,0x168(30); stw 0,0x11c(30); b 36f; 6:; lis 3,-32705; li 4,1; addi 3,3,8428; bl _s801C09A0_1; cmpwi 29,2; beq 7f; cmpwi 29,7; beq 8f; b 17f; 7:; lis 3,-32705; li 4,9; b 16f; 8:; lwz 3,-32056(13); bl _s801C09A0_2; lis 3,-32705; li 4,0; addi 3,3,8412; bl _s801C09A0_3; b 17f; 9:; lis 3,-32705; li 4,0; addi 3,3,8428; bl _s801C09A0_4; cmpwi 29,2; beq 10f; cmpwi 29,7; beq 11f; b 17f; 10:; lis 3,-32705; li 4,10; b 16f; 11:; lis 3,-32705; li 4,11; addi 3,3,8412; bl _s801C09A0_5; b 17f; 12:; cmpwi 31,1; beq 15f; bgt 13f; cmpwi 31,0; beq 14f; b 36f; 13:; cmpwi 31,3; beq 15f; b 36f; 14:; lwz 3,-32056(13); bl _s801C09A0_6; lis 3,-32705; li 4,0; b 16f; 15:; lis 3,-32705; li 4,11; 16:; addi 3,3,8412; bl _s801C09A0_7; 17:; mr 3,30; bl _s801C09A0_8; li 0,3; stw 0,0x168(30); b 36f; 18:; cmpwi 31,1; beq 30f; bgt 28f; cmpwi 31,0; bne 36f; mr 3,30; bl _s801C09A0_9; cmpwi 3,0; beq 19f; li 9,9; b 23f; 19:; li 0,8; b 25f; 20:; cmpwi 31,1; beq 26f; bgt 21f; cmpwi 31,0; beq 22f; b 36f; 21:; cmpwi 31,3; beq 26f; b 36f; 22:; mr 3,30; bl _s801C09A0_10; cmpwi 3,0; beq 24f; li 9,15; 23:; li 0,1; stw 0,0x168(30); stw 9,0x11c(30); b 36f; 24:; li 0,13; 25:; mr 3,30; stw 0,0x11c(30); bl _s801C09A0_11; b 36f; 26:; li 0,15; mr 3,30; stw 0,0x11c(30); bl _s801C09A0_12; b 36f; 27:; cmpwi 31,1; beq 30f; bgt 28f; cmpwi 31,0; beq 29f; b 36f; 28:; cmpwi 31,3; beq 30f; b 36f; 29:; li 0,5; stw 0,0x11c(30); b 36f; 30:; li 0,1; stw 0,0x11c(30); b 36f; 31:; cmpwi 31,1; beq 34f; bgt 32f; cmpwi 31,0; beq 33f; b 36f; 32:; cmpwi 31,3; beq 35f; b 36f; 33:; mr 3,30; bl _s801C09A0_13; stw 31,0x180(30); b 36f; 34:; li 9,255; li 0,0; stw 0,0x11c(30); stw 9,0x110(30); stw 9,0x10c(30); b 36f; 35:; li 0,0; stw 28,0x11c(30); stw 0,0x180(30); 36:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s801C09A0_0();
extern "C" void _s801C09A0_1();
extern "C" void _s801C09A0_2();
extern "C" void _s801C09A0_3();
extern "C" void _s801C09A0_4();
extern "C" void _s801C09A0_5();
extern "C" void _s801C09A0_6();
extern "C" void _s801C09A0_7();
extern "C" void _s801C09A0_8();
extern "C" void _s801C09A0_9();
extern "C" void _s801C09A0_10();
extern "C" void _s801C09A0_11();
extern "C" void _s801C09A0_12();
extern "C" void _s801C09A0_13();

struct M2MTarget {
    void SelectionCallback();
};

void M2MTarget::SelectionCallback() {
}
