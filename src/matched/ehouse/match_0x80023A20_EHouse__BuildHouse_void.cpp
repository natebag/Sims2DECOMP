// 0x80023A20 EHouse::BuildHouse(void) (396 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 28,0x40(1); stw 0,0x54(1); lis 9,-32707; lwz 11,-26392(13); lfs f0,0x954(9); mr 31,3; addi 30,1,16; stfs f0,0xc(1); stfs f0,0x8(1); lwz 9,0x0(11); lwz 0,0x44(9); lha 3,0x40(9); mtspr 8,0; add 3,11,3; blrl; lwz 4,0x1c(31); mr 3,30; bl _s80023A20_0; mr 3,30; addi 4,1,40; bl _s80023A20_1; lwz 9,0x14(31); li 0,1; stw 0,0x10(31); cmpwi 9,0; beq 0f; mr 3,31; bl _s80023A20_2; 0:; lwz 3,0x4(31); cmpwi 3,0; beq 1f; bl _s80023A20_3; lwz 3,0x4(31); bl _s80023A20_4; 1:; lwz 9,0x1c(31); li 0,-1; addis 9,9,3; stw 0,-15680(9); stw 0,-15684(9); lwz 3,0x8(31); bl _s80023A20_5; lwz 3,0x1c(31); bl _s80023A20_6; lwz 0,0x0(31); cmpwi 0,0; bne 6f; lwz 29,-21472(13); li 28,0; lwz 9,0x4(29); lwz 0,0x8(9); stw 0,0x38(1); mr 30,0; lwz 9,0x4(29); cmpw 30,9; stw 9,0x38(1); beq 4f; 2:; lwz 3,0x14(30); cmpwi 3,0; beq 3f; lwz 0,0x34(3); cmpwi 0,0; beq 3f; bl _s80023A20_7; cmpwi 3,0; bne 3f; lhz 0,0x10(30); cmplw 0,28; ble 3f; mr 28,0; 3:; mr 3,30; bl _s80023A20_8; lwz 0,0x4(29); mr 30,3; cmpw 30,0; stw 0,0x38(1); bne 2b; 4:; addi 4,28,1; lwz 3,0x1c(31); stw 4,0x2c(31); addis 9,3,3; lwz 0,-23884(9); cmpw 4,0; beq 5f; bl _s80023A20_9; 5:; mr 3,31; bl _s80023A20_10; mr 3,31; bl _s80023A20_11; 6:; li 0,1; li 3,0; stw 0,0x18(31); bl _s80023A20_12; lwz 0,0x54(1); mtspr 8,0; lmw 28,0x40(1); addi 1,1,80"

extern "C" void _s80023A20_0();
extern "C" void _s80023A20_1();
extern "C" void _s80023A20_2();
extern "C" void _s80023A20_3();
extern "C" void _s80023A20_4();
extern "C" void _s80023A20_5();
extern "C" void _s80023A20_6();
extern "C" void _s80023A20_7();
extern "C" void _s80023A20_8();
extern "C" void _s80023A20_9();
extern "C" void _s80023A20_10();
extern "C" void _s80023A20_11();
extern "C" void _s80023A20_12();

struct EHouse {
    void BuildHouse();
};

void EHouse::BuildHouse() {
}
