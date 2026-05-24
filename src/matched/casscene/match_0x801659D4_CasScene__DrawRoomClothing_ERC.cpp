// 0x801659D4 CasScene::DrawRoomClothing(ERC (504 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-288(1); mfspr 0,8; mfcr 12; stmw 27,0x10c(1); stw 0,0x124(1); stw 12,0x108(1); mr 31,3; mr 30,4; lwz 9,0x0(31); mr 27,5; li 29,0; lwz 3,0x1c(9); bl _s801659D4_0; cmpwi 3,0; beq 0f; lwz 0,0xa88(31); cmpwi 0,0; beq 0f; li 29,1; 0:; cmpwi 4,29,0; addi 28,31,8; addi 29,1,8; beq cr4,1f; lfs f1,0xabc(31); lwz 3,0xa88(31); bl _s801659D4_1; lwz 4,0xb18(31); mr 5,30; lwz 3,0xa88(31); bl _s801659D4_2; mr 3,29; bl _s801659D4_3; lwz 9,0x70(30); mr 4,29; li 5,1; lwz 0,0xec(9); lha 3,0xe8(9); mtspr 8,0; add 3,30,3; blrl; mr 3,31; li 4,3; li 5,0; bl _s801659D4_4; lwz 9,0x70(30); mr 4,28; lha 3,0x168(9); lwz 0,0x16c(9); add 3,30,3; mtspr 8,0; blrl; lwz 3,0xa80(31); cmpwi 3,0; beq 1f; mr 4,30; bl _s801659D4_5; 1:; lwz 4,0xb1c(31); mr 3,31; li 5,1; bl _s801659D4_6; beq cr4,2f; lwz 3,0x0(31); mr 4,30; bl _s801659D4_7; lwz 3,0xa88(31); mr 5,30; lwz 4,0xb18(31); bl _s801659D4_8; 2:; addi 3,1,8; bl _s801659D4_9; lwz 9,0x70(30); mr 4,29; li 5,1; lwz 0,0xec(9); lha 3,0xe8(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x70(30); mr 4,28; lha 3,0x168(9); lwz 0,0x16c(9); add 3,30,3; mtspr 8,0; blrl; lwz 3,0xa80(31); cmpwi 3,0; beq 3f; mr 4,30; bl _s801659D4_10; 3:; lwz 3,0xa84(31); cmpwi 3,0; beq 4f; beq cr4,4f; bl _s801659D4_11; mr 4,3; addi 3,1,72; bl _s801659D4_12; addi 3,1,200; addi 4,1,72; mr 5,27; bl _s801659D4_13; addi 4,1,200; addi 3,1,72; bl _s801659D4_14; addi 4,1,72; addi 3,1,136; bl _s801659D4_15; lwz 9,0x70(30); addi 4,1,72; li 5,1; lha 3,0xe8(9); lwz 0,0xec(9); add 3,30,3; mtspr 8,0; blrl; lwz 3,0xa84(31); mr 4,30; bl _s801659D4_16; 4:; lwz 0,0x124(1); lwz 12,0x108(1); mtspr 8,0; lmw 27,0x10c(1); mtcrf 8,12; addi 1,1,288"

extern "C" void _s801659D4_0();
extern "C" void _s801659D4_1();
extern "C" void _s801659D4_2();
extern "C" void _s801659D4_3();
extern "C" void _s801659D4_4();
extern "C" void _s801659D4_5();
extern "C" void _s801659D4_6();
extern "C" void _s801659D4_7();
extern "C" void _s801659D4_8();
extern "C" void _s801659D4_9();
extern "C" void _s801659D4_10();
extern "C" void _s801659D4_11();
extern "C" void _s801659D4_12();
extern "C" void _s801659D4_13();
extern "C" void _s801659D4_14();
extern "C" void _s801659D4_15();
extern "C" void _s801659D4_16();

struct CasScene {
    void DrawRoomClothing();
};

void CasScene::DrawRoomClothing() {
}
