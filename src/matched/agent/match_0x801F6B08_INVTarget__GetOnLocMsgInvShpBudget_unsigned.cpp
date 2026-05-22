// 0x801F6B08 INVTarget::GetOnLocMsgInvShpBudget(unsigned (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-544(1); mfspr 0,8; stmw 28,0x210(1); stw 0,0x224(1); mr 31,3; mr. 28,4; beq 2f; addi 30,1,8; bl _s801F6B08_0; mr 29,3; addi 4,30,8; li 5,256; mr 3,30; bl _s801F6B08_1; mr 4,30; li 5,1; mr 3,29; bl _s801F6B08_2; mr 3,30; bl _s801F6B08_3; mr 4,3; mr 3,28; bl _s801F6B08_4; lwz 0,0x84(31); cmpwi 0,0; bne 0f; lis 9,-32704; addi 3,9,-23456; b 1f; 0:; lis 9,-32704; addi 3,9,-23444; 1:; mr 4,28; bl _s801F6B08_5; 2:; lwz 0,0x224(1); mtspr 8,0; lmw 28,0x210(1); addi 1,1,544"
extern "C" void _s801F6B08_0();
extern "C" void _s801F6B08_1();
extern "C" void _s801F6B08_2();
extern "C" void _s801F6B08_3();
extern "C" void _s801F6B08_4();
extern "C" void _s801F6B08_5();
extern "C" void f_801F6B08() {}
