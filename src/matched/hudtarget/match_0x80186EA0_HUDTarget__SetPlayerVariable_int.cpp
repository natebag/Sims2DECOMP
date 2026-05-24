// 0x80186EA0 HUDTarget::SetPlayerVariable(int, (800 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 30,5; mr 29,4; lis 3,-32705; mr 28,6; addi 3,3,-20928; mr 4,30; bl _s80186EA0_0; cmpwi 3,0; bne 0f; mr 3,31; li 4,0; bl _s80186EA0_1; b 15f; 0:; lis 3,-32705; mr 4,30; addi 3,3,-21060; bl _s80186EA0_2; cmpwi 3,0; bne 5f; mr 3,28; bl _s80186EA0_3; rlwinm 0,3,0,24,31; stb 3,0xe8(31); cmpwi 0,1; beq 3f; bgt 1f; cmpwi 0,0; beq 2f; b 15f; 1:; cmpwi 0,2; beq 4f; b 15f; 2:; mr 3,31; bl _s80186EA0_4; b 15f; 3:; mr 3,31; bl _s80186EA0_5; b 15f; 4:; mr 3,31; bl _s80186EA0_6; b 15f; 5:; lis 3,-32705; mr 4,30; addi 3,3,-20004; bl _s80186EA0_7; cmpwi 3,0; bne 11f; mr 3,28; bl _s80186EA0_8; rlwinm 3,3,0,24,31; cmpwi 3,1; beq 8f; bgt 6f; cmpwi 3,0; beq 7f; b 15f; 6:; cmpwi 3,2; beq 9f; cmpwi 3,3; beq 10f; b 15f; 7:; mr 3,31; mr 4,29; bl _s80186EA0_9; b 15f; 8:; mr 3,31; mr 4,29; bl _s80186EA0_10; b 15f; 9:; mr 3,31; mr 4,29; bl _s80186EA0_11; b 15f; 10:; addi 9,31,233; stbx 3,9,29; b 15f; 11:; lis 3,-32705; mr 4,30; addi 3,3,-19988; bl _s80186EA0_12; cmpwi 3,0; beq 15f; lis 3,-32705; mr 4,30; addi 3,3,-21072; bl _s80186EA0_13; mr. 0,3; bne 12f; lis 9,-32705; stb 0,0x100(31); lfs f0,-19968(9); li 4,0; stw 0,0xdc(31); li 5,0; stw 0,0xe4(31); mr 3,31; stfs f0,0xcc(31); bl _s80186EA0_14; addi 3,31,1856; bl _s80186EA0_15; addi 3,31,264; bl _s80186EA0_16; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 15f; mr 3,31; li 4,1; li 5,0; bl _s80186EA0_17; addi 3,31,2036; bl _s80186EA0_18; addi 3,31,1060; bl _s80186EA0_19; b 15f; 12:; lis 3,-32705; mr 4,30; addi 3,3,-21088; bl _s80186EA0_20; mr. 3,3; bne 13f; li 0,1; stb 3,0x100(31); stw 0,0xe4(31); li 5,0; addi 3,31,1856; mr 4,31; bl _s80186EA0_21; addi 3,31,264; mr 4,31; bl _s80186EA0_22; mr 3,31; li 4,0; li 5,1; bl _s80186EA0_23; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 15f; li 5,1; addi 3,31,2036; mr 4,31; bl _s80186EA0_24; addi 3,31,1060; mr 4,31; bl _s80186EA0_25; mr 3,31; li 4,1; li 5,1; bl _s80186EA0_26; b 15f; 13:; lis 3,-32705; mr 4,30; addi 3,3,-21048; bl _s80186EA0_27; mr. 29,3; bne 14f; mr 3,31; bl _s80186EA0_28; mr 3,31; li 4,0; bl _s80186EA0_29; mr 3,31; li 4,1; bl _s80186EA0_30; mr 3,31; li 4,0; bl _s80186EA0_31; mr 3,31; li 4,1; bl _s80186EA0_32; mr 3,31; bl _s80186EA0_33; stb 29,0xea(31); stb 29,0xe8(31); stb 29,0xe9(31); b 15f; 14:; lis 3,-32705; mr 4,30; addi 3,3,-20856; bl _s80186EA0_34; cmpwi 3,0; beq 15f; lis 3,-32705; mr 4,30; addi 3,3,-21028; bl _s80186EA0_35; mr. 3,3; bne 15f; stb 3,0x100(31); 15:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s80186EA0_0();
extern "C" void _s80186EA0_1();
extern "C" void _s80186EA0_2();
extern "C" void _s80186EA0_3();
extern "C" void _s80186EA0_4();
extern "C" void _s80186EA0_5();
extern "C" void _s80186EA0_6();
extern "C" void _s80186EA0_7();
extern "C" void _s80186EA0_8();
extern "C" void _s80186EA0_9();
extern "C" void _s80186EA0_10();
extern "C" void _s80186EA0_11();
extern "C" void _s80186EA0_12();
extern "C" void _s80186EA0_13();
extern "C" void _s80186EA0_14();
extern "C" void _s80186EA0_15();
extern "C" void _s80186EA0_16();
extern "C" void _s80186EA0_17();
extern "C" void _s80186EA0_18();
extern "C" void _s80186EA0_19();
extern "C" void _s80186EA0_20();
extern "C" void _s80186EA0_21();
extern "C" void _s80186EA0_22();
extern "C" void _s80186EA0_23();
extern "C" void _s80186EA0_24();
extern "C" void _s80186EA0_25();
extern "C" void _s80186EA0_26();
extern "C" void _s80186EA0_27();
extern "C" void _s80186EA0_28();
extern "C" void _s80186EA0_29();
extern "C" void _s80186EA0_30();
extern "C" void _s80186EA0_31();
extern "C" void _s80186EA0_32();
extern "C" void _s80186EA0_33();
extern "C" void _s80186EA0_34();
extern "C" void _s80186EA0_35();

struct HUDTarget {
    void SetPlayerVariable();
};

void HUDTarget::SetPlayerVariable() {
}
