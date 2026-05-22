// 0x80252164 __OSLockSramEx (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-32694; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); addi 31,3,-24704; bl _s80252164_0; lwz 0,0x48(31); addi 4,31,72; cmpwi 0,0; beq 0f; bl _s80252164_1; li 3,0; b 1f; 0:; stw 3,0x44(31); li 0,1; addi 3,31,20; stw 0,0x0(4); 1:; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s80252164_0();
extern "C" void _s80252164_1();
extern "C" void f_80252164() {}
