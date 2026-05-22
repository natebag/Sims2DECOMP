// 0x80367738 CopyERAnimConstantArray(TArray<float, (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 31,4; mr 28,3; li 5,4; addi 3,1,8; mr 27,31; bl _s80367738_0; li 29,0; lwz 4,0x8(1); mr 3,28; li 5,0; addi 31,31,4; bl _s80367738_1; lwz 0,0x8(1); cmpw 29,0; bge 1f; li 30,0; 0:; lwz 3,0x0(28); mr 4,31; li 5,4; addi 29,29,1; add 3,3,30; addi 31,31,4; bl _s80367738_2; addi 30,30,4; lwz 0,0x8(1); cmpw 29,0; blt 0b; 1:; subf 3,27,31; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s80367738_0();
extern "C" void _s80367738_1();
extern "C" void _s80367738_2();
extern "C" void f_80367738() {}
