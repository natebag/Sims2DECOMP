// 0x803ADE14 void (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stmw 27,0x5c(1); stw 0,0x74(1); mr 31,3; lis 30,14563; lwz 9,0x0(31); ori 30,30,36409; lwz 0,0x4(31); mr 28,5; mr 27,6; mr 3,28; subf 0,9,0; addi 4,1,80; mullw 0,0,30; li 5,1; srawi 0,0,3; stw 0,0x50(1); bl _s803ADE14_0; lwz 29,0x4(31); lwz 0,0x0(31); lwz 9,0x50(1); subf 0,0,29; mullw 0,0,30; srawi 0,0,3; subf. 11,9,0; bge 0f; subf 30,0,9; addi 3,1,8; bl _s803ADE14_1; mr 4,29; mr 5,30; mr 3,31; addi 6,1,8; bl _s803ADE14_2; b 3f; 0:; ble 3f; mulli 0,11,72; subf 0,0,29; lwz 11,0x4(31); mr 9,0; cmpw 0,11; beq 2f; 1:; addi 9,9,72; cmpw 9,11; bne 1b; 2:; stw 0,0x4(31); 3:; lwz 30,0x0(31); b 5f; 4:; mr 3,30; mr 4,28; mr 5,27; addi 30,30,72; bl _s803ADE14_3; 5:; lwz 0,0x4(31); cmpw 30,0; bne 4b; lwz 0,0x74(1); mtspr 8,0; lmw 27,0x5c(1); addi 1,1,112"
extern "C" void _s803ADE14_0();
extern "C" void _s803ADE14_1();
extern "C" void _s803ADE14_2();
extern "C" void _s803ADE14_3();
extern "C" void f_803ADE14() {}
