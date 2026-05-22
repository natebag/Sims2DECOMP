// 0x803A46FC void (444 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 25,0x34(1); stw 0,0x54(1); mr 31,3; lis 30,-21846; lwz 0,0x4(31); ori 30,30,43691; lwz 9,0x0(31); mr 26,5; addi 4,1,40; li 5,1; subf 0,9,0; mr 25,6; mullw 0,0,30; mr 3,26; srawi 0,0,3; stw 0,0x28(1); bl _s803A46FC_0; lwz 4,0x4(31); lwz 0,0x0(31); lwz 5,0x28(1); subf 0,0,4; mullw 0,0,30; srawi 11,0,3; subf. 0,5,11; bge 3f; li 0,0; addi 30,1,8; stw 0,0x8(1); addi 9,30,8; stw 0,0x4(30); subf 5,11,5; stw 0,0x4(9); mr 3,31; stw 0,0x14(30); mr 6,30; stw 0,0x10(30); bl _s803A46FC_1; lwz 0,0x4(30); lwz 9,0x8(1); cmpw 9,0; beq 1f; 0:; addi 9,9,88; cmpw 9,0; bne 0b; 1:; lwz 3,0x0(30); cmpwi 3,0; beq 10f; lwz 0,0xc(30); lis 9,-17874; ori 9,9,35747; subf 0,3,0; mullw 0,0,9; srawi 0,0,3; mulli 4,0,88; cmplwi 4,128; ble 2f; bl _s803A46FC_2; b 10f; 2:; bl _s803A46FC_3; b 10f; 3:; ble 10f; mulli 0,0,24; subf 27,0,4; lwz 28,0x4(31); mr 11,27; cmpw 27,28; beq 9f; lis 30,-17874; ori 30,30,35747; 4:; lwz 9,0x0(11); addi 29,11,24; lwz 0,0x4(11); mr 3,9; cmpw 9,0; beq 6f; 5:; addi 9,9,88; cmpw 9,0; bne 5b; 6:; cmpwi 3,0; beq 8f; lwz 0,0xc(11); subf 0,3,0; mullw 0,0,30; srawi 0,0,3; mulli 4,0,88; cmplwi 4,128; ble 7f; bl _s803A46FC_4; b 8f; 7:; bl _s803A46FC_5; 8:; mr 11,29; cmpw 11,28; bne 4b; 9:; stw 27,0x4(31); 10:; lwz 30,0x0(31); b 12f; 11:; mr 3,30; mr 4,26; mr 5,25; addi 30,30,24; bl _s803A46FC_6; 12:; lwz 0,0x4(31); cmpw 30,0; bne 11b; lwz 0,0x54(1); mtspr 8,0; lmw 25,0x34(1); addi 1,1,80"
extern "C" void _s803A46FC_0();
extern "C" void _s803A46FC_1();
extern "C" void _s803A46FC_2();
extern "C" void _s803A46FC_3();
extern "C" void _s803A46FC_4();
extern "C" void _s803A46FC_5();
extern "C" void _s803A46FC_6();
extern "C" void f_803A46FC() {}
