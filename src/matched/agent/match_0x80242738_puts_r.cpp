// 0x80242738 _puts_r (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 29,0x2c(1); stw 0,0x3c(1); mr 29,4; mr 30,3; mr 3,29; bl _s80242738_0; mr 7,3; lis 9,-32704; lwz 3,0x8(30); addi 9,9,-676; addi 8,7,1; li 0,1; addi 11,1,24; li 10,2; stw 29,0x18(1); addi 4,1,8; stw 9,0x20(1); stw 0,0x24(1); stw 8,0x10(1); stw 11,0x8(1); stw 10,0xc(1); stw 7,0x1c(1); bl _s80242738_1; cmpwi 3,0; li 3,10; beq 0f; li 3,-1; 0:; lwz 0,0x3c(1); mtspr 8,0; lmw 29,0x2c(1); addi 1,1,56"
extern "C" void _s80242738_0();
extern "C" void _s80242738_1();
extern "C" void f_80242738() {}
