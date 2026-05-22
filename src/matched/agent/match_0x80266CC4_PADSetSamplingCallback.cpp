// 0x80266CC4 PADSetSamplingCallback (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; cmplwi 3,0; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); lwz 31,-23148(13); stw 3,-23148(13); beq 0f; lis 3,-32730; addi 3,3,27748; bl _s80266CC4_0; b 1f; 0:; lis 3,-32730; addi 3,3,27748; bl _s80266CC4_1; 1:; mr 3,31; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80266CC4_0();
extern "C" void _s80266CC4_1();
extern "C" void f_80266CC4() {}
