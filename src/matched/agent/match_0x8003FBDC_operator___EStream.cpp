// 0x8003FBDC operator<<(EStream (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; lwz 0,-24988(13); mr 9,3; stw 0,0x0(9)"
extern "C" void f_8003FBDC() {}
