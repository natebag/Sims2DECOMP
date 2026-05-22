// 0x801A6188 CRDTarget::HidePhoto(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 0,0x24(1); addi 3,1,8; bl _s801A6188_0; lis 4,-32705; addi 3,1,8; addi 4,4,-7852; li 5,0; li 6,0; bl _s801A6188_1; addi 3,1,8; li 4,2; bl _s801A6188_2; lwz 0,0x24(1); mtspr 8,0; addi 1,1,32"
extern "C" void _s801A6188_0();
extern "C" void _s801A6188_1();
extern "C" void _s801A6188_2();
extern "C" void f_801A6188() {}
