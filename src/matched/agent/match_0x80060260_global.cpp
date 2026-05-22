// 0x80060260 global (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="bl _s80060260_0; b 0f; li 0,0; stb 0,0x5f8(31); 0:; li 0,1; stw 0,0x5fc(31); lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s80060260_0();
extern "C" void f_80060260() {}
