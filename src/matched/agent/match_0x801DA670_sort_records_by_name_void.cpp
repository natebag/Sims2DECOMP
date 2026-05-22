// 0x801DA670 sort_records_by_name(void (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; cmpw 31,29; li 3,0; beq 0f; addi 3,31,12; bl _s801DA670_0; mr 30,3; addi 3,29,12; bl _s801DA670_1; mr 4,3; mr 3,30; bl _s801DA670_2; mr. 3,3; bne 0f; addi 3,31,16; bl _s801DA670_3; mr 30,3; addi 3,29,16; bl _s801DA670_4; mr 4,3; mr 3,30; bl _s801DA670_5; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801DA670_0();
extern "C" void _s801DA670_1();
extern "C" void _s801DA670_2();
extern "C" void _s801DA670_3();
extern "C" void _s801DA670_4();
extern "C" void _s801DA670_5();
extern "C" void f_801DA670() {}
