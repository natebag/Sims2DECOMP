// 0x80159B5C ObjectDataBehaviorConstants::~ObjectDataBehaviorConstants(void) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; lis 9,-32698; lwz 3,0x14(30); addi 9,9,22352; mr 29,4; stw 9,0x0(30); cmpwi 3,0; beq 0f; bl _s80159B5C_0; li 0,0; stw 0,0x14(30); 0:; lwz 9,0x10(30); cmpwi 9,0; beq 3f; lwz 0,-8(9); rlwinm 0,0,2,0,29; add 31,9,0; cmpw 9,31; beq 2f; 1:; addi 31,31,-4; li 4,0; mr 3,31; bl _s80159B5C_1; lwz 0,0x10(30); cmpw 0,31; bne 1b; 2:; lwz 3,0x10(30); addi 3,3,-8; bl _s80159B5C_2; li 0,0; stw 0,0x10(30); 3:; andi. 0,29,1; beq 4f; mr 3,30; bl _s80159B5C_3; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80159B5C_0();
extern "C" void _s80159B5C_1();
extern "C" void _s80159B5C_2();
extern "C" void _s80159B5C_3();
extern "C" void f_80159B5C() {}
