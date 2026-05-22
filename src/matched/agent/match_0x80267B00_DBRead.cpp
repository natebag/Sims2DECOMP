// 0x80267B00 DBRead (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); addi 30,4,0; stw 29,0x14(1); addi 29,3,0; bl _s80267B00_0; lwz 0,-23048(13); addi 31,3,0; rlwinm. 0,0,0,15,15; beq 0f; li 3,4096; b 1f; 0:; li 3,0; 1:; addis 3,3,2; addi 0,30,3; addi 4,29,0; rlwinm 5,0,0,0,29; addi 3,3,-8192; bl _s80267B00_1; li 0,0; stw 0,-23044(13); mr 3,31; stb 0,-23036(13); bl _s80267B00_2; lwz 0,0x24(1); li 3,0; lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80267B00_0();
extern "C" void _s80267B00_1();
extern "C" void _s80267B00_2();
extern "C" void f_80267B00() {}
