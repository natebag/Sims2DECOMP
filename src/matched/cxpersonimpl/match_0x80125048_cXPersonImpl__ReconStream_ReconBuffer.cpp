// 0x80125048 cXPersonImpl::ReconStream(ReconBuffer (860 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-168(1); mfspr 0,8; mfcr 12; stmw 24,0x88(1); stw 0,0xac(1); stw 12,0x84(1); mr 30,5; mr 31,3; cmpwi 30,10; mr 29,4; lwz 3,0x0(31); mfcr 28; bl _s80125048_0; mtcrf 128,28; bgt 0f; mr 3,29; addi 4,1,8; li 5,28; bl _s80125048_1; 0:; cmpwi 7,30,12; mfcr 27; rlwinm 27,27,28,0,3; cmpwi 30,2; cmpwi 7,30,42; mfcr 26; rlwinm 26,26,28,0,3; cmpwi 4,30,87; cmpwi 3,30,43; cmpwi 2,30,44; ble 4f; lwz 3,0x3f4(31); mr 4,29; mr 5,30; lwz 9,0x0(3); lha 0,0x98(9); lwz 9,0x9c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 30,3; ble 1f; mr 3,29; addi 4,31,168; li 5,16; bl _s80125048_2; 1:; cmpwi 30,7; ble 2f; mr 3,29; addi 4,31,232; li 5,16; bl _s80125048_3; b 4f; 2:; lwz 0,0xc(29); cmpwi 0,0; bne 4f; li 0,16; lis 9,-32706; mtspr 9,0; lfs f0,-12996(9); addi 11,31,232; 3:; stfs f0,0x0(11); addi 11,11,4; bdnz 3b; 4:; mtcrf 128,28; ble 6f; cmpwi 30,40; ble 5f; mr 3,29; addi 4,31,8; li 5,80; bl _s80125048_4; b 6f; 5:; mr 3,29; addi 4,31,8; li 5,64; bl _s80125048_5; 6:; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x210(9); lwz 9,0x214(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; li 0,10; beq 7f; li 0,20; 7:; sth 0,0x7c(31); lwz 11,0x4(31); lwz 9,0x4(11); lwz 0,0x204(9); lha 3,0x200(9); mtspr 8,0; add 3,11,3; blrl; subfic 0,3,0; adde 3,0,3; mtcrf 128,27; sth 3,0x8a(31); ble 8f; lwz 4,0x40c(31); addi 3,31,1036; mr 5,29; mr 6,30; bl _s80125048_6; 8:; mtcrf 128,26; ble 15f; addi 25,31,304; bgt cr4,10f; addi 3,1,8; bl _s80125048_7; addi 3,1,8; mr 4,29; mr 5,30; bl _s80125048_8; mr 3,25; addi 4,1,8; bl _s80125048_9; addi 3,1,8; li 9,1; lwz 0,0x38(3); cmpwi 0,0; bne 9f; li 9,0; 9:; stw 9,0x534(31); li 4,2; bl _s80125048_10; 10:; cmpwi 30,79; bgt 11f; lwz 0,0xc(29); cmpwi 0,0; bne 11f; addi 3,1,8; bl _s80125048_11; addi 3,1,8; mr 4,29; mr 5,30; bl _s80125048_12; addi 3,1,8; li 4,2; bl _s80125048_13; 11:; lwz 0,0x2ac(25); mr 3,29; lwz 9,0x2a8(25); addi 4,1,120; li 5,1; li 28,0; subf 0,9,0; addi 24,31,1056; stw 0,0x78(1); bl _s80125048_14; lwz 0,0x78(1); cmpw 28,0; bge 14f; lis 26,-13108; mr 27,25; ori 26,26,52429; 12:; lwz 0,0xc(29); cmpwi 0,0; bne 13f; addi 3,1,8; bl _s80125048_15; addi 4,1,8; mr 3,25; bl _s80125048_16; addi 3,1,8; li 4,2; bl _s80125048_17; 13:; lwz 3,0x2a8(27); mr 4,29; mr 5,30; add 3,3,28; mulhwu 0,3,26; addi 28,28,1; rlwinm 0,0,29,3,31; mulli 0,0,10; subf 3,0,3; mulli 3,3,68; add 3,27,3; bl _s80125048_18; lwz 0,0x78(1); cmpw 28,0; blt 12b; 14:; lwz 4,0x420(31); mr 3,24; mr 5,29; mr 6,30; bl _s80125048_19; 15:; ble cr3,16f; lwz 4,0x3e4(31); mr 6,30; addi 3,31,996; mr 5,29; bl _s80125048_20; 16:; ble cr4,17f; mr 3,29; addi 4,31,1332; bl _s80125048_21; 17:; bgt cr2,18f; li 0,0; sth 0,0x3c(31); sth 0,0xa(31); sth 0,0x18(31); sth 0,0x32(31); sth 0,0x34(31); sth 0,0x36(31); sth 0,0x38(31); sth 0,0x3a(31); 18:; lwz 0,0xac(1); lwz 12,0x84(1); mtspr 8,0; lmw 24,0x88(1); mtcrf 56,12; addi 1,1,168"

extern "C" void _s80125048_0();
extern "C" void _s80125048_1();
extern "C" void _s80125048_2();
extern "C" void _s80125048_3();
extern "C" void _s80125048_4();
extern "C" void _s80125048_5();
extern "C" void _s80125048_6();
extern "C" void _s80125048_7();
extern "C" void _s80125048_8();
extern "C" void _s80125048_9();
extern "C" void _s80125048_10();
extern "C" void _s80125048_11();
extern "C" void _s80125048_12();
extern "C" void _s80125048_13();
extern "C" void _s80125048_14();
extern "C" void _s80125048_15();
extern "C" void _s80125048_16();
extern "C" void _s80125048_17();
extern "C" void _s80125048_18();
extern "C" void _s80125048_19();
extern "C" void _s80125048_20();
extern "C" void _s80125048_21();

struct cXPersonImpl {
    void ReconStream_ReconBuffer();
};

void cXPersonImpl::ReconStream_ReconBuffer() {
}
