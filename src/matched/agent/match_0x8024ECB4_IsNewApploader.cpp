// 0x8024ECB4 IsNewApploader (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); lis 4,-32700; addi 4,4,-18712; li 5,10; bl _s8024ECB4_0; cmpwi 3,0; ble 0f; li 3,1; b 1f; 0:; li 3,0; 1:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8024ECB4_0();
extern "C" void f_8024ECB4() {}
