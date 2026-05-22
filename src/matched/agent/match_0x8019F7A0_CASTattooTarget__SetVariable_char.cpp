// 0x8019F7A0 CASTattooTarget::SetVariable(char (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 3,-32705; addi 3,3,-11608; bl _s8019F7A0_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8019F7A0_0();
extern "C" void f_8019F7A0() {}
