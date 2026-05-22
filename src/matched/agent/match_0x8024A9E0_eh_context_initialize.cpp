// 0x8024A9E0 eh_context_initialize (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 3,-32731; lis 9,-32700; addi 3,3,-21996; mtspr 8,3; stw 3,-21684(9); blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_8024A9E0() {}
