// 0x801B7100 UIDialog::~UIDialog(void) (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; mr 31,3; addi 9,9,30832; mr 30,4; stw 9,0x84(31); lwz 3,0x3c(31); cmpwi 3,0; beq 0f; bl _s801B7100_0; li 0,0; stw 0,0x3c(31); 0:; lwz 3,0x44(31); cmpwi 3,0; beq 1f; bl _s801B7100_1; li 0,0; stw 0,0x44(31); 1:; addi 3,31,56; li 4,2; bl _s801B7100_2; addi 3,31,52; li 4,2; bl _s801B7100_3; addi 3,31,48; li 4,2; bl _s801B7100_4; addi 3,31,44; li 4,2; bl _s801B7100_5; addi 3,31,40; li 4,2; bl _s801B7100_6; andi. 0,30,1; beq 2f; mr 3,31; bl _s801B7100_7; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801B7100_0();
extern "C" void _s801B7100_1();
extern "C" void _s801B7100_2();
extern "C" void _s801B7100_3();
extern "C" void _s801B7100_4();
extern "C" void _s801B7100_5();
extern "C" void _s801B7100_6();
extern "C" void _s801B7100_7();
extern "C" void f_801B7100() {}
