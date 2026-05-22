// 0x803AE408 vector<PenaltyRect, (412 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; lis 9,-13108; lwz 30,0x0(29); ori 9,9,52429; lwz 0,0xc(29); subf 0,30,0; mullw 0,0,9; srawi 0,0,2; cmplw 0,4; bge 13f; lwz 28,0x4(29); cmpwi 30,0; subf 0,30,28; mullw 0,0,9; srawi 27,0,2; beq 8f; cmpwi 4,0; beq 1f; mulli 0,4,20; mr 31,0; cmplwi 0,128; ble 0f; mr 3,31; bl _s803AE408_0; b 2f; 0:; mr 3,31; bl _s803AE408_1; b 2f; 1:; li 3,0; li 31,0; 2:; mr 8,30; mulli 27,27,20; mr 7,3; cmpw 8,28; beq 4f; 3:; lwz 0,0x0(8); lwz 9,0x4(8); lwz 11,0x8(8); lwz 10,0xc(8); stw 0,0x0(7); stw 9,0x4(7); stw 11,0x8(7); stw 10,0xc(7); lwz 0,0x10(8); addi 8,8,20; stw 0,0x10(7); cmpw 8,28; addi 7,7,20; bne 3b; 4:; lwz 11,0x0(29); mr 30,3; lwz 0,0x4(29); mr 3,11; lwz 9,0xc(29); cmpw 11,0; beq 6f; 5:; addi 11,11,20; cmpw 11,0; bne 5b; 6:; lis 0,-13108; subf 9,3,9; ori 0,0,52429; cmpwi 3,0; mullw 9,9,0; srawi 4,9,2; beq 12f; mulli 4,4,20; cmplwi 4,128; ble 7f; bl _s803AE408_2; b 12f; 7:; bl _s803AE408_3; b 12f; 8:; cmpwi 4,0; beq 10f; mulli 0,4,20; mr 31,0; cmplwi 0,128; ble 9f; mr 3,31; bl _s803AE408_4; b 11f; 9:; mr 3,31; bl _s803AE408_5; b 11f; 10:; li 3,0; li 31,0; 11:; mulli 27,27,20; mr 30,3; 12:; add 9,27,30; add 0,31,30; stw 0,0xc(29); stw 30,0x0(29); stw 9,0x4(29); 13:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s803AE408_0();
extern "C" void _s803AE408_1();
extern "C" void _s803AE408_2();
extern "C" void _s803AE408_3();
extern "C" void _s803AE408_4();
extern "C" void _s803AE408_5();
extern "C" void f_803AE408() {}
