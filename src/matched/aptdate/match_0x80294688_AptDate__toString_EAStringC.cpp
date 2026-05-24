// 0x80294688 AptDate::toString(EAStringC (728 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-136(1); mfspr 0,8; stmw 24,0x68(1); stw 0,0x8c(1); lis 9,-32704; addi 11,1,8; lwz 30,0x689c(9); lis 10,-32704; addi 9,9,26780; addi 28,1,40; lwz 29,0x18(9); mr 25,11; lwz 7,0x4(9); mr 24,28; lwz 6,0x8(9); mr 26,3; lwz 5,0xc(9); mr 31,4; lwz 8,0x10(9); addi 10,10,26808; lwz 0,0x14(9); addi 27,1,96; stw 30,0x8(1); li 9,48; stw 7,0x4(11); stw 6,0x8(11); stw 5,0xc(11); stw 8,0x10(11); stw 0,0x14(11); stw 29,0x18(11); 0:; lwz 0,0x0(10); addic. 9,9,-24; stw 0,0x0(28); lwz 0,0x4(10); stw 0,0x4(28); lwz 0,0x8(10); stw 0,0x8(28); lwz 0,0xc(10); stw 0,0xc(28); lwz 0,0x10(10); stw 0,0x10(28); lwz 0,0x14(10); addi 10,10,24; stw 0,0x14(28); addi 28,28,24; bne 0b; lwz 4,0x3c(26); mr 3,26; lwz 5,0x38(26); lwz 6,0x34(26); bl _s80294688_0; rlwinm 4,3,2,0,29; add 4,4,25; addi 3,1,88; bl _s80294688_1; lwz 11,0x58(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x0(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 1f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80294688_2; 1:; lwz 4,0x58(1); stw 4,0x0(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 2f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80294688_3; 2:; lis 30,-32704; mr 3,31; addi 4,30,26856; lis 29,-32704; bl _s80294688_4; lis 28,-32704; lwz 4,0x38(26); mr 3,31; rlwinm 4,4,2,0,29; add 4,24,4; bl _s80294688_5; addi 4,30,26856; mr 3,31; bl _s80294688_6; lwz 5,0x34(26); lis 4,-32704; addi 4,4,26860; mr 3,27; crxor 6,6,6; bl _s80294688_7; mr 4,27; mr 3,31; bl _s80294688_8; addi 4,30,26856; mr 3,31; bl _s80294688_9; lwz 5,0x2c(26); addi 4,29,26864; mr 3,27; crxor 6,6,6; bl _s80294688_10; mr 4,27; mr 3,31; bl _s80294688_11; addi 4,28,26872; mr 3,31; bl _s80294688_12; lwz 5,0x28(26); addi 4,29,26864; mr 3,27; crxor 6,6,6; bl _s80294688_13; mr 4,27; mr 3,31; bl _s80294688_14; addi 4,28,26872; mr 3,31; bl _s80294688_15; lwz 5,0x24(26); addi 4,29,26864; mr 3,27; crxor 6,6,6; bl _s80294688_16; mr 4,27; mr 3,31; bl _s80294688_17; lis 4,-32704; mr 3,31; addi 4,4,26876; bl _s80294688_18; lwz 0,0x64(26); cmpwi 0,0; bge 3f; lis 9,-32704; addi 4,9,26884; b 4f; 3:; lis 9,-32704; addi 4,9,26888; 4:; mr 3,31; bl _s80294688_19; lwz 0,0x64(26); lis 4,-32704; addi 4,4,26864; mr 3,27; srawi 9,0,31; xor 5,9,0; subf 5,9,5; crxor 6,6,6; bl _s80294688_20; mr 4,27; mr 3,31; bl _s80294688_21; lis 4,-32704; mr 3,31; addi 4,4,26892; bl _s80294688_22; lwz 5,0x3c(26); lis 4,-32704; addi 4,4,26860; mr 3,27; crxor 6,6,6; bl _s80294688_23; mr 3,31; mr 4,27; bl _s80294688_24; lwz 0,0x8c(1); mtspr 8,0; lmw 24,0x68(1); addi 1,1,136"

extern "C" void _s80294688_0();
extern "C" void _s80294688_1();
extern "C" void _s80294688_2();
extern "C" void _s80294688_3();
extern "C" void _s80294688_4();
extern "C" void _s80294688_5();
extern "C" void _s80294688_6();
extern "C" void _s80294688_7();
extern "C" void _s80294688_8();
extern "C" void _s80294688_9();
extern "C" void _s80294688_10();
extern "C" void _s80294688_11();
extern "C" void _s80294688_12();
extern "C" void _s80294688_13();
extern "C" void _s80294688_14();
extern "C" void _s80294688_15();
extern "C" void _s80294688_16();
extern "C" void _s80294688_17();
extern "C" void _s80294688_18();
extern "C" void _s80294688_19();
extern "C" void _s80294688_20();
extern "C" void _s80294688_21();
extern "C" void _s80294688_22();
extern "C" void _s80294688_23();
extern "C" void _s80294688_24();

struct AptDate {
    void toString_EAStringC();
};

void AptDate::toString_EAStringC() {
}
