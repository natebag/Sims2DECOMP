// 0x801A4A04 CRDTarget::SetVariable(char (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; mr 30,3; lbz 3,0x0(31); extsb 3,3; bl _s801A4A04_0; cmpwi 3,0; beq 0f; addi 31,31,1; 0:; lis 3,-32705; mr 4,31; addi 3,3,-7976; bl _s801A4A04_1; mr. 3,3; bne 1f; stw 3,0x8c(30); mr 3,30; bl _s801A4A04_2; b 4f; 1:; lis 3,-32705; mr 4,31; addi 3,3,-7956; bl _s801A4A04_3; mr. 3,3; bne 2f; stw 3,0x8c(30); bl _s801A4A04_4; mr. 3,3; beq 4f; bl _s801A4A04_5; b 4f; 2:; lis 3,-32705; mr 4,31; addi 3,3,-7936; bl _s801A4A04_6; cmpwi 3,0; bne 3f; mr 3,30; bl _s801A4A04_7; b 4f; 3:; lis 3,-32705; mr 4,31; addi 3,3,-7920; bl _s801A4A04_8; cmpwi 3,0; bne 4f; mr 3,30; bl _s801A4A04_9; 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801A4A04_0();
extern "C" void _s801A4A04_1();
extern "C" void _s801A4A04_2();
extern "C" void _s801A4A04_3();
extern "C" void _s801A4A04_4();
extern "C" void _s801A4A04_5();
extern "C" void _s801A4A04_6();
extern "C" void _s801A4A04_7();
extern "C" void _s801A4A04_8();
extern "C" void _s801A4A04_9();
extern "C" void f_801A4A04() {}
