// 0x803805CC __CARDPutControlBlock (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); addi 31,4,0; stw 30,0x10(1); addi 30,3,0; bl _s803805CC_0; lwz 0,0x0(30); cmpwi 0,0; beq 0f; stw 31,0x4(30); b 1f; 0:; lwz 0,0x4(30); cmpwi 0,-1; bne 1f; stw 31,0x4(30); 1:; bl _s803805CC_1; mr 3,31; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s803805CC_0();
extern "C" void _s803805CC_1();
extern "C" void f_803805CC() {}
