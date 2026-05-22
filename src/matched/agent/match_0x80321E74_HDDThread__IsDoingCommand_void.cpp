// 0x80321E74 HDDThread::IsDoingCommand(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 0,0x5c4(3); li 31,0; cmpwi 0,0; bne 0f; lwz 0,0x5c0(3); cmpwi 0,0; bne 0f; lwz 0,0x5c8(3); cmpwi 0,0; bne 0f; lwz 0,0x5cc(3); cmpwi 0,0; bne 0f; bl _s80321E74_0; cmpwi 3,0; beq 1f; 0:; li 31,1; 1:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80321E74_0();
extern "C" void f_80321E74() {}
