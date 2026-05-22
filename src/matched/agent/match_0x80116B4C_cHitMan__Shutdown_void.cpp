// 0x80116B4C cHitMan::Shutdown(void) (436 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-120(1); mfspr 0,8; stmw 29,0x6c(1); stw 0,0x7c(1); mr 30,3; bl _s80116B4C_0; lwz 3,0x50(30); bl _s80116B4C_1; lwz 3,0x50(30); bl _s80116B4C_2; addi 11,30,32; lwz 9,0x4(11); lwz 0,0x8(9); stw 0,0x8(1); lwz 9,0x4(11); stw 0,0x18(1); stw 9,0x10(1); b 2f; 0:; lwz 3,0x14(3); cmpwi 3,0; beq 1f; bl _s80116B4C_3; 1:; lwz 0,0x18(1); mr 3,0; stw 0,0x28(1); bl _s80116B4C_4; lwz 0,0x28(1); stw 3,0x18(1); stw 0,0x20(1); 2:; lwz 3,0x18(1); li 29,1; lwz 10,0x10(1); cmpw 3,10; bne 3f; li 29,0; 3:; cmpwi 29,0; bne 0b; lwz 0,0x8(1); addi 31,30,32; stw 10,0x30(1); li 8,0; stw 0,0x20(1); stw 0,0x38(1); stw 10,0x40(1); lwz 9,0x4(31); lwz 11,0x8(9); cmpw 0,11; stw 11,0x48(1); bne 4f; lwz 0,0x4(31); stw 0,0x50(1); xor 8,10,0; subfic 9,8,0; adde 8,9,8; 4:; cmpwi 8,0; beq 5f; lwz 0,0x8(31); addi 30,30,16; cmpwi 0,0; beq 10f; lwz 9,0x4(31); mr 3,31; lwz 4,0x4(9); bl _s80116B4C_5; lwz 9,0x4(31); stw 9,0x8(9); lwz 11,0x4(31); stw 29,0x4(11); lwz 9,0x4(31); stw 9,0xc(9); stw 29,0x8(31); b 10f; 5:; addi 30,30,16; b 8f; 6:; mr 3,9; stw 9,0x60(1); bl _s80116B4C_6; lwz 0,0x60(1); stw 3,0x38(1); stw 0,0x58(1); mr 3,0; lwz 5,0x4(31); addi 6,5,12; addi 4,5,4; addi 5,5,8; bl _s80116B4C_7; mr. 3,3; beq 7f; li 4,24; bl _s80116B4C_8; 7:; lwz 9,0x8(31); addi 9,9,-1; stw 9,0x8(31); 8:; lwz 9,0x38(1); li 11,1; lwz 0,0x40(1); cmpw 9,0; bne 9f; li 11,0; 9:; cmpwi 11,0; bne 6b; 10:; mr 3,30; bl _s80116B4C_9; li 3,1; lwz 0,0x7c(1); mtspr 8,0; lmw 29,0x6c(1); addi 1,1,120"
extern "C" void _s80116B4C_0();
extern "C" void _s80116B4C_1();
extern "C" void _s80116B4C_2();
extern "C" void _s80116B4C_3();
extern "C" void _s80116B4C_4();
extern "C" void _s80116B4C_5();
extern "C" void _s80116B4C_6();
extern "C" void _s80116B4C_7();
extern "C" void _s80116B4C_8();
extern "C" void _s80116B4C_9();
extern "C" void f_80116B4C() {}
