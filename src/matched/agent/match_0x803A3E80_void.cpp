// 0x803A3E80 void (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-128(1); mfspr 0,8; stmw 26,0x68(1); stw 0,0x84(1); mr 31,3; lis 30,-17874; lwz 0,0x4(31); ori 30,30,35747; lwz 9,0x0(31); mr 27,5; mr 26,6; mr 3,27; subf 0,9,0; addi 4,1,96; mullw 0,0,30; li 5,1; srawi 0,0,3; stw 0,0x60(1); bl _s803A3E80_0; lwz 28,0x4(31); lwz 0,0x0(31); lwz 11,0x60(1); subf 0,0,28; mullw 0,0,30; srawi 29,0,3; subf. 0,11,29; bge 0f; li 0,-1; addi 30,1,8; stw 0,0x8(1); li 9,0; subf 29,29,11; addi 4,1,32; li 5,64; sth 0,0xa(30); stw 9,0xc(30); addi 3,1,24; stw 0,0x4(30); sth 0,0x8(30); bl _s803A3E80_1; mr 4,28; mr 5,29; mr 6,30; mr 3,31; bl _s803A3E80_2; b 3f; 0:; ble 3f; mulli 0,0,88; subf 0,0,28; lwz 11,0x4(31); mr 9,0; cmpw 0,11; beq 2f; 1:; addi 9,9,88; cmpw 9,11; bne 1b; 2:; stw 0,0x4(31); 3:; lwz 30,0x0(31); b 5f; 4:; mr 3,30; mr 4,27; mr 5,26; addi 30,30,88; bl _s803A3E80_3; 5:; lwz 0,0x4(31); cmpw 30,0; bne 4b; lwz 0,0x84(1); mtspr 8,0; lmw 26,0x68(1); addi 1,1,128"
extern "C" void _s803A3E80_0();
extern "C" void _s803A3E80_1();
extern "C" void _s803A3E80_2();
extern "C" void _s803A3E80_3();
extern "C" void f_803A3E80() {}
