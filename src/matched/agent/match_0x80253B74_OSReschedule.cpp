// 0x80253B74 __OSReschedule (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); lwz 0,-23580(13); cmpwi 0,0; beq 0f; li 3,0; bl _s80253B74_0; 0:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80253B74_0();
extern "C" void f_80253B74() {}
