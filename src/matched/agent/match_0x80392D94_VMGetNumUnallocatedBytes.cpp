// 0x80392D94 VMGetNumUnallocatedBytes (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); bl _s80392D94_0; lwz 0,-21848(13); subf 3,0,3; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s80392D94_0();
extern "C" void f_80392D94() {}
