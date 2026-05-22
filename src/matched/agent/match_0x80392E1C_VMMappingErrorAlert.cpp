// 0x80392E1C __VMMappingErrorAlert (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-1040(1); mfspr 0,8; lis 4,-32698; mr 5,3; stw 0,0x414(1); addi 4,4,-22520; addi 3,1,8; crxor 6,6,6; bl _s80392E1C_0; bl _s80392E1C_1; lwz 0,0x414(1); mtspr 8,0; addi 1,1,1040"
extern "C" void _s80392E1C_0();
extern "C" void _s80392E1C_1();
extern "C" void f_80392E1C() {}
