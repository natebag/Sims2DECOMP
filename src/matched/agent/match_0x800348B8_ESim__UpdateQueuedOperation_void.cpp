// 0x800348B8 ESim::UpdateQueuedOperation(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,-26824(13); bl _s800348B8_0; lwz 0,0x520(31); cmpwi 0,0; beq 0f; lwz 0,0x43c(31); cmpwi 0,0; bgt 0f; li 0,0; stw 0,0x520(31); 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800348B8_0();
extern "C" void f_800348B8() {}
