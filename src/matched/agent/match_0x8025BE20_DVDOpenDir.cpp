// 0x8025BE20 DVDOpenDir (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-152(1); stw 31,0x94(1); addi 31,4,0; stw 30,0x90(1); addi 30,3,0; bl _s8025BE20_0; cmpwi 3,0; bge 0f; lwz 3,-23496(13); addi 4,1,16; li 5,128; bl _s8025BE20_1; lis 3,-32700; crxor 6,6,6; addi 3,3,-15188; addi 4,30,0; addi 5,1,16; bl _s8025BE20_2; li 3,0; b 4f; 0:; mulli 5,3,12; lwz 4,-23508(13); lwzx 0,4,5; rlwinm. 0,0,0,0,7; bne 1f; li 0,0; b 2f; 1:; li 0,1; 2:; cmpwi 0,0; bne 3f; li 3,0; b 4f; 3:; stw 3,0x0(31); addi 0,3,1; li 3,1; stw 0,0x4(31); lwz 0,-23508(13); add 4,0,5; lwz 0,0x8(4); stw 0,0x8(31); 4:; lwz 0,0x9c(1); lwz 31,0x94(1); lwz 30,0x90(1); addi 1,1,152; mtspr 8,0"
extern "C" void _s8025BE20_0();
extern "C" void _s8025BE20_1();
extern "C" void _s8025BE20_2();
extern "C" void f_8025BE20() {}
