// 0x801D4A2C PCTTarget::on_tab_changed(void) (368 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; lwz 9,0xb0(31); lwz 0,0xac(31); cmplw 9,0; li 3,0; bgt 12f; lwz 3,0xbc(31); cmpwi 3,0; beq 0f; bl _s801D4A2C_0; 0:; lwz 9,0xb0(31); li 0,0; stw 0,0xc0(31); mulli 9,9,20; stw 0,0xbc(31); lwz 11,0xa8(31); lwzx 0,11,9; cmpwi 0,2; beq 3f; bgt 1f; cmpwi 0,0; beq 6f; cmpwi 0,1; beq 2f; b 6f; 1:; cmpwi 0,3; beq 4f; cmpwi 0,4; beq 5f; b 6f; 2:; mr 3,31; bl _s801D4A2C_1; b 6f; 3:; mr 3,31; bl _s801D4A2C_2; b 6f; 4:; mr 3,31; bl _s801D4A2C_3; b 6f; 5:; mr 3,31; bl _s801D4A2C_4; 6:; lwz 0,0xac(31); li 30,0; cmplw 30,0; bge 11f; lis 9,-32705; li 27,0; addi 28,9,30572; li 29,0; 7:; lwz 0,0xb0(31); cmpw 0,30; bne 8f; lwz 9,0xa8(31); add 9,29,9; lwz 5,0xc(9); b 9f; 8:; lwz 9,0xa8(31); add 9,27,9; lwz 5,0x8(9); 9:; lwz 0,0x0(31); lwz 4,0x0(28); cmpwi 0,0; beq 10f; lwz 3,0x1c(31); cmpwi 3,0; beq 10f; lwz 6,0x7c(31); li 7,0; bl _s801D4A2C_5; 10:; lwz 0,0xac(31); addi 30,30,1; addi 28,28,4; addi 27,27,20; cmplw 30,0; addi 29,29,20; blt 7b; 11:; li 30,0; mr 3,31; stw 30,0xb4(31); bl _s801D4A2C_6; stw 30,0xb8(31); mr 3,31; bl _s801D4A2C_7; 12:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s801D4A2C_0();
extern "C" void _s801D4A2C_1();
extern "C" void _s801D4A2C_2();
extern "C" void _s801D4A2C_3();
extern "C" void _s801D4A2C_4();
extern "C" void _s801D4A2C_5();
extern "C" void _s801D4A2C_6();
extern "C" void _s801D4A2C_7();
extern "C" void f_801D4A2C() {}
