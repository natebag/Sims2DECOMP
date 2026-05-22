// 0x801D3334 PCTTarget::~PCTTarget(void) (740 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 30,3; lis 9,-32698; lwz 0,0x0(30); addi 9,9,29080; mr 26,4; stw 9,0x80(30); cmpwi 0,0; beq 9f; lwz 3,0x4(30); addi 4,30,40; bl _s801D3334_0; lwz 3,0x8(30); addi 4,30,56; bl _s801D3334_1; lwz 3,0xc(30); addi 4,30,72; bl _s801D3334_2; addi 9,30,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 0f; lwz 0,0x58(30); cmpwi 0,0; beq 1f; 0:; li 11,1; 1:; cmpwi 11,0; beq 2f; lwz 3,0x10(30); bl _s801D3334_3; 2:; addi 9,30,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 3f; lwz 0,0x68(30); cmpwi 0,0; beq 4f; 3:; li 11,1; 4:; cmpwi 11,0; beq 5f; lwz 3,0x14(30); bl _s801D3334_4; 5:; lwz 3,0x18(30); cmpwi 3,0; beq 6f; lwz 4,0x7c(30); bl _s801D3334_5; 6:; lwz 3,0x1c(30); cmpwi 3,0; beq 7f; lwz 4,0x7c(30); bl _s801D3334_6; 7:; lwz 3,0x20(30); cmpwi 3,0; beq 8f; lwz 4,0x7c(30); bl _s801D3334_7; 8:; lwz 3,0x24(30); cmpwi 3,0; beq 9f; lwz 4,0x7c(30); bl _s801D3334_8; 9:; lis 9,-32697; li 4,30; addi 29,9,24012; lwz 3,0x144(29); bl _s801D3334_9; lwz 3,0xa4(30); cmpwi 3,0; beq 10f; bl _s801D3334_10; 10:; lwz 3,0xbc(30); li 31,0; stw 31,0xa4(30); cmpwi 3,0; beq 11f; bl _s801D3334_11; 11:; lwz 11,0x214(30); stw 31,0xbc(30); cmpwi 11,0; beq 12f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 12:; lwz 4,0x88(30); stw 31,0x214(30); cmpwi 4,0; beq 13f; li 3,0; bl _s801D3334_12; stw 31,0x88(30); 13:; lwz 4,0x8c(30); cmpwi 4,0; beq 14f; li 3,1; bl _s801D3334_13; stw 31,0x8c(30); 14:; stw 31,0x488(29); addi 9,30,540; mr 29,9; addi 28,30,380; lwz 11,0x21c(30); addi 27,30,244; lwz 0,0x4(9); cmpw 11,0; beq 16f; lwz 0,0x218(30); cmpwi 0,0; beq 16f; mr 31,11; 15:; lwz 11,0x218(30); li 4,5; lha 5,0x0(31); li 6,0; lwz 9,0x0(11); addi 31,31,2; lwz 0,0x4c(9); lha 3,0x48(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x4(29); cmpw 31,0; bne 15b; 16:; lwz 0,0x240(30); cmpwi 0,0; beq 17f; lis 9,-32697; addi 31,9,23428; lwz 0,0x48(31); cmpwi 0,0; beq 17f; li 3,1; bl _s801D3334_14; lis 9,-32705; lfs f0,0x4578(9); fcmpu 0,f1,f0; ble 17f; lwz 9,0x48(31); li 0,1; stw 0,0x98(9); 17:; lis 3,-32697; li 4,-1; addi 3,3,23428; bl _s801D3334_15; lwz 3,0x21c(30); cmpwi 3,0; beq 19f; lwz 0,0xc(29); subf 0,3,0; rlwinm 4,0,0,0,30; cmplwi 4,128; ble 18f; bl _s801D3334_16; b 19f; 18:; bl _s801D3334_17; 19:; mr 3,28; li 4,2; bl _s801D3334_18; mr 3,27; li 4,2; bl _s801D3334_19; lis 9,-32698; andi. 0,26,1; addi 9,9,-12328; stw 9,0x80(30); beq 20f; mr 3,30; bl _s801D3334_20; 20:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s801D3334_0();
extern "C" void _s801D3334_1();
extern "C" void _s801D3334_2();
extern "C" void _s801D3334_3();
extern "C" void _s801D3334_4();
extern "C" void _s801D3334_5();
extern "C" void _s801D3334_6();
extern "C" void _s801D3334_7();
extern "C" void _s801D3334_8();
extern "C" void _s801D3334_9();
extern "C" void _s801D3334_10();
extern "C" void _s801D3334_11();
extern "C" void _s801D3334_12();
extern "C" void _s801D3334_13();
extern "C" void _s801D3334_14();
extern "C" void _s801D3334_15();
extern "C" void _s801D3334_16();
extern "C" void _s801D3334_17();
extern "C" void _s801D3334_18();
extern "C" void _s801D3334_19();
extern "C" void _s801D3334_20();
extern "C" void f_801D3334() {}
