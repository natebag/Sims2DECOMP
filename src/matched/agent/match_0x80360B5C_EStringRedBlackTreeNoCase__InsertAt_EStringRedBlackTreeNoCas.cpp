// 0x80360B5C EStringRedBlackTreeNoCase::InsertAt(EStringRedBlackTreeNoCaseNoCaseNode (364 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 29,3; mr 30,4; mr 27,5; mr 26,6; li 3,32; bl _s80360B5C_0; mr 31,3; addi 28,31,28; mr 3,28; bl _s80360B5C_1; cmpwi 31,0; bne 0f; li 3,0; b 12f; 0:; lis 9,-32700; li 0,1; addi 9,9,11816; stw 0,0x14(31); stw 9,0x4(31); mr 3,28; mr 4,27; stw 30,0x8(31); stw 9,0x0(31); bl _s80360B5C_2; stw 26,0x18(31); cmpwi 30,0; beq 6f; lwz 4,0x1c(31); addi 3,30,28; bl _s80360B5C_3; cmpwi 3,0; ble 2f; lwz 9,0xc(30); stw 31,0x0(30); cmpwi 9,0; beq 1f; stw 31,0x10(9); stw 30,0x10(31); lwz 0,0xc(30); stw 31,0xc(30); b 10f; 1:; lwz 9,0x0(29); stw 9,0x10(31); cmpwi 9,0; bne 7f; b 8f; 2:; lwz 9,0x10(30); stw 31,0x4(30); cmpwi 9,0; beq 3f; stw 31,0xc(9); stw 30,0xc(31); lwz 0,0x10(30); stw 31,0x10(30); stw 0,0x10(31); b 11f; 3:; lwz 9,0x4(29); stw 9,0xc(31); cmpwi 9,0; beq 4f; stw 31,0x10(9); b 5f; 4:; stw 31,0x0(29); 5:; li 0,0; stw 31,0x4(29); stw 0,0x10(31); b 11f; 6:; lwz 9,0x0(29); stw 31,0x8(29); stw 9,0x10(31); cmpwi 9,0; beq 8f; 7:; stw 31,0xc(9); b 9f; 8:; stw 31,0x4(29); 9:; li 0,0; stw 31,0x0(29); 10:; stw 0,0xc(31); 11:; mr 3,29; mr 4,31; bl _s80360B5C_4; mr 3,31; 12:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s80360B5C_0();
extern "C" void _s80360B5C_1();
extern "C" void _s80360B5C_2();
extern "C" void _s80360B5C_3();
extern "C" void _s80360B5C_4();
extern "C" void f_80360B5C() {}
