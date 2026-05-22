// 0x80267B8C DBQueryData (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; li 3,0; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); lwz 0,-23044(13); stb 3,-23036(13); cmpwi 0,0; bne 1f; bl _s80267B8C_0; addi 31,3,0; addi 3,1,8; bl _s80267B8C_1; lwz 0,0x8(1); rlwinm. 0,0,0,31,31; beq 0f; addi 3,1,8; bl _s80267B8C_2; lwz 0,0x8(1); rlwinm 0,0,0,3,31; stw 0,0x8(1); lwz 4,0x8(1); rlwinm 3,4,0,3,7; addis 0,3,-7936; cmplwi 0,0; bne 0f; rlwinm 3,4,0,17,31; stw 4,-23048(13); li 0,1; stw 3,-23044(13); stb 0,-23036(13); 0:; mr 3,31; bl _s80267B8C_3; 1:; lwz 3,-23044(13); lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80267B8C_0();
extern "C" void _s80267B8C_1();
extern "C" void _s80267B8C_2();
extern "C" void _s80267B8C_3();
extern "C" void f_80267B8C() {}
