// 0x80250944 OnReset (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; cmpwi 3,0; stw 0,0x4(1); stwu 1,-8(1); beq 0f; lis 3,-13312; li 0,255; sth 0,0x4010(3); lis 3,-4096; bl _s80250944_0; 0:; li 3,1; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80250944_0();
extern "C" void f_80250944() {}
