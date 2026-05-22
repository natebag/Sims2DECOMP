// 0x80261A94 DVDLowAudioBufferConfig (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; cmpwi 3,0; stw 0,0x4(1); li 0,0; stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 5,-23352(13); stw 0,-23360(13); beq 0f; lis 0,1; 0:; oris 0,0,58368; lis 3,-13312; or 0,4,0; addi 3,3,24576; stw 0,0x8(3); li 0,1; lis 4,-32768; stw 0,0x1c(3); lis 3,-32694; addi 31,3,-16848; lwz 0,0xf8(4); addi 3,31,0; rlwinm 0,0,30,2,31; mulli 30,0,10; bl _s80261A94_0; lis 3,-32730; addi 7,3,4036; addi 3,31,0; addi 6,30,0; li 5,0; bl _s80261A94_1; lwz 0,0x24(1); li 3,1; lwz 31,0x1c(1); lwz 30,0x18(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80261A94_0();
extern "C" void _s80261A94_1();
extern "C" void f_80261A94() {}
