// 0x801A01C0 CASRoommateTarget::SetVariable(char (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lis 3,-32705; addi 3,3,-11500; bl _s801A01C0_0; cmpwi 3,0; bne 0f; lwz 9,0x84(31); lwz 0,0x18(9); cmpwi 0,0; beq 1f; mr 3,31; bl _s801A01C0_1; cmpwi 3,0; beq 1f; li 0,1; stw 0,0x8c(31); b 1f; 0:; lis 3,-32705; mr 4,30; addi 3,3,-11476; bl _s801A01C0_2; cmpwi 3,0; bne 1f; lwz 9,0x84(31); lwz 0,0x18(9); cmpwi 0,0; beq 1f; stw 3,0x8c(31); 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801A01C0_0();
extern "C" void _s801A01C0_1();
extern "C" void _s801A01C0_2();
extern "C" void f_801A01C0() {}
