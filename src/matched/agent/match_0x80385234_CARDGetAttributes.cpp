// 0x80385234 CARDGetAttributes (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-96(1); stw 31,0x5c(1); addi 31,5,0; addi 5,1,20; bl _s80385234_0; cmpwi 3,0; bne 0f; lbz 0,0x48(1); stb 0,0x0(31); 0:; lwz 0,0x64(1); lwz 31,0x5c(1); addi 1,1,96; mtspr 8,0"
extern "C" void _s80385234_0();
extern "C" void f_80385234() {}
