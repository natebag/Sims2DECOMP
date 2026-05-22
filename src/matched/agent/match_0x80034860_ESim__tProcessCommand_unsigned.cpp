// 0x80034860 ESim::tProcessCommand(unsigned (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr. 4,4; beq 0f; cmpwi 4,1; beq 1f; b 2f; 0:; bl _s80034860_0; b 2f; 1:; bl _s80034860_1; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80034860_0();
extern "C" void _s80034860_1();
extern "C" void f_80034860() {}
