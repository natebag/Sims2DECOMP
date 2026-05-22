// 0x8019E64C TArray<int, (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8019E72C" lines="addi 3,30,16; bl _s8019E64C_0; extsh 4,3; addi 5,1,8; mr 3,31; bl _s8019E64C_1"
extern "C" void _s8019E64C_0();
extern "C" void _s8019E64C_1();
extern "C" void f_8019E72C();
extern "C" void f_8019E64C() {}
