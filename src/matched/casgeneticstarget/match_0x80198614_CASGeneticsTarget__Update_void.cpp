// 0x80198614 CASGeneticsTarget::Update(void) (932 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stmw 24,0x50(1); stw 0,0x74(1); lwz 0,-31440(13); mr 31,3; cmpwi 0,3; beq 1f; cmplwi 0,3; bgt 0f; cmpwi 0,1; beq 4f; cmpwi 0,2; beq 6f; b 13f; 0:; cmpwi 0,4; beq 9f; cmpwi 0,5; beq 10f; b 13f; 1:; lis 9,-32697; addi 10,9,23428; lwz 11,0x3c(10); lwz 4,0x134c(11); mr 0,4; cmpwi 4,0; bge 2f; addi 0,4,3; 2:; rlwinm 0,0,0,0,29; lwz 9,0x1348(11); subf 0,0,4; li 24,1; slw 0,24,0; addi 25,31,172; andc 0,9,0; addi 26,31,464; stw 0,0x1348(11); lwz 3,0x3c(10); bl _s80198614_0; lwz 5,0x9c(31); li 4,1; lwz 3,0x94(31); bl _s80198614_1; lwz 27,0x0(3); li 4,0; lwz 5,0xa0(31); lwz 3,0x94(31); bl _s80198614_2; lwz 29,0x0(3); li 4,1; lwz 5,0xa4(31); lwz 3,0x94(31); bl _s80198614_3; lwz 28,0x0(3); li 4,0; lwz 5,0xa8(31); lwz 3,0x94(31); bl _s80198614_4; lwz 30,0x0(3); mr 4,27; lwz 3,0x94(31); mr 5,29; mr 6,25; li 7,1; bl _s80198614_5; lwz 3,0x94(31); mr 6,26; mr 4,28; mr 5,30; li 7,0; bl _s80198614_6; lwz 3,0x84(31); bl _s80198614_7; mr 6,3; lwz 3,0x94(31); cmpwi 3,0; beq 3f; cmpwi 6,0; beq 3f; lwz 7,0x2f4(31); mr 4,25; mr 5,26; xori 7,7,1; subfic 0,7,0; adde 7,0,7; bl _s80198614_8; stw 24,-31440(13); bl _s80198614_9; b 13f; 3:; li 0,0; stw 0,-31440(13); b 13f; 4:; addi 3,1,8; bl _s80198614_10; addi 3,1,8; li 4,16; bl _s80198614_11; lwz 30,-21480(13); addi 3,1,8; li 4,2; bl _s80198614_12; cmpwi 30,0; beq 13f; mr 3,31; li 4,0; bl _s80198614_13; lwz 3,0x2fc(31); cmpwi 3,0; beq 5f; li 4,3; bl _s80198614_14; 5:; li 0,0; li 4,0; stw 0,0x2fc(31); li 5,-1; mr 3,31; bl _s80198614_15; mr 3,31; li 4,1; li 5,-1; bl _s80198614_16; li 0,2; b 8f; 6:; addi 3,1,8; bl _s80198614_17; addi 3,1,8; li 4,16; bl _s80198614_18; lwz 30,-21480(13); addi 3,1,8; li 4,2; bl _s80198614_19; cmpwi 30,0; beq 13f; mr 3,31; li 4,1; bl _s80198614_20; lwz 3,0x2fc(31); cmpwi 3,0; beq 7f; li 4,3; bl _s80198614_21; 7:; li 0,0; li 4,2; stw 0,0x2fc(31); li 5,-1; mr 3,31; bl _s80198614_22; mr 3,31; li 4,3; li 5,-1; bl _s80198614_23; li 0,4; 8:; stw 0,-31440(13); bl _s80198614_24; b 13f; 9:; addi 3,1,8; bl _s80198614_25; addi 3,1,8; li 4,16; bl _s80198614_26; lwz 30,-21480(13); addi 3,1,8; li 4,2; bl _s80198614_27; cmpwi 30,0; beq 13f; li 0,5; stw 0,-31440(13); b 13f; 10:; lis 9,-32697; addi 7,9,23428; lwz 8,0x3c(7); lwz 10,0x134c(8); mr 9,10; cmpwi 10,0; bge 11f; addi 9,10,3; 11:; rlwinm 9,9,0,0,29; lwz 11,0x1348(8); subf 9,9,10; li 0,1; slw 0,0,9; or 11,11,0; stw 11,0x1348(8); lwz 3,0x3c(7); bl _s80198614_28; mr 3,31; bl _s80198614_29; lwz 0,0x300(31); lis 11,-32697; rlwinm 0,0,0,27,25; stw 0,0x300(31); lwz 9,0x6200(11); cmpwi 9,0; beq 12f; lwz 0,0x414(31); cmpwi 0,0; beq 12f; lwz 11,0x418(31); cmpwi 11,0; beq 12f; lwz 9,0x0(11); li 0,0; lwz 10,-26564(13); ori 9,9,8; stw 0,0x10(11); stw 9,0x0(11); lwz 11,0x0(10); lwz 5,0x418(31); lha 3,0xb0(11); lwz 0,0xb4(11); add 3,10,3; lwz 4,0x414(31); mtspr 8,0; blrl; 12:; lis 9,-32705; li 0,0; addi 9,9,-15588; lis 3,-32705; stw 0,-31440(13); addi 3,3,-14876; stw 9,0x48(1); li 4,0; li 5,0; li 6,1; addi 7,1,72; bl _s80198614_30; 13:; lwz 0,0x74(1); mtspr 8,0; lmw 24,0x50(1); addi 1,1,112"

extern "C" void _s80198614_0();
extern "C" void _s80198614_1();
extern "C" void _s80198614_2();
extern "C" void _s80198614_3();
extern "C" void _s80198614_4();
extern "C" void _s80198614_5();
extern "C" void _s80198614_6();
extern "C" void _s80198614_7();
extern "C" void _s80198614_8();
extern "C" void _s80198614_9();
extern "C" void _s80198614_10();
extern "C" void _s80198614_11();
extern "C" void _s80198614_12();
extern "C" void _s80198614_13();
extern "C" void _s80198614_14();
extern "C" void _s80198614_15();
extern "C" void _s80198614_16();
extern "C" void _s80198614_17();
extern "C" void _s80198614_18();
extern "C" void _s80198614_19();
extern "C" void _s80198614_20();
extern "C" void _s80198614_21();
extern "C" void _s80198614_22();
extern "C" void _s80198614_23();
extern "C" void _s80198614_24();
extern "C" void _s80198614_25();
extern "C" void _s80198614_26();
extern "C" void _s80198614_27();
extern "C" void _s80198614_28();
extern "C" void _s80198614_29();
extern "C" void _s80198614_30();

struct CASGeneticsTarget {
    void Update();
};

void CASGeneticsTarget::Update() {
}
