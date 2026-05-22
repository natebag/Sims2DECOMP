// 0x801E1644 SKLTarget::UpdateSkillsBar(void) (888 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-136(1); mfspr 0,8; stmw 19,0x54(1); stw 0,0x8c(1); mr 30,3; lwz 0,0x84(30); cmpwi 0,0; beq 10f; lis 9,-32697; lwz 0,0x94(30); addi 9,9,24012; lwz 11,0xa4(30); rlwinm 0,0,2,0,29; addi 9,9,188; lwzx 27,9,0; cmpw 27,11; beq 2f; stw 27,0xa4(30); cmpwi 27,0; beq 10f; addi 3,1,8; li 28,0; bl _s801E1644_0; addi 24,30,168; addi 3,1,8; lis 19,-32705; bl _s801E1644_1; lis 20,-32705; lis 9,-32700; lis 11,-32697; addi 21,9,-25244; addi 22,11,23428; lis 23,-32705; addi 26,30,196; addi 31,1,32; li 25,0; li 29,0; 0:; lwz 9,0x4(27); lwzx 4,29,21; lha 3,0x138(9); lwz 0,0x13c(9); add 3,27,3; mtspr 8,0; blrl; stwx 3,29,24; addi 4,19,23032; mr 5,28; mr 3,31; crxor 6,6,6; bl _s801E1644_2; lwz 5,0x94(30); addi 3,1,8; mr 4,31; bl _s801E1644_3; addi 3,1,8; li 4,14; bl _s801E1644_4; addi 4,20,23044; mr 5,28; mr 3,31; crxor 6,6,6; bl _s801E1644_5; lwz 5,0x94(30); addi 3,1,8; mr 4,31; bl _s801E1644_6; addi 3,1,8; addi 4,23,3316; bl _s801E1644_7; lwz 3,0x48(22); cmpwi 3,0; beq 1f; lwz 4,0x94(30); li 5,0; bl _s801E1644_8; 1:; stwx 25,29,26; addi 28,28,1; addi 29,29,4; cmpwi 28,6; ble 0b; addi 3,1,8; bl _s801E1644_9; addi 3,1,8; li 4,2; bl _s801E1644_10; b 10f; 2:; cmpwi 27,0; beq 10f; addi 3,1,8; li 25,0; bl _s801E1644_11; addi 24,30,168; lis 9,-32700; lis 11,-32697; addi 21,9,-25244; addi 22,11,23428; addi 26,30,196; li 29,0; lis 23,-32705; 3:; lwz 9,0x4(27); lwzx 4,29,21; lwz 0,0x13c(9); lha 3,0x138(9); mtspr 8,0; add 3,27,3; blrl; lwzx 0,29,24; mr 28,3; cmpw 28,0; beq 5f; addi 31,1,48; addi 3,1,8; bl _s801E1644_12; addi 4,23,23032; mr 5,25; mr 3,31; crxor 6,6,6; bl _s801E1644_13; lwz 5,0x94(30); addi 3,1,8; mr 4,31; bl _s801E1644_14; addi 3,1,8; li 4,14; bl _s801E1644_15; lwzx 0,29,26; cmpwi 0,0; bne 4f; lis 4,-32705; mr 5,25; addi 4,4,23044; mr 3,31; crxor 6,6,6; bl _s801E1644_16; lwz 5,0x94(30); mr 4,31; addi 3,1,8; bl _s801E1644_17; lis 4,-32705; addi 3,1,8; addi 4,4,23056; bl _s801E1644_18; 4:; addi 3,1,8; bl _s801E1644_19; stwx 28,29,24; li 0,10; stwx 0,29,26; lwz 9,0x90(30); cmpwi 9,0; bne 5f; lwz 3,0x48(22); cmpwi 3,0; beq 5f; lwz 4,0x94(30); li 5,1; bl _s801E1644_20; 5:; addi 25,25,1; addi 29,29,4; cmpwi 25,6; ble 3b; li 24,0; li 25,0; li 28,0; addi 31,1,32; addi 27,1,64; lis 22,-32705; lis 23,-32705; li 29,0; 6:; lwzx 9,29,26; cmpwi 9,0; ble 8f; addi 0,9,-1; cmpwi 0,0; stwx 0,29,26; bne 7f; mr 3,31; li 25,1; bl _s801E1644_21; addi 4,22,23044; mr 5,28; mr 3,27; crxor 6,6,6; bl _s801E1644_22; mr 3,31; bl _s801E1644_23; lwz 5,0x94(30); mr 3,31; mr 4,27; bl _s801E1644_24; addi 4,23,3316; mr 3,31; bl _s801E1644_25; mr 3,31; bl _s801E1644_26; mr 3,31; li 4,2; bl _s801E1644_27; b 8f; 7:; li 24,1; 8:; addi 28,28,1; addi 29,29,4; cmpwi 28,6; ble 6b; cmpwi 25,0; beq 9f; cmpwi 24,0; bne 9f; lis 9,-32697; lwz 3,0x5bcc(9); cmpwi 3,0; beq 9f; lwz 4,0x94(30); li 5,0; bl _s801E1644_28; 9:; addi 3,1,8; li 4,2; bl _s801E1644_29; 10:; lwz 0,0x8c(1); mtspr 8,0; lmw 19,0x54(1); addi 1,1,136"
extern "C" void _s801E1644_0();
extern "C" void _s801E1644_1();
extern "C" void _s801E1644_2();
extern "C" void _s801E1644_3();
extern "C" void _s801E1644_4();
extern "C" void _s801E1644_5();
extern "C" void _s801E1644_6();
extern "C" void _s801E1644_7();
extern "C" void _s801E1644_8();
extern "C" void _s801E1644_9();
extern "C" void _s801E1644_10();
extern "C" void _s801E1644_11();
extern "C" void _s801E1644_12();
extern "C" void _s801E1644_13();
extern "C" void _s801E1644_14();
extern "C" void _s801E1644_15();
extern "C" void _s801E1644_16();
extern "C" void _s801E1644_17();
extern "C" void _s801E1644_18();
extern "C" void _s801E1644_19();
extern "C" void _s801E1644_20();
extern "C" void _s801E1644_21();
extern "C" void _s801E1644_22();
extern "C" void _s801E1644_23();
extern "C" void _s801E1644_24();
extern "C" void _s801E1644_25();
extern "C" void _s801E1644_26();
extern "C" void _s801E1644_27();
extern "C" void _s801E1644_28();
extern "C" void _s801E1644_29();
extern "C" void f_801E1644() {}
