// 0x801624EC CasNpcEditor::Update(float) (1044 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-624(1); mfspr 0,8; stfd f31,0x268(1); stmw 29,0x25c(1); stw 0,0x274(1); mr 31,3; fmr f31,f1; lwz 0,0x8(31); cmpwi 0,0; beq 21f; bl _s801624EC_0; cmpwi 3,0; beq 3f; lfs f0,0x14(31); lis 9,-32706; lfs f13,-2652(9); fsubs f0,f0,f31; fcmpu 0,f0,f13; stfs f0,0x14(31); cror 3,2,0; bns 3f; stfs f13,0x14(31); mr 3,31; bl _s801624EC_1; cmpwi 3,0; beq 1f; lwz 0,-31536(13); cmpwi 0,0; bne 0f; li 3,120; bl _s801624EC_2; bl _s801624EC_3; stw 3,-31536(13); 0:; lis 4,-19795; lwz 3,-31536(13); ori 4,4,16077; bl _s801624EC_4; b 3f; 1:; lwz 0,-31536(13); cmpwi 0,0; bne 2f; li 3,120; bl _s801624EC_5; bl _s801624EC_6; stw 3,-31536(13); 2:; lis 4,-14130; lwz 3,-31536(13); ori 4,4,55855; bl _s801624EC_7; 3:; lwz 3,-26524(13); li 4,0; bl _s801624EC_8; mr 30,3; li 4,0; bl _s801624EC_9; mr 4,3; li 5,0; mr 3,30; li 6,8; bl _s801624EC_10; cmpwi 3,0; beq 11f; lwz 0,0x8(31); cmpwi 0,1; bne 6f; lwz 11,-32056(13); lis 4,21875; ori 4,4,25970; lwz 9,0xc(11); lha 3,0x78(9); lwz 0,0x7c(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,0x10(31); addi 30,9,1; cmplw 30,3; ble 4f; li 30,1; 4:; addi 29,1,8; addi 3,1,12; bl _s801624EC_11; mr 3,31; mr 4,30; mr 5,29; bl _s801624EC_12; cmpwi 3,0; beq 14f; lis 9,-32706; stw 30,0x10(31); lfs f0,-2648(9); addi 4,31,24; li 5,32; addi 3,1,16; stfs f0,0x14(31); bl _s801624EC_13; addi 4,31,56; li 5,32; addi 3,1,80; bl _s801624EC_14; lwz 0,0x8(1); addi 9,1,304; mr 4,9; mr 5,29; stw 0,0xc(31); li 11,288; 5:; lwz 0,0x0(5); addic. 11,11,-24; stw 0,0x0(9); lwz 0,0x4(5); stw 0,0x4(9); lwz 0,0x8(5); stw 0,0x8(9); lwz 0,0xc(5); stw 0,0xc(9); lwz 0,0x10(5); stw 0,0x10(9); lwz 0,0x14(5); addi 5,5,24; stw 0,0x14(9); addi 9,9,24; bne 5b; lwz 0,0x0(5); mr 3,31; stw 0,0x0(9); lwz 0,0x4(5); stw 0,0x4(9); bl _s801624EC_15; b 21f; 6:; cmpwi 0,2; bne 8f; lwz 9,0x10(31); addi 30,9,1; cmplwi 30,51; ble 7f; li 30,0; 7:; mr 3,31; mr 4,30; bl _s801624EC_16; mr. 29,3; bne 10f; b 14f; 8:; cmpwi 0,3; bne 21f; lwz 9,0x10(31); addi 30,9,1; cmplwi 30,161; ble 9f; li 30,0; 9:; mr 3,31; mr 4,30; bl _s801624EC_17; mr. 29,3; beq 14f; 10:; lis 9,-32706; stw 30,0x10(31); lfs f0,-2648(9); addi 4,31,24; li 5,32; addi 3,29,4; stfs f0,0x14(31); bl _s801624EC_18; addi 3,29,68; addi 4,31,56; li 5,32; bl _s801624EC_19; li 0,0; stw 0,0xc(31); b 21f; 11:; mr 3,31; bl _s801624EC_20; cmpwi 3,0; bne 21f; lwz 3,-26524(13); li 4,0; bl _s801624EC_21; mr 30,3; li 4,0; bl _s801624EC_22; mr 4,3; li 5,0; mr 3,30; li 6,2; bl _s801624EC_23; cmpwi 3,0; beq 21f; lwz 3,-26524(13); li 4,0; bl _s801624EC_24; mr 30,3; li 4,0; bl _s801624EC_25; mr 4,3; li 5,0; mr 3,30; li 6,3; bl _s801624EC_26; cmpwi 3,0; beq 16f; lwz 0,0x8(31); cmpwi 0,1; bne 12f; mr 3,31; bl _s801624EC_27; cmpwi 3,0; bne 17f; b 14f; 12:; cmpwi 0,2; bne 13f; mr 3,31; bl _s801624EC_28; cmpwi 3,0; bne 17f; b 14f; 13:; cmpwi 0,3; bne 21f; 14:; lwz 0,-31536(13); cmpwi 0,0; bne 15f; li 3,120; bl _s801624EC_29; bl _s801624EC_30; stw 3,-31536(13); 15:; lis 4,-14130; lwz 3,-31536(13); ori 4,4,55855; bl _s801624EC_31; b 21f; 16:; mr 3,31; bl _s801624EC_32; cmpwi 3,0; beq 19f; 17:; lwz 0,-31536(13); cmpwi 0,0; bne 18f; li 3,120; bl _s801624EC_33; bl _s801624EC_34; stw 3,-31536(13); 18:; lis 4,-19795; lwz 3,-31536(13); ori 4,4,16077; bl _s801624EC_35; b 21f; 19:; lwz 0,-31536(13); cmpwi 0,0; bne 20f; li 3,120; bl _s801624EC_36; bl _s801624EC_37; stw 3,-31536(13); 20:; lis 4,-14130; lwz 3,-31536(13); ori 4,4,55855; bl _s801624EC_38; 21:; lwz 0,0x274(1); mtspr 8,0; lmw 29,0x25c(1); lfd f31,0x268(1); addi 1,1,624"

extern "C" void _s801624EC_0();
extern "C" void _s801624EC_1();
extern "C" void _s801624EC_2();
extern "C" void _s801624EC_3();
extern "C" void _s801624EC_4();
extern "C" void _s801624EC_5();
extern "C" void _s801624EC_6();
extern "C" void _s801624EC_7();
extern "C" void _s801624EC_8();
extern "C" void _s801624EC_9();
extern "C" void _s801624EC_10();
extern "C" void _s801624EC_11();
extern "C" void _s801624EC_12();
extern "C" void _s801624EC_13();
extern "C" void _s801624EC_14();
extern "C" void _s801624EC_15();
extern "C" void _s801624EC_16();
extern "C" void _s801624EC_17();
extern "C" void _s801624EC_18();
extern "C" void _s801624EC_19();
extern "C" void _s801624EC_20();
extern "C" void _s801624EC_21();
extern "C" void _s801624EC_22();
extern "C" void _s801624EC_23();
extern "C" void _s801624EC_24();
extern "C" void _s801624EC_25();
extern "C" void _s801624EC_26();
extern "C" void _s801624EC_27();
extern "C" void _s801624EC_28();
extern "C" void _s801624EC_29();
extern "C" void _s801624EC_30();
extern "C" void _s801624EC_31();
extern "C" void _s801624EC_32();
extern "C" void _s801624EC_33();
extern "C" void _s801624EC_34();
extern "C" void _s801624EC_35();
extern "C" void _s801624EC_36();
extern "C" void _s801624EC_37();
extern "C" void _s801624EC_38();

struct CasNpcEditor {
    void Update();
};

void CasNpcEditor::Update() {
}
