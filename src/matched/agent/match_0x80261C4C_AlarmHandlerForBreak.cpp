// 0x80261C4C AlarmHandlerForBreak (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 4,-13312; stw 0,0x4(1); addi 3,4,24576; stwu 1,-8(1); lwz 0,-23356(13); lwz 3,0x18(3); cmplw 3,0; bge 0f; lwz 3,0x6000(4); li 0,1; ori 3,3,65; stw 3,0x6000(4); stw 0,-23328(13); b 1f; 0:; lis 3,-32768; lwz 0,0xf8(3); lis 3,4194; addi 3,3,19923; rlwinm 0,0,30,2,31; mulhwu 0,3,0; rlwinm 0,0,26,6,31; mulli 4,0,20; li 3,0; bl _s80261C4C_0; 1:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80261C4C_0();
extern "C" void f_80261C4C() {}
