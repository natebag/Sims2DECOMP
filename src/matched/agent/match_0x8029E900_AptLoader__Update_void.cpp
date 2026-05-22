// 0x8029E900 AptLoader::Update(void) (404 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 26,0x20(1); stw 0,0x3c(1); mr 30,3; 0:; lwz 0,0x0(30); li 29,0; b 13f; 1:; lwz 3,0x0(3); stw 3,0x10(1); cmpwi 3,0; beq 2f; bl _s8029E900_0; 2:; lis 9,-32694; li 26,2; addi 27,9,-16288; li 28,4; b 8f; 3:; cmpwi 9,3; bne 6f; stw 3,0x18(1); cmpwi 3,0; beq 4f; bl _s8029E900_1; 4:; addi 31,1,24; mr 3,30; mr 4,31; bl _s8029E900_2; cmpwi 3,0; beq 11f; lwz 9,0x10(1); li 29,1; stw 28,0x8(9); lwz 11,0x10(1); lwz 3,0x10(11); lwz 5,0x14(11); mr 4,3; addi 3,3,8; bl _s8029E900_3; lwz 3,0x10(1); stw 3,0x18(1); cmpwi 3,0; beq 5f; bl _s8029E900_4; 5:; mr 4,31; mr 3,30; bl _s8029E900_5; b 7f; 6:; addi 0,9,-4; cmplwi 0,1; ble 11f; 7:; lwz 0,0x0(30); stw 0,0x8(1); stw 0,0x18(1); 8:; lwz 3,0x10(1); lwz 9,0x8(3); cmpwi 9,1; bne 10f; stw 26,0x8(3); lwz 3,0x10(1); stw 3,0x18(1); cmpwi 3,0; beq 9f; bl _s8029E900_6; 9:; lwz 9,0x10(1); addi 4,1,24; lwz 11,0x20(27); lwz 3,0x4(9); mtspr 8,11; addi 3,3,8; blrl; b 7b; 10:; cmpwi 9,2; bne 3b; 11:; lwz 3,0x10(1); cmpwi 3,0; beq 12f; bl _s8029E900_7; cmpwi 3,0; bne 12f; lwz 3,0x10(1); bl _s8029E900_8; 12:; lwz 9,0x8(1); lwz 0,0x4(9); 13:; stw 0,0x8(1); li 0,0; lwz 3,0x8(1); stw 0,0x10(1); li 0,1; cmpwi 3,0; bne 14f; li 0,0; 14:; cmpwi 0,0; bne 1b; cmpwi 29,0; bne 0b; lwz 0,0x3c(1); mtspr 8,0; lmw 26,0x20(1); addi 1,1,56"
extern "C" void _s8029E900_0();
extern "C" void _s8029E900_1();
extern "C" void _s8029E900_2();
extern "C" void _s8029E900_3();
extern "C" void _s8029E900_4();
extern "C" void _s8029E900_5();
extern "C" void _s8029E900_6();
extern "C" void _s8029E900_7();
extern "C" void _s8029E900_8();
extern "C" void f_8029E900() {}
