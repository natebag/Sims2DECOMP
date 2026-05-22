// 0x8024A9B0 __get_eh_info (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32700; lwz 0,-21684(9); mtspr 8,0; blrl; addi 3,3,8; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_8024A9B0() {}
