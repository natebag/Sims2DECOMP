// 0x802021A8 RGTTarget::SetVariable(char (464 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,4; mr 29,3; lbz 9,0x0(31); mr 30,5; addi 9,9,-48; cmplwi 9,1; bgt 0f; addi 31,31,1; 0:; lis 3,-32704; mr 4,31; addi 3,3,-17536; bl _s802021A8_0; cmpwi 3,0; bne 3f; mr 3,30; bl _s802021A8_1; mr 4,3; mr 3,29; bl _s802021A8_2; mr 31,3; cmpwi 31,9; bgt 8f; lwz 0,-31536(13); cmpwi 0,0; bne 1f; li 3,120; bl _s802021A8_3; bl _s802021A8_4; stw 3,-31536(13); 1:; lis 9,-32700; rlwinm 31,31,2,0,29; addi 30,9,-24388; lwz 3,-31536(13); lwzx 4,30,31; bl _s802021A8_5; lwz 0,0x8c(29); cmpwi 0,0; bne 2f; lis 3,-32704; lwzx 4,30,31; addi 3,3,-17516; bl _s802021A8_6; b 8f; 2:; lis 3,-32704; lwzx 4,30,31; addi 3,3,-17496; bl _s802021A8_7; b 8f; 3:; lis 3,-32704; mr 4,31; addi 3,3,-17476; bl _s802021A8_8; cmpwi 3,0; bne 5f; mr 3,30; bl _s802021A8_9; mr 4,3; mr 3,29; bl _s802021A8_10; mr 31,3; cmpwi 31,9; bgt 8f; lwz 0,-31536(13); cmpwi 0,0; bne 4f; li 3,120; bl _s802021A8_11; bl _s802021A8_12; stw 3,-31536(13); 4:; lis 9,-32700; rlwinm 0,31,2,0,29; addi 9,9,-24388; lwz 3,-31536(13); lwzx 4,9,0; bl _s802021A8_13; b 8f; 5:; lis 3,-32704; mr 4,31; addi 3,3,-17456; bl _s802021A8_14; cmpwi 3,0; bne 8f; lis 3,-32704; mr 4,30; addi 3,3,-30824; bl _s802021A8_15; cmpwi 3,0; bne 6f; lwz 9,0x88(29); lis 0,10922; ori 0,0,43691; addi 9,9,1; b 7f; 6:; lwz 9,0x88(29); lis 0,10922; ori 0,0,43691; addi 9,9,-1; 7:; mulhw 0,9,0; srawi 11,9,31; srawi 0,0,1; subf 0,11,0; mulli 0,0,12; subf 9,0,9; stw 9,0x88(29); mr 3,29; lwz 4,0x88(3); bl _s802021A8_16; 8:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802021A8_0();
extern "C" void _s802021A8_1();
extern "C" void _s802021A8_2();
extern "C" void _s802021A8_3();
extern "C" void _s802021A8_4();
extern "C" void _s802021A8_5();
extern "C" void _s802021A8_6();
extern "C" void _s802021A8_7();
extern "C" void _s802021A8_8();
extern "C" void _s802021A8_9();
extern "C" void _s802021A8_10();
extern "C" void _s802021A8_11();
extern "C" void _s802021A8_12();
extern "C" void _s802021A8_13();
extern "C" void _s802021A8_14();
extern "C" void _s802021A8_15();
extern "C" void _s802021A8_16();
extern "C" void f_802021A8() {}
