// 0x80098988 Physics::PhysicsMove(EVec3 (976 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 28,0; li 29,0; li 27,1; bl _s80098988_0; cmpwi 3,24; bne 0f; lwz 3,0x8(31); bl _s80098988_1; mr 3,31; li 4,17; bl _s80098988_2; b 15f; 0:; lwz 3,0x8(31); bl _s80098988_3; cmpwi 3,1; bne 1f; lwz 3,0x8(31); bl _s80098988_4; b 15f; 1:; lwz 3,0x8(31); bl _s80098988_5; cmpwi 3,23; bne 3f; lwz 3,0x8(31); bl _s80098988_6; lwz 0,0x54(30); stw 27,0xd8(30); cmpwi 0,0; bne 2f; lis 3,-32706; li 4,0; addi 3,3,-29632; bl _s80098988_7; li 3,408; bl _s80098988_8; bl _s80098988_9; stw 3,0x54(30); 2:; li 27,0; b 15f; 3:; lwz 3,0x8(31); bl _s80098988_10; cmpwi 3,48; bne 4f; bl _s80098988_11; cmpwi 3,0; beq 13f; lwz 9,-32160(13); lwz 0,0xb4(9); andi. 9,0,4; beq 15f; lwz 3,0x8(31); li 29,1; bl _s80098988_12; mr 3,31; bl _s80098988_13; mr 3,31; li 4,8; bl _s80098988_14; b 15f; 4:; lwz 3,0x8(31); bl _s80098988_15; cmpwi 3,49; beq 7f; lwz 3,0x8(31); bl _s80098988_16; cmpwi 3,46; bne 6f; lwz 3,0x8(31); bl _s80098988_17; lwz 11,0x54(30); cmpwi 11,0; beq 5f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 5:; lwz 3,0x68(30); li 4,1; b 9f; 6:; lwz 3,0x8(31); bl _s80098988_18; cmpwi 3,47; bne 10f; 7:; lwz 3,0x8(31); bl _s80098988_19; lwz 11,0x54(30); cmpwi 11,0; beq 8f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 8:; lwz 3,0x68(30); li 4,0; 9:; stw 29,0x54(30); li 28,1; bl _s80098988_20; b 15f; 10:; lwz 3,0x8(31); bl _s80098988_21; cmpwi 3,8; bne 12f; bl _s80098988_22; cmpwi 3,0; beq 13f; lwz 9,-32160(13); lwz 0,0xb4(9); andi. 9,0,4; beq 15f; lwz 3,0x8(31); bl _s80098988_23; lis 9,-32697; addi 30,9,23428; lwz 11,0x68(30); stw 27,0xd8(30); cmpwi 11,0; beq 11f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; stw 29,0x68(30); 11:; mr 3,31; li 29,1; li 4,16; bl _s80098988_24; b 15f; 12:; lwz 3,0x8(31); bl _s80098988_25; cmpwi 3,3; bne 15f; bl _s80098988_26; cmpwi 3,0; bne 14f; 13:; li 3,1; bl _s80098988_27; b 15f; 14:; lwz 9,-32160(13); lwz 0,0xb4(9); andi. 9,0,4; beq 15f; lwz 3,0x8(31); li 29,1; bl _s80098988_28; mr 3,31; bl _s80098988_29; mr 3,31; li 4,8; bl _s80098988_30; 15:; cmpwi 28,0; beq 16f; lwz 0,-24620(13); cmpwi 0,0; bne 16f; li 3,220; bl _s80098988_31; bl _s80098988_32; stw 3,-24620(13); 16:; cmpwi 29,0; beq 17f; lwz 3,-24620(13); cmpwi 3,0; beq 18f; li 4,3; bl _s80098988_33; li 0,0; stw 0,-24620(13); 17:; lwz 9,-24620(13); cmpwi 9,0; beq 18f; stw 27,0xd8(9); 18:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32; blr; stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lis 9,-32697; li 0,1; addi 31,9,23428; lwz 11,0x68(31); stw 0,0xd8(31); cmpwi 11,0; beq 19f; lwz 9,0x80(11); li 4,3; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0x68(31); 19:; lwz 11,0x54(31); cmpwi 11,0; beq 20f; lwz 9,0x80(11); li 4,3; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0x54(31); 20:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,-24620(13); cmpwi 3,0; beq 21f; bl _s80098988_34; 21:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,-26524(13); li 4,0; bl _s80098988_35; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80098988_0();
extern "C" void _s80098988_1();
extern "C" void _s80098988_2();
extern "C" void _s80098988_3();
extern "C" void _s80098988_4();
extern "C" void _s80098988_5();
extern "C" void _s80098988_6();
extern "C" void _s80098988_7();
extern "C" void _s80098988_8();
extern "C" void _s80098988_9();
extern "C" void _s80098988_10();
extern "C" void _s80098988_11();
extern "C" void _s80098988_12();
extern "C" void _s80098988_13();
extern "C" void _s80098988_14();
extern "C" void _s80098988_15();
extern "C" void _s80098988_16();
extern "C" void _s80098988_17();
extern "C" void _s80098988_18();
extern "C" void _s80098988_19();
extern "C" void _s80098988_20();
extern "C" void _s80098988_21();
extern "C" void _s80098988_22();
extern "C" void _s80098988_23();
extern "C" void _s80098988_24();
extern "C" void _s80098988_25();
extern "C" void _s80098988_26();
extern "C" void _s80098988_27();
extern "C" void _s80098988_28();
extern "C" void _s80098988_29();
extern "C" void _s80098988_30();
extern "C" void _s80098988_31();
extern "C" void _s80098988_32();
extern "C" void _s80098988_33();
extern "C" void _s80098988_34();
extern "C" void _s80098988_35();
extern "C" void f_80098988() {}
