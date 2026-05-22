// 0x801A2D78 ACTTarget::CancelModeEnabled(bool) (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr. 30,4; mr 31,3; mcrf cr7,cr0; beq cr7,0f; lwz 0,0xe4(31); cmpwi 0,0; beq 1f; 0:; lwz 0,0xd8(31); cmpwi 0,0; bne 2f; 1:; li 3,0; b 6f; 2:; stw 30,0x644(31); bne cr7,3f; mr 3,31; bl _s801A2D78_0; b 5f; 3:; addi 3,1,8; bl _s801A2D78_1; lis 4,-32705; lwz 6,0xdc(31); addi 4,4,-8784; addi 3,1,8; li 5,1; bl _s801A2D78_2; lwz 9,0xe4(31); cmpwi 9,0; beq 4f; li 0,0; stw 9,0x648(31); stw 0,0x64c(31); mr 3,31; bl _s801A2D78_3; 4:; addi 3,1,8; li 4,2; bl _s801A2D78_4; 5:; mr 3,30; 6:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"
extern "C" void _s801A2D78_0();
extern "C" void _s801A2D78_1();
extern "C" void _s801A2D78_2();
extern "C" void _s801A2D78_3();
extern "C" void _s801A2D78_4();
extern "C" void f_801A2D78() {}
