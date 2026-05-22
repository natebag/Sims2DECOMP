// 0x80161B7C global (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="andi. 0,4,1; addi 9,9,24424; stw 9,0x4(3); beq 0f; bl _s80161B7C_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stw 4,0x0(3)"
extern "C" void _s80161B7C_0();
extern "C" void f_80161B7C() {}
