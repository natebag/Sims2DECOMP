// 0x80311A50 EResourceLoaderImpl::DoLoadResource(EResourceManager (484 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; mfcr 12; stmw 27,0x1c(1); stw 0,0x34(1); stw 12,0x18(1); li 0,0; mr 29,4; mr 28,5; stw 7,0x8(1); stw 8,0xc(1); li 27,0; stw 0,0x10(1); mr. 31,6; beq 1f; lwz 3,0x40(29); lis 4,-32702; addi 4,4,1120; bl _s80311A50_0; cmpwi 3,0; bne 0f; lwz 9,0x28(31); li 5,0; lwz 4,0x8(1); lha 3,0x28(9); lwz 0,0x2c(9); add 3,31,3; mtspr 8,0; blrl; b 3f; 0:; lwz 9,0x28(31); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,31,3; blrl; lwz 0,0xc(1); add 27,3,0; b 3f; 1:; mr 3,29; mr 4,28; addi 5,1,8; addi 6,1,12; bl _s80311A50_1; cmpwi 3,0; li 3,0; beq 9f; mr 3,29; bl _s80311A50_2; mr. 31,3; bne 2f; li 3,0; b 9f; 2:; lwz 9,0x28(31); li 5,0; lwz 4,0x8(1); lha 3,0x28(9); lwz 0,0x2c(9); add 3,31,3; mtspr 8,0; blrl; 3:; lwz 9,0xd1c(29); mr 4,31; lwz 5,0xc(1); mr 6,28; lwz 0,0x4c(9); lha 3,0x48(9); mtspr 8,0; add 3,29,3; blrl; lwz 0,0x10(1); mr 30,3; cmpwi 0,0; beq 4f; lis 3,-32694; addi 4,1,16; addi 3,3,-10620; bl _s80311A50_3; 4:; cmpwi 30,0; cmpwi 4,27,0; beq 6f; lwz 0,0x10(30); rlwinm. 9,0,24,8,31; bne 5f; lwz 9,0xc(1); rlwimi 0,9,8,0,23; stw 0,0x10(30); 5:; mr 5,28; mr 3,29; mr 4,30; li 6,1; bl _s80311A50_4; bne cr4,7f; mr 3,29; mr 4,30; bl _s80311A50_5; 6:; beq cr4,8f; 7:; lwz 9,0x28(31); lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; cmpw 3,27; beq 8f; lwz 9,0x28(31); mr 4,27; li 5,0; lha 3,0x28(9); lwz 0,0x2c(9); add 3,31,3; mtspr 8,0; blrl; 8:; mr 3,30; 9:; lwz 0,0x34(1); lwz 12,0x18(1); mtspr 8,0; lmw 27,0x1c(1); mtcrf 8,12; addi 1,1,48"
extern "C" void _s80311A50_0();
extern "C" void _s80311A50_1();
extern "C" void _s80311A50_2();
extern "C" void _s80311A50_3();
extern "C" void _s80311A50_4();
extern "C" void _s80311A50_5();
extern "C" void f_80311A50() {}
