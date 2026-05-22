// 0x801D3D68 PCTTarget::GetVariable(char (1032 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; mr 30,4; li 3,32; bl _s801D3D68_0; mr. 29,3; bne 0f; li 3,0; b 25f; 0:; li 0,0; lis 3,-32705; stb 0,0x0(29); addi 3,3,17276; mr 4,30; bl _s801D3D68_1; cmpwi 3,0; bne 1f; lis 4,-32705; lwz 5,0xc0(31); b 20f; 1:; lis 3,-32705; mr 4,30; addi 3,3,17312; bl _s801D3D68_2; cmpwi 3,0; bne 4f; lwz 0,0xc4(31); 2:; li 5,0; cmpwi 0,0; 3:; beq 22f; li 5,1; b 22f; 4:; lis 3,-32705; mr 4,30; addi 3,3,17332; bl _s801D3D68_3; cmpwi 3,0; bne 5f; lwz 0,0xc8(31); b 2b; 5:; lis 3,-32705; mr 4,30; addi 3,3,17352; bl _s801D3D68_4; cmpwi 3,0; bne 7f; lwz 0,0xc0(31); lis 9,-21846; ori 9,9,43691; li 10,1; mulhwu 11,0,9; rlwinm 9,11,30,2,31; mulli 9,9,6; cmpw 0,9; bne 6f; li 10,0; 6:; rlwinm 0,11,30,2,31; li 5,0; add 9,0,10; cmplwi 9,2; ble 22f; lwz 0,0xb4(31); li 5,1; cmpwi 0,0; bne 22f; li 5,0; b 22f; 7:; lis 3,-32705; mr 4,30; addi 3,3,17368; bl _s801D3D68_5; cmpwi 3,0; bne 9f; lwz 0,0xc0(31); lis 9,-21846; ori 9,9,43691; li 8,1; mulhwu 10,0,9; rlwinm 11,10,30,2,31; mulli 9,11,6; cmpw 0,9; bne 8f; li 8,0; 8:; rlwinm 0,10,30,2,31; li 5,0; add 11,0,8; cmplwi 11,2; ble 22f; lwz 9,0xb4(31); addi 0,11,-2; subfc 5,0,9; subfe 5,5,5; neg 5,5; b 22f; 9:; lis 3,-32705; mr 4,30; addi 3,3,17384; bl _s801D3D68_6; cmpwi 3,0; bne 10f; lwz 11,0xb0(31); li 5,1; lwz 0,0xac(31); cmplw 11,0; bge 22f; mulli 11,11,20; lwz 9,0xa8(31); lwzx 3,9,11; cmpwi 3,1; beq 22f; blt 22f; cmpwi 7,3,4; mfcr 5; rlwinm 5,5,30,31,31; b 22f; 10:; lis 3,-32705; mr 4,30; addi 3,3,17400; bl _s801D3D68_7; cmpwi 3,0; bne 11f; lwz 0,0x20c(31); b 2b; 11:; lis 3,-32705; mr 4,30; addi 3,3,17420; bl _s801D3D68_8; cmpwi 3,0; bne 14f; lwz 9,0x204(31); li 0,1; stw 0,0x98(31); li 5,0; cmpwi 9,0; bne 12f; lwz 0,0x23c(31); cmpwi 0,0; bne 12f; lwz 0,0x234(31); cmpwi 0,0; bne 12f; lwz 0,0x238(31); cmpwi 0,0; bne 12f; lwz 0,0xf0(31); cmpwi 0,0; beq 13f; 12:; li 5,1; 13:; lis 4,-32705; xori 5,5,1; b 20f; 14:; lis 3,-32705; mr 4,30; addi 3,3,17440; bl _s801D3D68_9; cmpwi 3,0; bne 17f; lwz 0,0x90(31); cmpwi 0,1; bne 15f; lis 9,-32705; addi 4,9,-5288; b 16f; 15:; lis 9,-32705; addi 4,9,-5284; 16:; mr 3,29; bl _s801D3D68_10; b 24f; 17:; lis 3,-32705; lwz 5,-23852(13); addi 3,3,18000; mr 4,30; bl _s801D3D68_11; mr. 3,3; bne 19f; stw 3,0x8(1); lis 4,-32705; mr 3,30; addi 4,4,18020; addi 5,1,8; li 30,0; crxor 6,6,6; bl _s801D3D68_12; cmpwi 3,1; bne 18f; mr 3,31; lwz 4,0xb8(3); bl _s801D3D68_13; mr. 3,3; beq 18f; lwz 30,0xc(3); 18:; cmpwi 30,0; li 5,0; b 3b; 19:; lis 3,-32705; mr 4,30; addi 3,3,17260; bl _s801D3D68_14; cmpwi 3,0; bne 21f; lis 4,-32705; lwz 5,0xac(31); 20:; addi 4,4,-8800; mr 3,29; crxor 6,6,6; bl _s801D3D68_15; b 24f; 21:; lis 3,-32705; mr 4,30; addi 3,3,17296; bl _s801D3D68_16; cmpwi 3,0; bne 23f; lwz 9,0xb0(31); lwz 0,0xac(31); cmplw 9,0; bge 24f; mulli 9,9,20; lwz 3,0xa8(31); add 0,3,9; cmpwi 0,0; beq 24f; lwzx 0,3,9; li 5,0; cmpwi 0,3; bne 22f; li 5,3; 22:; lis 4,-32705; mr 3,29; addi 4,4,-8800; crxor 6,6,6; bl _s801D3D68_17; b 24f; 23:; lis 3,-32705; mr 4,30; addi 3,3,17248; bl _s801D3D68_18; cmpwi 3,0; bne 24f; lis 9,-32705; addi 11,9,-8792; lwz 10,-8792(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(29); sth 0,0x4(29); stb 8,0x6(29); 24:; mr 3,29; bl _s801D3D68_19; mr 3,29; 25:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s801D3D68_0();
extern "C" void _s801D3D68_1();
extern "C" void _s801D3D68_2();
extern "C" void _s801D3D68_3();
extern "C" void _s801D3D68_4();
extern "C" void _s801D3D68_5();
extern "C" void _s801D3D68_6();
extern "C" void _s801D3D68_7();
extern "C" void _s801D3D68_8();
extern "C" void _s801D3D68_9();
extern "C" void _s801D3D68_10();
extern "C" void _s801D3D68_11();
extern "C" void _s801D3D68_12();
extern "C" void _s801D3D68_13();
extern "C" void _s801D3D68_14();
extern "C" void _s801D3D68_15();
extern "C" void _s801D3D68_16();
extern "C" void _s801D3D68_17();
extern "C" void _s801D3D68_18();
extern "C" void _s801D3D68_19();
extern "C" void f_801D3D68() {}
