// 0x803AE260 vector<CTilePt, (372 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 28,3; lis 9,-21846; lwz 31,0x0(28); ori 9,9,43691; lwz 0,0xc(28); mr 27,4; subf 0,31,0; mullw 0,0,9; cmplw 0,27; bge 13f; lwz 26,0x4(28); cmpwi 31,0; subf 0,31,26; mullw 24,0,9; beq 8f; cmpwi 27,0; beq 1f; rlwinm 0,27,1,0,30; add 3,0,27; mr 25,0; cmplwi 3,128; ble 0f; bl _s803AE260_0; mr 29,3; b 2f; 0:; bl _s803AE260_1; mr 29,3; b 2f; 1:; li 29,0; li 25,0; 2:; mr 30,29; cmpw 31,26; rlwinm 23,24,1,0,30; beq 4f; 3:; mr 3,30; mr 4,31; bl _s803AE260_2; addi 31,31,3; addi 30,30,3; cmpw 31,26; bne 3b; 4:; lwz 30,0x4(28); lwz 31,0x0(28); cmpw 31,30; beq 6f; 5:; mr 3,31; li 4,2; bl _s803AE260_3; addi 31,31,3; cmpw 31,30; bne 5b; 6:; lwz 3,0x0(28); lwz 0,0xc(28); cmpwi 3,0; subf 4,3,0; beq 12f; cmplwi 4,128; ble 7f; bl _s803AE260_4; b 12f; 7:; bl _s803AE260_5; b 12f; 8:; cmpwi 27,0; beq 10f; rlwinm 0,27,1,0,30; add 3,0,27; mr 25,0; cmplwi 3,128; ble 9f; bl _s803AE260_6; b 11f; 9:; bl _s803AE260_7; b 11f; 10:; li 3,0; li 25,0; 11:; mr 29,3; rlwinm 23,24,1,0,30; 12:; add 9,23,24; add 0,25,27; add 9,9,29; add 0,0,29; stw 0,0xc(28); stw 29,0x0(28); stw 9,0x4(28); 13:; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"
extern "C" void _s803AE260_0();
extern "C" void _s803AE260_1();
extern "C" void _s803AE260_2();
extern "C" void _s803AE260_3();
extern "C" void _s803AE260_4();
extern "C" void _s803AE260_5();
extern "C" void _s803AE260_6();
extern "C" void _s803AE260_7();
extern "C" void f_803AE260() {}
