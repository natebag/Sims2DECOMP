// 0x8024BE60 OSInitAlarm (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; li 3,8; stw 0,0x4(1); stwu 1,-8(1); bl _s8024BE60_0; lis 4,-32731; addi 4,4,-14920; cmplw 3,4; beq 0f; li 0,0; addi 3,13,-23688; stw 0,0x4(3); li 3,8; stw 0,-23688(13); bl _s8024BE60_1; lis 3,-32700; addi 3,3,-21176; bl _s8024BE60_2; 0:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8024BE60_0();
extern "C" void _s8024BE60_1();
extern "C" void _s8024BE60_2();
extern "C" void f_8024BE60() {}
