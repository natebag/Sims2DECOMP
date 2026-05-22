// 0x802404D0 DSIHandler (628 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 28,0x30(1); stw 0,0x44(1); mr 29,4; lwz 9,0x198(29); lwz 30,0x0(9); rlwinm 31,30,0,16,31; andi. 0,30,32768; beq 0f; oris 31,31,65535; 0:; rlwinm 0,30,18,25,29; lis 9,-13312; lwzx 11,29,0; ori 9,9,24604; cmpw 6,9; add 31,31,11; bne 15f; li 0,10; lis 11,3072; mtspr 9,0; addi 8,1,8; ori 11,11,24576; li 10,0; 1:; oris 9,11,49152; lwz 0,0x0(9); addi 11,11,4; stwx 0,10,8; addi 10,10,4; bdnz 1b; lwz 10,0x10(1); lis 8,-32694; lwz 0,0x14(1); li 9,0; mr 4,10; lwz 11,-26356(8); rlwinm 10,10,16,16,31; rlwinm 0,0,2,0,29; ori 9,9,57344; add 28,11,0; cmpw 10,9; beq 11f; bgt 3f; li 0,0; ori 0,0,43008; cmpw 10,0; beq 7f; bgt 2f; cmpwi 10,4608; beq 6f; b 14f; 2:; li 0,0; ori 0,0,43776; cmpw 10,0; beq 13f; b 14f; 3:; li 0,0; ori 0,0,57856; cmpw 10,0; beq 12f; bgt 4f; li 0,0; ori 0,0,57600; b 5f; 4:; li 0,0; ori 0,0,58112; cmpw 10,0; beq 13f; li 0,0; ori 0,0,58369; 5:; cmpw 10,0; beq 12f; b 14f; 6:; lwz 3,0x1c(1); bl _s802404D0_0; b 16f; 7:; lwz 0,0x20(1); cmpwi 0,0; bne 8f; lis 3,-32694; addi 3,3,-26400; bl _s802404D0_1; b 9f; 8:; mr 3,28; bl _s802404D0_2; lis 9,-32694; cmpwi 3,0; stw 3,-26368(9); bne 10f; lwz 5,0x20(1); lis 9,-32700; lis 11,-32694; lwz 3,-23456(9); lwz 4,0x1c(1); lis 6,-32732; stw 5,-26360(11); addi 6,6,892; mr 7,28; li 8,1; bl _s802404D0_3; cmpwi 3,-1; bne 9f; lis 0,3; lis 9,-32694; ori 0,0,4352; stw 0,-26368(9); 9:; lis 9,-32694; lwz 0,-26368(9); cmpwi 0,0; beq 16f; 10:; bl _s802404D0_4; b 16f; 11:; lis 11,-32694; lis 9,-13312; lwz 0,-26368(11); ori 9,9,24608; lis 3,-32694; stw 0,0x0(9); addi 3,3,-26400; rlwinm 0,0,0,0,7; stw 0,-26368(11); bl _s802404D0_5; b 16f; 12:; lis 9,-32694; lwz 0,-26432(9); cmpwi 0,0; bne 15f; 13:; lis 3,-32694; addi 3,3,-26400; bl _s802404D0_6; b 16f; 14:; lis 3,-32704; addi 3,3,-960; crxor 6,6,6; bl _s802404D0_7; .long 0x00000001; lis 0,5; lis 9,-32694; ori 0,0,8192; stw 0,-26368(9); bl _s802404D0_8; b 16f; 15:; bl _s802404D0_9; rlwinm 0,30,13,25,29; lwzx 9,29,0; stw 9,0x0(31); bl _s802404D0_10; 16:; lwz 9,0x198(29); addi 9,9,4; stw 9,0x198(29); mr 3,29; bl _s802404D0_11; lwz 0,0x44(1); mtspr 8,0; lmw 28,0x30(1); addi 1,1,64"
extern "C" void _s802404D0_0();
extern "C" void _s802404D0_1();
extern "C" void _s802404D0_2();
extern "C" void _s802404D0_3();
extern "C" void _s802404D0_4();
extern "C" void _s802404D0_5();
extern "C" void _s802404D0_6();
extern "C" void _s802404D0_7();
extern "C" void _s802404D0_8();
extern "C" void _s802404D0_9();
extern "C" void _s802404D0_10();
extern "C" void _s802404D0_11();
extern "C" void f_802404D0() {}
