// 0x801C6B54 MMUTarget::GetLotListItemName(char (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,4; lis 3,-32705; addi 3,3,11436; li 5,9; li 31,0; bl _s801C6B54_0; cmpwi 3,0; bne 0f; addi 3,30,9; bl _s801C6B54_1; mr 31,3; 0:; addi 3,31,1; bl _s801C6B54_2; li 31,0; mr 5,3; lis 4,-32697; addi 4,4,24012; addi 3,1,8; crxor 6,6,6; bl _s801C6B54_3; lwz 9,0x8(1); cmpwi 9,0; beq 1f; lwz 31,0x0(9); 1:; mr 3,31; bl _s801C6B54_4; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s801C6B54_5; mr 30,3; mr 4,31; bl _s801C6B54_6; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s801C6B54_0();
extern "C" void _s801C6B54_1();
extern "C" void _s801C6B54_2();
extern "C" void _s801C6B54_3();
extern "C" void _s801C6B54_4();
extern "C" void _s801C6B54_5();
extern "C" void _s801C6B54_6();
extern "C" void f_801C6B54() {}
