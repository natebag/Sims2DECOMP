// 0x80250F60 KillThreads (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); lis 3,-32768; lwz 3,0xdc(3); b 0f; 0:; b 1f; 1:; b 5f; 2:; lhz 0,0x2c8(3); lwz 31,0x2fc(3); cmpwi 0,4; beq 3f; bge 4f; cmpwi 0,1; beq 3f; b 4f; 3:; bl _s80250F60_0; 4:; mr 3,31; 5:; cmplwi 3,0; bne 2b; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s80250F60_0();
extern "C" void f_80250F60() {}
