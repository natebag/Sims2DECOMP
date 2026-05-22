// 0x803117A8 EResourceLoaderImpl::ProcessMessage(unsigned (680 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; mr. 31,4; beq 16f; lwz 0,0x0(31); cmpwi 0,4; beq 7f; bgt 1f; cmpwi 0,1; beq 2f; bgt 0f; cmpwi 0,0; beq 14f; b 16f; 0:; cmpwi 0,2; beq 14f; cmpwi 0,3; beq 3f; b 16f; 1:; cmpwi 0,6; beq 11f; blt 8f; cmpwi 0,7; beq 13f; cmpwi 0,8; beq 15f; b 16f; 2:; lwz 3,0x1c(31); bl _s803117A8_0; mr 3,31; bl _s803117A8_1; bl _s803117A8_2; bl _s803117A8_3; b 16f; 3:; bl _s803117A8_4; bl _s803117A8_5; lwz 0,0x4(31); cmpwi 0,0; beq 6f; lwz 0,0x24(31); cmpwi 0,0; ble 6f; 4:; lwz 3,0x4(31); addi 5,1,8; lwz 4,0x8(31); bl _s803117A8_6; cmpwi 3,0; bne 5f; lwz 4,0x4(31); mr 3,30; lwz 5,0x8(31); lwz 6,0xc(31); lwz 7,0x10(31); lwz 8,0x14(31); bl _s803117A8_7; stw 3,0x8(1); 5:; lwz 9,0x24(31); addi 9,9,-1; cmpwi 9,0; stw 9,0x24(31); bgt 4b; 6:; lwz 9,0x18(31); cmpwi 9,0; beq 14f; lwz 0,0x8(31); li 10,1; stw 0,0x4(9); lwz 11,0x18(31); lwz 0,0x14(31); stw 0,0x8(11); lwz 9,0x18(31); stw 10,0x0(9); b 14f; 7:; lwz 3,0x4(31); li 5,1; lwz 4,0x8(31); bl _s803117A8_8; b 14f; 8:; lwz 3,0x4(31); cmpwi 3,0; beq 9f; bl _s803117A8_9; stw 3,0xc(31); 9:; lwz 11,0xc(31); cmpwi 11,0; beq 10f; lwz 9,0x28(11); li 5,0; lwz 4,0x10(31); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0xc(31); lwz 4,0x1c(31); lwz 9,0x28(11); lwz 5,0x14(31); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,0x18(31); stw 3,0x14(31); cmpwi 9,0; beq 10f; li 0,0; li 10,1; stw 0,0x4(9); lwz 11,0x18(31); lwz 0,0x14(31); stw 0,0x8(11); lwz 9,0x18(31); stw 10,0x0(9); 10:; lwz 0,0x20(31); cmpwi 0,0; bne 16f; b 14f; 11:; lwz 11,0xc(31); cmpwi 11,0; beq 12f; lwz 9,0x28(11); li 5,0; lwz 4,0x10(31); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0xc(31); lwz 4,0x1c(31); lwz 9,0x28(11); lwz 5,0x14(31); lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,0x18(31); stw 3,0x14(31); cmpwi 9,0; beq 12f; li 0,0; li 10,1; stw 0,0x4(9); lwz 11,0x18(31); lwz 0,0x14(31); stw 0,0x8(11); lwz 9,0x18(31); stw 10,0x0(9); 12:; lwz 0,0x20(31); cmpwi 0,0; bne 16f; b 14f; 13:; lwz 3,0x4(31); bl _s803117A8_10; 14:; mr 3,31; bl _s803117A8_11; b 16f; 15:; mr 3,31; bl _s803117A8_12; 16:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s803117A8_0();
extern "C" void _s803117A8_1();
extern "C" void _s803117A8_2();
extern "C" void _s803117A8_3();
extern "C" void _s803117A8_4();
extern "C" void _s803117A8_5();
extern "C" void _s803117A8_6();
extern "C" void _s803117A8_7();
extern "C" void _s803117A8_8();
extern "C" void _s803117A8_9();
extern "C" void _s803117A8_10();
extern "C" void _s803117A8_11();
extern "C" void _s803117A8_12();
extern "C" void f_803117A8() {}
