// 0x80137BE0 Room::CollectTileStats(CTilePt (612 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 24,0x40(1); stw 0,0x64(1); mr 30,3; mr 31,4; bl _s80137BE0_0; cmpwi 3,0; beq 0f; lwz 9,0x4c(30); addi 9,9,2; stw 9,0x4c(30); b 14f; 0:; lwz 4,-21488(13); addi 3,1,8; mr 5,31; lwz 9,0x0(4); lha 0,0xa8(9); lwz 9,0xac(9); add 4,4,0; mtspr 8,9; blrl; addi 3,1,8; bl _s80137BE0_1; cmpwi 3,0; beq 11f; addi 3,1,8; bl _s80137BE0_2; cmpwi 3,0; beq 7f; lwz 9,0x4c(30); lis 11,-32702; addi 31,11,17252; addi 3,1,8; addi 9,9,1; stw 9,0x4c(30); lwz 4,0x4364(11); bl _s80137BE0_3; cmpwi 3,0; beq 1f; mr 27,31; b 2f; 1:; addi 27,31,20; 2:; lwz 4,0x0(27); addi 3,1,8; li 26,0; li 25,0; bl _s80137BE0_4; addi 29,27,4; mr 24,3; li 31,0; li 28,2; 3:; lwz 4,0x0(27); addi 3,1,8; lwzx 5,31,29; bl _s80137BE0_5; cmpwi 3,0; beq 4f; li 26,1; 4:; lwzx 4,31,29; addi 3,1,8; bl _s80137BE0_6; cmpwi 3,0; beq 5f; li 25,1; 5:; addi 31,31,4; addic. 28,28,-1; bne 3b; mr 3,24; bl _s80137BE0_7; cmpwi 3,0; beq 6f; lwz 9,0x74(30); cmpwi 26,0; addi 9,9,1; stw 9,0x74(30); beq 6f; lwz 9,0x78(30); addi 9,9,1; stw 9,0x78(30); 6:; cmpwi 25,0; beq 13f; lwz 9,0x50(30); addi 9,9,1; b 12f; 7:; lwz 9,0x4c(30); mr 4,31; lwz 10,-21488(13); addi 9,9,2; stw 9,0x4c(30); lwz 11,0x0(10); lha 3,0x88(11); lwz 0,0x8c(11); add 3,10,3; mtspr 8,0; blrl; cmpwi 3,0; beq 8f; lwz 9,0x50(30); addi 9,9,2; stw 9,0x50(30); 8:; addi 3,1,8; bl _s80137BE0_8; mr. 31,3; beq 13f; 9:; mr 4,31; addi 3,1,8; bl _s80137BE0_9; bl _s80137BE0_10; cmpwi 3,0; beq 10f; lwz 9,0x74(30); addi 3,1,8; mr 4,31; li 5,0; addi 9,9,1; stw 9,0x74(30); bl _s80137BE0_11; cmpwi 3,0; beq 10f; lwz 9,0x78(30); addi 9,9,1; stw 9,0x78(30); 10:; mr 4,31; addi 3,1,8; bl _s80137BE0_12; mr. 31,3; bne 9b; b 13f; 11:; lwz 9,0x4c(30); mr 4,31; lwz 10,-21488(13); addi 9,9,2; stw 9,0x4c(30); lwz 11,0x0(10); lha 3,0x88(11); lwz 0,0x8c(11); add 3,10,3; mtspr 8,0; blrl; cmpwi 3,0; beq 13f; lwz 9,0x50(30); addi 9,9,2; 12:; stw 9,0x50(30); 13:; addi 3,1,8; li 4,2; bl _s80137BE0_13; 14:; lwz 0,0x64(1); mtspr 8,0; lmw 24,0x40(1); addi 1,1,96"

extern "C" void _s80137BE0_0();
extern "C" void _s80137BE0_1();
extern "C" void _s80137BE0_2();
extern "C" void _s80137BE0_3();
extern "C" void _s80137BE0_4();
extern "C" void _s80137BE0_5();
extern "C" void _s80137BE0_6();
extern "C" void _s80137BE0_7();
extern "C" void _s80137BE0_8();
extern "C" void _s80137BE0_9();
extern "C" void _s80137BE0_10();
extern "C" void _s80137BE0_11();
extern "C" void _s80137BE0_12();
extern "C" void _s80137BE0_13();

struct Room {
    void CollectTileStats_CTilePt();
};

void Room::CollectTileStats_CTilePt() {
}
