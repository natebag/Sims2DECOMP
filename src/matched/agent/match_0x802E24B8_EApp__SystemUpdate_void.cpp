// 0x802E24B8 EApp::SystemUpdate(void) (568 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; bl _s802E24B8_0; cmpwi 3,6; bgt 0f; cmpwi 3,4; bge 1f; cmpwi 3,0; beq 4f; b 2f; 0:; cmpwi 3,8; beq 4f; cmpwi 3,11; bne 2f; 1:; li 0,1; b 3f; 2:; li 0,0; 3:; stw 0,-26820(13); 4:; lwz 30,-26820(13); cmpwi 30,0; bne 12f; lwz 0,0x450(31); cmpwi 0,2; bne 6f; lwz 0,0x454(31); cmpwi 0,2; beq 6f; lwz 11,-26392(13); lwz 9,0x0(11); lwz 0,0x44(9); lha 3,0x40(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26512(13); lwz 9,0x0(11); lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; lwz 3,0x458(31); cmpwi 3,0; beq 5f; bl _s802E24B8_1; lis 3,-32692; lwz 4,0x458(31); addi 3,3,-24196; li 5,1; bl _s802E24B8_2; stw 30,0x458(31); 5:; lwz 9,0x338(31); lha 3,0x28(9); lwz 0,0x2c(9); add 3,31,3; mtspr 8,0; blrl; 6:; lwz 0,0x454(31); cmpwi 0,1; bne 9f; lwz 11,-26564(13); lwz 9,0x0(11); lwz 0,0x4c(9); lha 3,0x48(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x338(31); lha 3,0x20(9); lwz 0,0x24(9); add 3,31,3; mtspr 8,0; blrl; lis 3,-32692; lwz 4,0x45c(31); addi 3,3,-24196; li 5,0; li 6,0; bl _s802E24B8_3; stw 3,0x458(31); cmpwi 3,0; beq 7f; lwz 11,-26512(13); lwz 9,0x0(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lwz 3,0x458(31); lwz 4,0x460(31); lwz 5,0x464(31); bl _s802E24B8_4; li 0,2; stw 0,0x454(31); b 8f; 7:; stw 3,0x454(31); 8:; li 0,0; stw 0,0x45c(31); 9:; lwz 0,0x454(31); lwz 11,-26512(13); stw 0,0x450(31); lwz 9,0x0(11); lha 3,0x38(9); lwz 0,0x3c(9); add 3,11,3; mtspr 8,0; blrl; lwz 3,0x458(31); cmpwi 3,0; beq 10f; bl _s802E24B8_5; 10:; lwz 9,0x338(31); lwz 0,0xac(9); lha 3,0xa8(9); mtspr 8,0; add 3,31,3; blrl; lwz 11,-26512(13); lwz 9,0x0(11); lha 3,0x40(9); lwz 0,0x44(9); add 3,11,3; mtspr 8,0; blrl; lwz 3,0x458(31); cmpwi 3,0; beq 11f; bl _s802E24B8_6; cmpwi 3,0; beq 11f; li 0,0; stw 0,0x454(31); 11:; bl _s802E24B8_7; 12:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802E24B8_0();
extern "C" void _s802E24B8_1();
extern "C" void _s802E24B8_2();
extern "C" void _s802E24B8_3();
extern "C" void _s802E24B8_4();
extern "C" void _s802E24B8_5();
extern "C" void _s802E24B8_6();
extern "C" void _s802E24B8_7();
extern "C" void f_802E24B8() {}
