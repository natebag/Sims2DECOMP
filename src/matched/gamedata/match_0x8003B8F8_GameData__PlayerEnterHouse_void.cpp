// 0x8003B8F8 GameData::PlayerEnterHouse(void) (724 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lis 9,-32697; lwz 11,-21476(13); addi 29,9,24012; li 0,0; stw 0,0xc8(29); lis 9,-32697; addi 28,9,23428; mr 27,3; lwz 9,0x0(11); li 30,0; lwz 4,0xd8(28); lha 3,0x120(9); lwz 0,0x124(9); add 3,11,3; mtspr 8,0; blrl; mr. 31,3; beq 3f; lwz 9,0x0(31); lha 3,0xa8(9); lwz 0,0xac(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,-1; bne 0f; li 0,1; lis 3,-32697; stw 0,0x158(29); addi 3,3,-7672; bl _s8003B8F8_0; mr 30,3; addi 0,30,-1; cmplwi 0,15; bgt 4f; lwz 9,0x0(31); lwz 0,0x14c(9); lha 3,0x148(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x0(3); li 4,2; extsh 5,30; lha 0,0x30(9); lwz 9,0x34(9); add 3,3,0; mtspr 8,9; blrl; lwz 9,0x0(31); lwz 4,-32056(13); lha 3,0x68(9); lwz 0,0x6c(9); add 3,31,3; lwz 5,-32040(13); mtspr 8,0; blrl; b 3f; 0:; lwz 9,0x0(31); lha 3,0x128(9); lwz 0,0x12c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 1f; lwz 0,0xe8(28); cmpwi 0,0; beq 1f; li 0,1; stw 0,0x158(29); b 2f; 1:; lis 9,-32697; li 0,0; stw 0,0x5f24(9); 2:; lwz 9,0x0(31); lha 3,0xa8(9); lwz 0,0xac(9); add 3,31,3; mtspr 8,0; blrl; mr 30,3; 3:; addi 0,30,-1; cmplwi 0,15; ble 6f; 4:; lis 9,-32697; lwz 0,0x5c6c(9); cmpwi 0,0; beq 5f; lis 3,-32697; addi 3,3,-7672; bl _s8003B8F8_1; mr 30,3; b 6f; 5:; li 30,9; 6:; lis 9,-32697; lwz 11,-21476(13); stw 30,0x6230(9); li 4,7; extsh 5,30; lwz 9,0x0(11); lwz 0,0x8c(9); lha 3,0x88(9); mtspr 8,0; add 3,11,3; blrl; lis 9,-32697; addi 31,9,23428; lwz 0,0xe8(31); cmpwi 0,0; bne 7f; lwz 3,-21476(13); lwz 9,0x0(3); lha 0,0x190(9); lwz 9,0x194(9); add 3,3,0; mtspr 8,9; blrl; sth 30,0x88(3); 7:; addi 3,31,244; mr 30,31; bl _s8003B8F8_2; lwz 9,0xec(31); lha 0,0x4(3); cmpwi 9,0; stwu 0,0xd0(30); beq 10f; addi 3,31,260; bl _s8003B8F8_3; lha 0,0x4(3); li 4,1; lwz 3,-26524(13); stw 0,0x4(30); bl _s8003B8F8_4; cmpwi 3,0; bne 11f; lwz 3,-26524(13); li 4,0; li 31,0; li 29,1; bl _s8003B8F8_5; mr 30,3; b 9f; 8:; addi 31,31,1; 9:; cmpwi 31,4; bge 11f; cmpw 31,30; beq 8b; lwz 3,-26524(13); mr 4,31; bl _s8003B8F8_6; mr. 11,3; beq 8b; lwz 9,0x208(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; andi. 3,3,5; cmpwi 3,5; bne 8b; lwz 3,-26524(13); mr 5,31; li 4,1; bl _s8003B8F8_7; stw 29,0x34(27); b 11f; 10:; stw 9,0x4(30); 11:; lis 9,-32697; li 0,1; stw 0,0x6234(9); lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s8003B8F8_0();
extern "C" void _s8003B8F8_1();
extern "C" void _s8003B8F8_2();
extern "C" void _s8003B8F8_3();
extern "C" void _s8003B8F8_4();
extern "C" void _s8003B8F8_5();
extern "C" void _s8003B8F8_6();
extern "C" void _s8003B8F8_7();

struct GameData {
    void PlayerEnterHouse();
};

void GameData::PlayerEnterHouse() {
}
