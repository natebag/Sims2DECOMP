// 0x80382C5C CARDUnmount (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); addi 4,1,12; stw 30,0x18(1); stw 29,0x14(1); addi 29,3,0; bl _s80382C5C_0; cmpwi 3,0; bge 0f; b 2f; 0:; mulli 4,29,272; lis 3,-32688; addi 0,3,-24000; add 30,0,4; bl _s80382C5C_1; lwz 0,0x0(30); addi 31,3,0; cmpwi 0,0; beq 1f; addi 3,29,0; li 4,0; bl _s80382C5C_2; mr 3,29; bl _s80382C5C_3; addi 3,30,224; bl _s80382C5C_4; li 3,0; stw 3,0x0(30); li 0,-3; stw 0,0x4(30); stw 3,0x24(30); 1:; mr 3,31; bl _s80382C5C_5; li 3,0; 2:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80382C5C_0();
extern "C" void _s80382C5C_1();
extern "C" void _s80382C5C_2();
extern "C" void _s80382C5C_3();
extern "C" void _s80382C5C_4();
extern "C" void _s80382C5C_5();
extern "C" void f_80382C5C() {}
