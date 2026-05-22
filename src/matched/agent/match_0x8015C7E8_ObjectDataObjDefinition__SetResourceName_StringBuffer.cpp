// 0x8015C7E8 ObjectDataObjDefinition::SetResourceName(StringBuffer (572 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 26,0x18(1); stw 0,0x34(1); mr 28,3; mr 3,4; addi 29,28,4; bl _s8015C7E8_0; mr 31,3; bl _s8015C7E8_1; add 27,31,3; lwz 0,0x4(29); lwz 3,0x4(28); subf 30,31,27; subf 5,3,0; cmplw 30,5; bgt 1f; cmpwi 30,0; beq 0f; mr 4,31; mr 5,30; crxor 6,6,6; bl _s8015C7E8_2; 0:; lwz 0,0x4(28); lwz 31,0x4(29); add 30,0,30; cmpw 30,31; beq 18f; mr 3,30; mr 4,31; li 5,1; bl _s8015C7E8_3; lwz 0,0x4(29); subf 9,30,31; subf 0,9,0; b 17f; 1:; cmpwi 5,0; beq 2f; mr 4,31; crxor 6,6,6; bl _s8015C7E8_4; 2:; lwz 9,0x4(28); lwz 0,0x4(29); subf 3,9,0; add 28,31,3; cmpw 28,27; beq 18f; subf 31,28,27; li 0,-2; cmplw 31,0; stw 3,0x10(1); bgt 3f; subfic 0,31,-2; cmplw 3,0; ble 4f; 3:; mr 3,29; bl _s8015C7E8_5; 4:; lwz 0,0x0(29); lwz 9,0xc(29); lwz 11,0x10(1); subf 9,0,9; addi 9,9,-1; add 0,11,31; cmplw 0,9; ble 15f; cmplw 11,31; stw 31,0x8(1); addi 9,1,16; bge 5f; addi 9,1,8; 5:; lwz 0,0x0(9); add 0,11,0; addic. 26,0,1; beq 7f; cmplwi 26,128; ble 6f; mr 3,26; bl _s8015C7E8_6; mr 31,3; b 8f; 6:; mr 3,26; bl _s8015C7E8_7; mr 31,3; b 8f; 7:; li 31,0; 8:; lwz 4,0x0(29); lwz 30,0x4(29); cmpw 30,4; beq 9f; subf 30,4,30; mr 3,31; mr 5,30; bl _s8015C7E8_8; add 3,3,30; b 10f; 9:; mr 3,31; 10:; cmpw 27,28; beq 11f; subf 30,28,27; mr 4,28; mr 5,30; bl _s8015C7E8_9; add 30,3,30; b 12f; 11:; mr 30,3; 12:; li 0,0; stb 0,0x0(30); lwz 3,0x0(29); lwz 0,0xc(29); cmpwi 3,0; subf 4,3,0; beq 14f; cmplwi 4,128; ble 13f; bl _s8015C7E8_10; b 14f; 13:; bl _s8015C7E8_11; 14:; add 0,31,26; stw 30,0x4(29); stw 0,0xc(29); stw 31,0x0(29); b 18f; 15:; lwz 9,0x4(29); addi 4,28,1; cmpw 27,4; addi 3,9,1; beq 16f; subf 5,4,27; bl _s8015C7E8_12; 16:; lwz 9,0x4(29); li 0,0; stbx 0,9,31; lbz 11,0x0(28); lwz 9,0x4(29); stb 11,0x0(9); lwz 0,0x4(29); add 0,0,31; 17:; stw 0,0x4(29); 18:; lwz 0,0x34(1); mtspr 8,0; lmw 26,0x18(1); addi 1,1,48"
extern "C" void _s8015C7E8_0();
extern "C" void _s8015C7E8_1();
extern "C" void _s8015C7E8_2();
extern "C" void _s8015C7E8_3();
extern "C" void _s8015C7E8_4();
extern "C" void _s8015C7E8_5();
extern "C" void _s8015C7E8_6();
extern "C" void _s8015C7E8_7();
extern "C" void _s8015C7E8_8();
extern "C" void _s8015C7E8_9();
extern "C" void _s8015C7E8_10();
extern "C" void _s8015C7E8_11();
extern "C" void _s8015C7E8_12();
extern "C" void f_8015C7E8() {}
