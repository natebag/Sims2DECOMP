// 0x80190764 SerializeUIGameData::SerializeUIData(int, (656 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; mfcr 12; stmw 25,0x14(1); stw 0,0x34(1); stw 12,0x10(1); mr 28,3; mr 30,4; mr 31,6; xori 27,5,1; subfic 0,27,0; adde. 27,0,27; beq 2f; cmpwi 28,0; mfcr 29; bne 0f; lis 3,-32705; addi 3,3,-17476; b 1f; 0:; lis 3,-32705; addi 3,3,-17456; 1:; bl _s80190764_0; stw 3,0x0(30); mr 3,30; cmpwi 4,31,0; bl _s80190764_1; beq cr4,6f; lis 0,17781; ori 0,0,14019; stw 0,0x0(30); b 6f; 2:; cmpwi 28,0; mfcr 29; bne 4f; lwz 0,0x0(30); addi 3,1,8; cmpwi 4,31,0; stw 0,0x8(1); bl _s80190764_2; beq cr4,3f; lis 0,17781; ori 0,0,14019; stw 0,0x8(1); 3:; lis 3,-32705; lwz 4,0x8(1); addi 3,3,-17476; bl _s80190764_3; b 6f; 4:; lwz 0,0x0(30); addi 3,1,8; cmpwi 4,31,0; stw 0,0x8(1); bl _s80190764_4; beq cr4,5f; lis 0,17781; ori 0,0,14019; stw 0,0x8(1); 5:; lis 3,-32705; lwz 4,0x8(1); addi 3,3,-17456; bl _s80190764_5; 6:; addi 30,30,4; cmpwi 3,27,0; beq cr3,9f; mtcrf 128,29; bne 7f; lis 3,-32705; addi 3,3,-17436; b 8f; 7:; lis 3,-32705; addi 3,3,-17424; 8:; bl _s80190764_6; stw 3,0x0(30); mr 3,30; bl _s80190764_7; beq cr4,13f; li 0,0; stw 0,0x0(30); b 13f; 9:; mtcrf 128,29; bne 11f; lwz 0,0x0(30); addi 3,1,8; stw 0,0x8(1); bl _s80190764_8; beq cr4,10f; stw 28,0x8(1); 10:; lis 3,-32705; lwz 4,0x8(1); addi 3,3,-17436; bl _s80190764_9; b 13f; 11:; lwz 0,0x0(30); addi 3,1,8; stw 0,0x8(1); bl _s80190764_10; beq cr4,12f; stw 27,0x8(1); 12:; lis 3,-32705; lwz 4,0x8(1); addi 3,3,-17424; bl _s80190764_11; 13:; mulli 0,28,40; lis 9,-32700; addi 9,9,-25200; mulli 26,28,14; addi 30,30,4; li 25,0; add 29,0,9; li 28,20; 14:; beq cr3,15f; lhz 0,0x0(29); mr 3,30; stw 0,0x0(30); bl _s80190764_12; beq cr4,17f; stw 25,0x0(30); b 17f; 15:; lwz 0,0x0(30); addi 31,1,8; mr 3,31; stw 0,0x8(1); bl _s80190764_13; beq cr4,16f; stw 27,0x8(1); 16:; lhz 0,0x2(31); sth 0,0x0(29); 17:; addi 30,30,4; addi 29,29,2; addic. 28,28,-1; bne 14b; lis 9,-32700; li 25,0; addi 9,9,-25120; li 28,14; add 29,26,9; 18:; beq cr3,19f; lbz 0,0x0(29); mr 3,30; stw 0,0x0(30); bl _s80190764_14; beq cr4,21f; stw 25,0x0(30); b 21f; 19:; lwz 0,0x0(30); addi 31,1,8; mr 3,31; stw 0,0x8(1); bl _s80190764_15; beq cr4,20f; stw 27,0x8(1); 20:; lbz 0,0x3(31); stb 0,0x0(29); 21:; addi 30,30,4; addi 29,29,1; addic. 28,28,-1; bne 18b; lwz 0,0x34(1); lwz 12,0x10(1); mtspr 8,0; lmw 25,0x14(1); mtcrf 24,12; addi 1,1,48"

extern "C" void _s80190764_0();
extern "C" void _s80190764_1();
extern "C" void _s80190764_2();
extern "C" void _s80190764_3();
extern "C" void _s80190764_4();
extern "C" void _s80190764_5();
extern "C" void _s80190764_6();
extern "C" void _s80190764_7();
extern "C" void _s80190764_8();
extern "C" void _s80190764_9();
extern "C" void _s80190764_10();
extern "C" void _s80190764_11();
extern "C" void _s80190764_12();
extern "C" void _s80190764_13();
extern "C" void _s80190764_14();
extern "C" void _s80190764_15();

struct SerializeUIGameData {
    void SerializeUIData();
};

void SerializeUIGameData::SerializeUIData() {
}
