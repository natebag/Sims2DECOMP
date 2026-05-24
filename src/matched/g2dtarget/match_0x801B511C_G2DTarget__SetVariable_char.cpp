// 0x801B511C G2DTarget::SetVariable(char (756 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 31,3; lbz 3,0x0(30); mr 29,5; extsb 3,3; bl _s801B511C_0; cmpwi 3,0; beq 0f; addi 30,30,1; 0:; lis 3,-32705; mr 4,30; addi 3,3,3068; bl _s801B511C_1; cmpwi 3,0; bne 2f; mr 4,29; mr 3,31; bl _s801B511C_2; cmpwi 3,0; beq 14f; lwz 0,0x134(31); cmpwi 0,3; bne 14f; lwz 0,-31536(13); cmpwi 0,0; bne 1f; li 3,120; bl _s801B511C_3; bl _s801B511C_4; stw 3,-31536(13); 1:; lwz 3,-31536(13); lis 4,-13223; ori 4,4,29738; bl _s801B511C_5; b 5f; 2:; lis 3,-32705; mr 4,30; addi 3,3,3084; bl _s801B511C_6; cmpwi 3,0; bne 4f; mr 4,29; mr 3,31; bl _s801B511C_7; cmpwi 3,0; beq 14f; lwz 0,0x134(31); cmpwi 0,3; bne 14f; lwz 0,0xc8(31); cmpwi 0,0; beq 14f; lwz 0,-31536(13); cmpwi 0,0; bne 3f; li 3,120; bl _s801B511C_8; bl _s801B511C_9; stw 3,-31536(13); 3:; lwz 3,-31536(13); lis 4,-13223; ori 4,4,29738; bl _s801B511C_10; b 5f; 4:; lis 3,-32705; mr 4,30; addi 3,3,3104; bl _s801B511C_11; cmpwi 3,0; bne 6f; mr 4,29; mr 3,31; bl _s801B511C_12; cmpwi 3,0; beq 14f; lwz 9,0x134(31); cmpwi 9,3; bne 14f; lwz 0,0xc0(31); cmpwi 0,0; beq 14f; stw 9,0xb0(31); 5:; mr 3,31; bl _s801B511C_13; b 14f; 6:; lis 3,-32705; mr 4,30; addi 3,3,3124; bl _s801B511C_14; cmpwi 3,0; bne 9f; mr 4,29; mr 3,31; bl _s801B511C_15; cmpwi 3,0; beq 14f; lwz 0,0x134(31); cmpwi 0,3; bne 14f; lwz 10,0xb0(31); lfs f0,0x128(31); addi 11,10,-1; stfs f0,0x12c(31); cmpwi 11,-1; stw 11,0xb0(31); bne 7f; lwz 9,0xa4(31); addi 9,9,-1; stw 9,0xb0(31); b 8f; 7:; lwz 9,0xa4(31); divw 0,11,9; mullw 0,0,9; subf 0,0,11; stw 0,0xb0(31); 8:; lwz 0,0xb0(31); cmpw 10,0; b 10f; 9:; lis 3,-32705; mr 4,30; addi 3,3,3136; bl _s801B511C_16; cmpwi 3,0; bne 12f; mr 4,29; mr 3,31; bl _s801B511C_17; cmpwi 3,0; beq 14f; lwz 0,0x134(31); cmpwi 0,3; bne 14f; lwz 10,0xb0(31); lwz 11,0xa4(31); addi 9,10,1; lfs f0,0x128(31); divw 0,9,11; stfs f0,0x12c(31); mullw 0,0,11; subf 9,0,9; cmpw 10,9; stw 9,0xb0(31); 10:; beq 14f; mr 3,31; bl _s801B511C_18; lwz 0,-31536(13); cmpwi 0,0; bne 11f; li 3,120; bl _s801B511C_19; bl _s801B511C_20; stw 3,-31536(13); 11:; lis 4,-13521; lwz 3,-31536(13); ori 4,4,42957; bl _s801B511C_21; b 14f; 12:; lis 3,-32705; mr 4,30; addi 3,3,2808; bl _s801B511C_22; cmpwi 3,0; bne 13f; lwz 9,0xa4(31); li 0,3; stw 0,0x134(31); cmpwi 9,0; bne 14f; mr 3,31; bl _s801B511C_23; b 14f; 13:; lis 3,-32705; mr 4,30; addi 3,3,3152; bl _s801B511C_24; mr. 3,3; bne 14f; stw 3,0x8c(31); mr 3,31; bl _s801B511C_25; 14:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s801B511C_0();
extern "C" void _s801B511C_1();
extern "C" void _s801B511C_2();
extern "C" void _s801B511C_3();
extern "C" void _s801B511C_4();
extern "C" void _s801B511C_5();
extern "C" void _s801B511C_6();
extern "C" void _s801B511C_7();
extern "C" void _s801B511C_8();
extern "C" void _s801B511C_9();
extern "C" void _s801B511C_10();
extern "C" void _s801B511C_11();
extern "C" void _s801B511C_12();
extern "C" void _s801B511C_13();
extern "C" void _s801B511C_14();
extern "C" void _s801B511C_15();
extern "C" void _s801B511C_16();
extern "C" void _s801B511C_17();
extern "C" void _s801B511C_18();
extern "C" void _s801B511C_19();
extern "C" void _s801B511C_20();
extern "C" void _s801B511C_21();
extern "C" void _s801B511C_22();
extern "C" void _s801B511C_23();
extern "C" void _s801B511C_24();
extern "C" void _s801B511C_25();

struct G2DTarget {
    void SetVariable();
};

void G2DTarget::SetVariable() {
}
