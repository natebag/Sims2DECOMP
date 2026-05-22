// 0x8024E890 IsStreamEnabled (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); bl _s8024E890_0; lbz 0,0x8(3); cmplwi 0,0; beq 0f; li 3,1; b 1f; 0:; li 3,0; 1:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8024E890_0();
extern "C" void f_8024E890() {}
