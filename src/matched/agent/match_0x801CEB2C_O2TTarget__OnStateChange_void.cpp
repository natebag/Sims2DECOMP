// 0x801CEB2C O2TTarget::OnStateChange(void) (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x88(31); cmpwi 0,1; bne 0f; bl _s801CEB2C_0; cmpwi 3,0; beq 2f; lwz 0,0x258(31); cmpwi 0,0; beq 1f; b 2f; 0:; cmpwi 0,2; bne 3f; mr 3,31; bl _s801CEB2C_1; cmpwi 3,0; beq 2f; lwz 0,0x258(31); cmpwi 0,0; bne 2f; 1:; mr 3,31; bl _s801CEB2C_2; b 4f; 2:; lis 3,-32705; li 4,0; addi 3,3,15992; li 5,0; li 6,0; li 7,0; bl _s801CEB2C_3; b 4f; 3:; lis 3,-32705; li 4,0; addi 3,3,15992; li 5,0; li 6,0; li 7,0; bl _s801CEB2C_4; 4:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801CEB2C_0();
extern "C" void _s801CEB2C_1();
extern "C" void _s801CEB2C_2();
extern "C" void _s801CEB2C_3();
extern "C" void _s801CEB2C_4();
extern "C" void f_801CEB2C() {}
