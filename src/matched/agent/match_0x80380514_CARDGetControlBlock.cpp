// 0x80380514 __CARDGetControlBlock (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; mulli 6,3,272; stw 0,0x4(1); stwu 1,-32(1); lis 5,-32688; cmpwi 3,0; stw 31,0x1c(1); addi 0,5,-24000; stw 30,0x18(1); add 30,0,6; stw 29,0x14(1); addi 29,4,0; blt 0f; cmpwi 3,2; bge 0f; lwz 0,0x10c(30); cmplwi 0,0; bne 1f; 0:; li 3,-128; b 5f; 1:; bl _s80380514_0; lwz 0,0x0(30); cmpwi 0,0; bne 2f; li 31,-3; b 4f; 2:; lwz 0,0x4(30); cmpwi 0,-1; bne 3f; li 31,-1; b 4f; 3:; li 0,-1; stw 0,0x4(30); li 0,0; li 31,0; stw 0,0xd0(30); stw 30,0x0(29); 4:; bl _s80380514_1; mr 3,31; 5:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80380514_0();
extern "C" void _s80380514_1();
extern "C" void f_80380514() {}
