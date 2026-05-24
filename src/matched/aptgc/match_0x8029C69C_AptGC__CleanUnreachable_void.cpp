// 0x8029C69C AptGC::CleanUnreachable(void) (408 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 3,-27600(13); bl _s8029C69C_0; lwz 3,-23016(13); bl _s8029C69C_1; lis 9,-32726; lwz 29,-27024(13); addi 9,9,-14764; mr. 31,3; stw 9,-27024(13); beq 2f; li 30,1; 0:; lwz 0,0x0(31); andi. 9,0,16128; beq 1f; rlwinm 9,0,2,30,31; andis. 11,0,16384; bne 1f; andi. 11,9,1; bne 1f; rlwimi 0,30,30,1,1; lwz 9,0x8(31); stw 0,0x0(31); lha 3,0x70(9); lwz 0,0x74(9); add 3,31,3; mtspr 8,0; blrl; 1:; lwz 3,-23016(13); mr 4,31; bl _s8029C69C_2; mr. 31,3; bne 0b; 2:; bl _s8029C69C_3; lwz 3,-23016(13); stw 29,-27024(13); bl _s8029C69C_4; lwz 30,-27028(13); li 0,1; stw 0,-27028(13); mr. 31,3; beq 5f; 3:; lwz 0,0x0(31); andis. 9,0,16384; bne 4f; lwz 9,0x8(31); lwz 0,0x5c(9); lha 3,0x58(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x8(31); lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; 4:; lwz 3,-23016(13); mr 4,31; bl _s8029C69C_5; mr. 31,3; bne 3b; 5:; lwz 3,-23016(13); stw 30,-27028(13); bl _s8029C69C_6; mr. 31,3; beq 9f; li 30,0; 6:; lwz 0,0x0(31); andis. 9,0,16384; bne 7f; lwz 9,0x8(31); lha 3,0x50(9); lwz 0,0x54(9); add 3,31,3; mtspr 8,0; blrl; lwz 3,-23016(13); mr 4,31; b 8f; 7:; lwz 3,-23016(13); rlwimi 0,30,30,1,1; mr 4,31; stw 0,0x0(31); 8:; bl _s8029C69C_7; mr 31,3; cmpwi 31,0; bne 6b; 9:; lwz 3,-27600(13); bl _s8029C69C_8; bl _s8029C69C_9; bl _s8029C69C_10; bl _s8029C69C_11; bl _s8029C69C_12; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s8029C69C_0();
extern "C" void _s8029C69C_1();
extern "C" void _s8029C69C_2();
extern "C" void _s8029C69C_3();
extern "C" void _s8029C69C_4();
extern "C" void _s8029C69C_5();
extern "C" void _s8029C69C_6();
extern "C" void _s8029C69C_7();
extern "C" void _s8029C69C_8();
extern "C" void _s8029C69C_9();
extern "C" void _s8029C69C_10();
extern "C" void _s8029C69C_11();
extern "C" void _s8029C69C_12();

struct AptGC {
    void CleanUnreachable();
};

void AptGC::CleanUnreachable() {
}
