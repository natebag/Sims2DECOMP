// 0x802CE39C G2DTarget::Update(void) (572 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lmw 29,0xc(1); mtcrf 8,12; addi 1,1,24; blr; lwz 3,0x8(3); lis 9,-32700; addi 9,9,-4812; cmpw 3,9; beq 4f; cmpwi 7,5,0; 0:; lwz 0,0x18(3); cmpw 4,0; bne 1f; beqlr cr7; lwz 0,0x1c(3); stw 0,0x0(5); blr; 1:; cmplw 4,0; bge 2f; lwz 3,0x0(3); b 3f; 2:; lwz 3,0x4(3); 3:; cmpw 3,9; bne 0b; 4:; li 3,0; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; mr 30,5; li 5,0; bl _s802CE39C_0; mr. 3,3; beq 7f; 5:; lwz 9,0xc(3); cmpwi 9,0; beq 6f; lwz 0,0x18(9); cmpw 0,31; bne 6f; mr 3,9; b 5b; 6:; cmpwi 30,0; beq 7f; lwz 0,0x1c(3); stw 0,0x0(30); 7:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; lwz 3,0x10(4); cmpwi 3,0; beq 8f; lwz 9,0x18(4); lwz 0,0x18(3); cmpw 0,9; bne 8f; cmpwi 5,0; beqlr; lwz 0,0x1c(3); stw 0,0x0(5); blr; 8:; li 3,0; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 30,0x4(31); cmpwi 30,0; beq 10f; 9:; mr 3,30; lwz 30,0xc(30); bl _s802CE39C_1; mr. 30,30; bne 9b; 10:; lis 9,-32700; li 0,0; addi 9,9,-4812; stw 0,0x0(31); stw 9,0x8(31); stw 0,0x4(31); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; lwz 31,0x0(29); b 12f; 11:; lwz 30,0x1c(31); bl _s802CE39C_2; mr 4,30; bl _s802CE39C_3; lwz 31,0x10(31); 12:; li 0,1; cmpwi 31,0; bne 13f; li 0,0; 13:; cmpwi 0,0; bne 11b; mr 3,29; bl _s802CE39C_4; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24; blr; lwz 3,0x0(3); li 9,0; cmpwi 3,0; beq 15f; 14:; lwz 3,0x10(3); addi 9,9,1; cmpwi 3,0; bne 14b; 15:; mr 3,9; blr; stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; bl _s802CE39C_5; mr 3,30; mr 4,29; li 5,1; bl _s802CE39C_6; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802CE39C_0();
extern "C" void _s802CE39C_1();
extern "C" void _s802CE39C_2();
extern "C" void _s802CE39C_3();
extern "C" void _s802CE39C_4();
extern "C" void _s802CE39C_5();
extern "C" void _s802CE39C_6();
extern "C" void f_802CE39C() {}
