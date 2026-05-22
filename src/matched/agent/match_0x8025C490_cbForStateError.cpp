// 0x8025C490 cbForStateError (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; cmplwi 3,16; stw 0,0x4(1); li 0,-1; stwu 1,-24(1); stw 31,0x14(1); lwz 4,-23480(13); stw 0,0xc(4); bne 0f; bl _s8025C490_0; b 3f; 0:; bl _s8025C490_1; lis 3,-32694; lwz 31,-23480(13); addi 0,3,-17184; li 3,1; stw 0,-23480(13); stw 3,-23456(13); lwz 12,0x28(31); cmplwi 12,0; beq 1f; mtspr 8,12; addi 4,31,0; li 3,-1; blrl; 1:; lwz 0,-23448(13); cmplwi 0,0; beq 2f; lwz 12,-23444(13); li 0,0; stw 0,-23448(13); cmplwi 12,0; beq 2f; mtspr 8,12; addi 4,31,0; li 3,0; blrl; 2:; bl _s8025C490_2; 3:; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8025C490_0();
extern "C" void _s8025C490_1();
extern "C" void _s8025C490_2();
extern "C" void f_8025C490() {}
