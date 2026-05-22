// 0x8025C678 CheckCancel (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); lwz 0,-23448(13); cmplwi 0,0; beq 2f; lis 4,-32694; stw 3,-23440(13); li 0,0; lwz 31,-23480(13); addi 3,4,-17184; stw 0,-23448(13); li 0,10; stw 3,-23480(13); stw 0,0xc(31); lwz 12,0x28(31); cmplwi 12,0; beq 0f; mtspr 8,12; addi 4,31,0; li 3,-3; blrl; 0:; lwz 12,-23444(13); cmplwi 12,0; beq 1f; mtspr 8,12; addi 4,31,0; li 3,0; blrl; 1:; bl _s8025C678_0; li 3,1; b 3f; 2:; li 3,0; 3:; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8025C678_0();
extern "C" void f_8025C678() {}
