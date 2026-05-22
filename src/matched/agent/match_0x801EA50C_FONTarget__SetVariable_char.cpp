// 0x801EA50C FONTarget::SetVariable(char (436 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,4; mr 30,3; lbz 9,0x0(31); mr 29,5; addi 9,9,-48; cmplwi 9,1; bgt 0f; addi 31,31,1; 0:; lis 3,-32704; mr 4,31; addi 3,3,-30392; bl _s801EA50C_0; mr. 28,3; bne 4f; mr 3,29; bl _s801EA50C_1; mr 4,3; lwz 3,0x8c(30); cmpwi 3,0; beq 8f; bl _s801EA50C_2; mr. 31,3; beq 8f; lwz 3,0x10(31); li 0,1; cmpwi 3,0; bne 1f; li 0,0; 1:; cmpwi 0,0; beq 2f; bl _s801EA50C_3; lwz 9,0x4(3); lwz 4,0x10(31); lha 0,0xb0(9); lwz 9,0xb4(9); add 3,3,0; mtspr 8,9; blrl; stw 28,0x98(30); b 8f; 2:; lwz 9,0x8c(30); lwz 0,0x4(9); cmpwi 0,0; beq 3f; lwz 0,0xc(31); stw 0,0x4(9); lwz 3,0x8c(30); lwz 4,0x4(3); bl _s801EA50C_4; mr 5,3; lwz 9,0x8c(30); stw 5,0x88(30); mr 3,30; lwz 4,0x4(9); bl _s801EA50C_5; 3:; li 0,1; stw 0,0x98(30); b 8f; 4:; lis 3,-32704; mr 4,31; addi 3,3,-30372; bl _s801EA50C_6; cmpwi 3,0; bne 8f; lwz 9,0x8c(30); cmpwi 9,0; beq 8f; lwz 0,0x4(9); cmpwi 0,0; beq 8f; lwz 0,0x88(30); cmpwi 0,9; ble 7f; lis 3,-32704; mr 4,29; addi 3,3,-30824; bl _s801EA50C_7; cmpwi 3,0; bne 6f; lwz 9,0x8c(30); lwz 11,0x4(9); lwz 0,0x4(11); cmpwi 0,0; bne 5f; lwz 0,0xc(11); cmpwi 0,0; beq 7f; 5:; stw 0,0x4(9); b 7f; 6:; lwz 11,0x8c(30); lwz 9,0x4(11); lwz 9,0x0(9); cmpwi 9,0; beq 7f; stw 9,0x4(11); 7:; lwz 9,0x8c(30); mr 3,30; lwz 5,0x88(3); lwz 4,0x4(9); bl _s801EA50C_8; 8:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s801EA50C_0();
extern "C" void _s801EA50C_1();
extern "C" void _s801EA50C_2();
extern "C" void _s801EA50C_3();
extern "C" void _s801EA50C_4();
extern "C" void _s801EA50C_5();
extern "C" void _s801EA50C_6();
extern "C" void _s801EA50C_7();
extern "C" void _s801EA50C_8();
extern "C" void f_801EA50C() {}
