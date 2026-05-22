// 0x80251408 __OSResetSWInterruptHandler (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); stw 30,0x20(1); stw 29,0x1c(1); bl _s80251408_0; lis 5,-32768; stw 4,-23588(13); lwz 0,0xf8(5); lis 4,17180; addi 4,4,-8573; stw 3,-23592(13); rlwinm 0,0,30,2,31; mulhwu 0,4,0; rlwinm 0,0,17,15,31; mulli 0,0,100; rlwinm 29,0,29,3,31; li 30,0; lis 31,-13312; 0:; bl _s80251408_1; lwz 6,-23588(13); xoris 5,30,32768; lwz 0,-23592(13); subfc 4,6,4; subfe 0,0,3; xoris 3,0,32768; subfc 0,29,4; subfe 5,5,3; subfe 5,3,3; neg. 5,5; beq 1f; lwz 0,0x3000(31); rlwinm. 0,0,0,15,15; beq 0b; 1:; lis 3,-13312; lwz 0,0x3000(3); rlwinm. 0,0,0,15,15; bne 2f; li 0,1; stw 0,-23612(13); li 3,512; stw 0,-23608(13); bl _s80251408_2; lwz 12,-23616(13); cmplwi 12,0; beq 2f; li 0,0; mtspr 8,12; stw 0,-23616(13); blrl; 2:; li 0,2; lis 3,-13312; stw 0,0x3000(3); lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s80251408_0();
extern "C" void _s80251408_1();
extern "C" void _s80251408_2();
extern "C" void f_80251408() {}
