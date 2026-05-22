// 0x80327768 AudioHeapFreeMemory(EA::Allocator::GeneralAllocator (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; li 31,0; lis 29,-32692; 0:; addi 3,29,-14084; bl _s80327768_0; cmpwi 3,0; add 31,31,3; beq 1f; cmplw 31,30; blt 0b; 1:; cmpwi 31,0; li 3,1; bne 2f; li 3,0; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80327768_0();
extern "C" void f_80327768() {}
