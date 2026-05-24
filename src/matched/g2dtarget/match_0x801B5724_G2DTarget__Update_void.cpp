// 0x801B5724 G2DTarget::Update(void) (572 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 31,3; lwz 0,0x134(31); cmpwi 0,6; bne 2f; lis 9,-32697; li 4,47; lwz 3,0x5f10(9); bl _s801B5724_0; cmpwi 3,0; beq 8f; mr 3,31; bl _s801B5724_1; lwz 0,0xa4(31); cmpwi 0,0; ble 0f; lwz 4,0xb0(31); mr 3,31; bl _s801B5724_2; lwz 4,0x130(31); cmplwi 4,1; bgt 0f; lis 3,-32705; addi 3,3,3292; bl _s801B5724_3; li 0,-1; stw 0,0x130(31); 0:; lwz 4,0x98(31); cmpwi 4,0; beq 1f; mr 3,31; bl _s801B5724_4; addi 3,1,8; bl _s801B5724_5; lis 4,-32705; lis 5,-32705; addi 4,4,3308; addi 3,1,8; addi 5,5,3316; li 6,0; bl _s801B5724_6; li 0,0; addi 3,1,8; stw 0,0x98(31); li 4,2; bl _s801B5724_7; b 8f; 1:; mr 3,31; bl _s801B5724_8; b 8f; 2:; cmpwi 0,4; bne 4f; lwz 0,0xa4(31); cmpwi 0,0; bne 3f; lwz 9,0x90(31); cmpwi 9,44; bgt 3f; addi 0,9,1; stw 0,0x90(31); b 8f; 3:; addi 30,31,312; li 0,5; li 9,1; lis 4,-32705; lis 7,-32705; addi 4,4,2804; addi 7,7,3152; stw 0,0x134(31); stw 9,0x8c(31); mr 3,30; li 5,125; li 6,0; li 8,0; bl _s801B5724_9; mr 3,30; li 4,0; bl _s801B5724_10; mr 3,30; bl _s801B5724_11; b 8f; 4:; cmpwi 0,3; bne 8f; lwz 4,0x98(31); cmpwi 4,0; beq 5f; mr 3,31; bl _s801B5724_12; mr 3,31; bl _s801B5724_13; mr 3,31; bl _s801B5724_14; li 0,0; stw 0,0x98(31); b 8f; 5:; lwz 0,0x94(31); cmpwi 0,0; bne 6f; lwz 9,0x90(31); addi 9,9,1; cmpwi 9,45; stw 9,0x90(31); ble 6f; li 0,1; stw 0,0x94(31); 6:; lwz 0,0xa4(31); cmpwi 0,0; ble 8f; lis 9,-32697; lwz 0,0x6120(9); cmpwi 0,0; bne 7f; lwz 0,0xb8(31); cmpwi 0,0; beq 8f; 7:; lwz 0,0xbc(31); cmpwi 0,0; bne 8f; lis 9,-32705; lfs f13,0x12c(31); lfs f12,0xcf8(9); fcmpu 0,f13,f12; ble 8f; lfs f0,-26800(13); fsubs f0,f13,f0; fcmpu 0,f0,f12; stfs f0,0x12c(31); cror 3,2,0; bns 8f; li 0,3; li 9,1; stw 0,0xb0(31); mr 3,31; stw 9,0xbc(31); bl _s801B5724_15; 8:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"

extern "C" void _s801B5724_0();
extern "C" void _s801B5724_1();
extern "C" void _s801B5724_2();
extern "C" void _s801B5724_3();
extern "C" void _s801B5724_4();
extern "C" void _s801B5724_5();
extern "C" void _s801B5724_6();
extern "C" void _s801B5724_7();
extern "C" void _s801B5724_8();
extern "C" void _s801B5724_9();
extern "C" void _s801B5724_10();
extern "C" void _s801B5724_11();
extern "C" void _s801B5724_12();
extern "C" void _s801B5724_13();
extern "C" void _s801B5724_14();
extern "C" void _s801B5724_15();

struct G2DTarget {
    void Update();
};

void G2DTarget::Update() {
}
