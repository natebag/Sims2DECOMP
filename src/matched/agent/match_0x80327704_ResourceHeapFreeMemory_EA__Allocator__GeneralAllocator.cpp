// 0x80327704 ResourceHeapFreeMemory(EA::Allocator::GeneralAllocator (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,-22652(13); lwz 9,0x0(3); lha 0,0xe0(9); lwz 9,0xe4(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; li 3,0; beq 0f; lwz 3,-26392(13); lwz 9,0x0(3); lha 0,0x40(9); lwz 9,0x44(9); add 3,3,0; mtspr 8,9; blrl; li 3,1; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_80327704() {}
