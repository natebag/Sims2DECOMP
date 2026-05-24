// 0x80347FD8 ENgcRenderer::NgcTriListInt(EDLEntry (896 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; mfcr 12; stmw 20,0x18(1); stw 0,0x4c(1); stw 12,0x14(1); lwz 0,-26252(13); li 27,0; mr 25,3; mr 31,4; cmpwi 0,0; stw 27,-26196(13); beq 20f; lwz 0,0x510(25); cmpwi 0,0; beq 0f; li 4,0; bl _s80347FD8_0; 0:; lbz 0,0x1(31); li 21,1; lwz 24,0x4(31); cmpwi 0,0; bne 1f; li 21,0; 1:; lwz 20,0x1c(31); cmpwi 24,254; lwz 26,0x8(31); li 23,3; lwz 30,0xc(31); lwz 29,0x10(31); lwz 28,0x14(31); lwz 22,0x18(31); bgt 2f; li 23,2; 2:; cmpwi 7,20,0; bne cr7,3f; li 23,1; 3:; lwz 9,0x4d8(25); cmpwi 4,28,0; lwz 0,0x6cc(9); stw 27,0x4c(9); oris 0,0,32768; stw 27,0x4(9); ori 0,0,1; stw 27,0x28(9); stw 0,0x6cc(9); stw 27,0x2c(9); stw 27,0x30(9); stw 27,0x38(9); stw 27,0x3c(9); stw 27,0x40(9); stw 27,0x44(9); stw 27,0x48(9); lwz 11,0x4d8(25); lwz 0,0x6cc(11); stw 23,0x28(11); oris 0,0,32768; ori 0,0,1; stw 0,0x6cc(11); beq cr4,4f; lwz 9,0x4d8(25); lwz 0,0x6cc(9); stw 23,0x2c(9); oris 0,0,32768; ori 0,0,1; stw 0,0x6cc(9); 4:; cmpwi 29,0; mfcr 31; beq 5f; lwz 9,0x4d8(25); lwz 0,0x6cc(9); stw 23,0x30(9); oris 0,0,32768; ori 0,0,1; stw 0,0x6cc(9); 5:; cmpwi 6,30,0; mfcr 27; rlwinm 27,27,24,0,3; mcrf cr0,cr6; beq 6f; lwz 9,0x4d8(25); lwz 0,0x6cc(9); stw 23,0x38(9); oris 0,0,32768; ori 0,0,1; stw 0,0x6cc(9); 6:; cmpwi 22,0; beq 7f; bne cr7,14f; stw 21,0x8(1); mr 5,24; mr 6,26; mr 7,28; mr 8,30; mr 9,29; mr 10,22; mr 3,25; li 4,144; bl _s80347FD8_1; b 20f; 7:; bne cr7,14f; cmpwi 21,0; mfcr 31; beq 8f; lwz 9,0x4d8(25); lwz 0,0x6cc(9); stw 23,0x3c(9); oris 0,0,32768; ori 0,0,1; stw 0,0x6cc(9); 8:; lwz 3,0x4d8(25); li 4,0; bl _s80347FD8_2; li 3,144; li 4,6; rlwinm 5,24,0,16,31; bl _s80347FD8_3; cmpw 22,24; bge 20f; mtspr 9,24; rlwinm 31,31,4,0,31; mtcrf 1,31; rlwinm 31,31,28,0,31; lis 8,-13311; 9:; lha 0,0x0(26); cmpwi 28,0; lha 9,0x2(26); lha 11,0x4(26); sth 0,-32768(8); addi 26,26,8; sth 9,-32768(8); sth 11,-32768(8); beq 10f; lbz 0,0x0(28); lbz 11,0x1(28); lbz 9,0x2(28); extsb 0,0; stb 0,-32768(8); extsb 11,11; extsb 9,9; stb 11,-32768(8); stb 9,-32768(8); addi 28,28,4; 10:; cmpwi 29,0; beq 11f; lbz 0,0x0(29); lbz 9,0x1(29); lbz 11,0x2(29); lbz 10,0x3(29); stb 0,-32768(8); addi 29,29,4; stb 9,-32768(8); stb 11,-32768(8); stb 10,-32768(8); 11:; cmpwi 30,0; beq 13f; lha 0,0x0(30); lha 9,0x2(30); sth 0,-32768(8); sth 9,-32768(8); beq cr7,12f; lha 0,0x4(30); addi 30,30,4; sth 0,-32768(8); sth 0,-32768(8); 12:; addi 30,30,4; 13:; bdnz 9b; b 20f; 14:; mr 4,26; li 3,9; li 5,8; bl _s80347FD8_4; beq cr4,15f; mr 4,28; li 3,10; li 5,4; bl _s80347FD8_5; 15:; mtcrf 128,31; beq 16f; mr 4,29; li 3,11; li 5,4; bl _s80347FD8_6; 16:; cmpwi 21,0; mfcr 31; mtcrf 128,27; beq 18f; li 5,4; mtcrf 128,31; beq 17f; li 5,8; 17:; li 3,13; mr 4,30; bl _s80347FD8_7; mtcrf 128,31; beq 19f; addi 4,30,4; li 3,14; li 5,8; bl _s80347FD8_8; 18:; mtcrf 128,31; beq 19f; lwz 9,0x4d8(25); lwz 0,0x6cc(9); stw 23,0x3c(9); oris 0,0,32768; ori 0,0,1; stw 0,0x6cc(9); 19:; lwz 3,0x4d8(25); li 4,0; bl _s80347FD8_9; mr 3,20; mr 4,22; bl _s80347FD8_10; 20:; lwz 9,0x4dc(25); addi 9,9,24; stw 9,0x4dc(25); lwz 0,0x4c(1); lwz 12,0x14(1); mtspr 8,0; lmw 20,0x18(1); mtcrf 8,12; addi 1,1,72"

extern "C" void _s80347FD8_0();
extern "C" void _s80347FD8_1();
extern "C" void _s80347FD8_2();
extern "C" void _s80347FD8_3();
extern "C" void _s80347FD8_4();
extern "C" void _s80347FD8_5();
extern "C" void _s80347FD8_6();
extern "C" void _s80347FD8_7();
extern "C" void _s80347FD8_8();
extern "C" void _s80347FD8_9();
extern "C" void _s80347FD8_10();

struct ENgcRenderer {
    void NgcTriListInt_EDLEntry();
};

void ENgcRenderer::NgcTriListInt_EDLEntry() {
}
