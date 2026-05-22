// 0x80382BC0 DoUnmount (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); addi 29,4,0; stw 28,0x10(1); addi 28,3,0; mulli 5,28,272; lis 3,-32688; addi 0,3,-24000; add 31,0,5; bl _s80382BC0_0; lwz 0,0x0(31); addi 30,3,0; cmpwi 0,0; beq 0f; addi 3,28,0; li 4,0; bl _s80382BC0_1; mr 3,28; bl _s80382BC0_2; addi 3,31,224; bl _s80382BC0_3; li 0,0; stw 0,0x0(31); stw 29,0x4(31); stw 0,0x24(31); 0:; mr 3,30; bl _s80382BC0_4; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); lwz 28,0x10(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80382BC0_0();
extern "C" void _s80382BC0_1();
extern "C" void _s80382BC0_2();
extern "C" void _s80382BC0_3();
extern "C" void _s80382BC0_4();
extern "C" void f_80382BC0() {}
