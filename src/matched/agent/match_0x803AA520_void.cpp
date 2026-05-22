// 0x803AA520 void (424 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-216(1); mfspr 0,8; stmw 25,0xbc(1); stw 0,0xdc(1); mr 29,3; lis 30,-15985; lwz 9,0x0(29); ori 30,30,39961; lwz 0,0x4(29); mr 27,5; mr 25,6; mr 3,27; subf 0,9,0; addi 4,1,176; mullw 0,0,30; li 5,1; srawi 0,0,2; stw 0,0xb0(1); bl _s803AA520_0; lwz 31,0x4(29); lwz 0,0x0(29); lwz 9,0xb0(1); subf 0,0,31; mullw 0,0,30; srawi 0,0,2; subf. 11,9,0; bge 3f; subf 30,0,9; addi 3,1,8; bl _s803AA520_1; addi 28,1,8; mr 4,31; mr 5,30; mr 3,29; mr 6,28; bl _s803AA520_2; lwz 0,0x4(28); lis 9,-32698; lwz 11,0x8(1); addi 9,9,18992; stw 9,0x18(1); cmpw 11,0; beq 1f; 0:; addi 11,11,16; cmpw 11,0; bne 0b; 1:; lwz 3,0x0(28); cmpwi 3,0; beq 10f; lwz 0,0xc(28); subf 0,3,0; rlwinm 4,0,0,0,27; cmplwi 4,128; ble 2f; bl _s803AA520_3; b 10f; 2:; bl _s803AA520_4; b 10f; 3:; ble 10f; mulli 0,11,164; subf 28,0,31; lwz 30,0x4(29); mr 11,28; cmpw 28,30; beq 9f; lis 9,-32698; addi 26,9,18992; 4:; lwz 0,0x4(11); addi 31,11,164; lwz 9,0x0(11); stw 26,0x10(11); cmpw 9,0; beq 6f; 5:; addi 9,9,16; cmpw 9,0; bne 5b; 6:; lwz 3,0x0(11); cmpwi 3,0; beq 8f; lwz 0,0xc(11); subf 0,3,0; rlwinm 4,0,0,0,27; cmplwi 4,128; ble 7f; bl _s803AA520_5; b 8f; 7:; bl _s803AA520_6; 8:; mr 11,31; cmpw 11,30; bne 4b; 9:; stw 28,0x4(29); 10:; lwz 30,0x0(29); b 12f; 11:; mr 3,30; mr 4,27; mr 5,25; addi 30,30,164; bl _s803AA520_7; 12:; lwz 0,0x4(29); cmpw 30,0; bne 11b; lwz 0,0xdc(1); mtspr 8,0; lmw 25,0xbc(1); addi 1,1,216"
extern "C" void _s803AA520_0();
extern "C" void _s803AA520_1();
extern "C" void _s803AA520_2();
extern "C" void _s803AA520_3();
extern "C" void _s803AA520_4();
extern "C" void _s803AA520_5();
extern "C" void _s803AA520_6();
extern "C" void _s803AA520_7();
extern "C" void f_803AA520() {}
