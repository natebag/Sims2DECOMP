// 0x80393FF8 __THPDecompressYUV (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); lwz 6,-21552(13); stw 3,0x6b0(6); lwz 6,-21552(13); stw 4,0x6b4(6); lwz 4,-21552(13); stw 5,0x6b8(4); lwz 4,-21552(13); lhz 31,0x698(4); lhz 30,0x694(4); mfspr 4,917; mfspr 0,918; stw 4,-21564(13); stw 0,-21560(13); li 3,7; oris 3,3,7; mtspr 917,3; li 3,15620; oris 3,3,15620; mtspr 918,3; bl _s80393FF8_0; lwz 4,-21552(13); lhz 0,0x692(4); cmplwi 0,512; bne 2f; cmplwi 30,448; bne 2f; b 1f; 0:; bl _s80393FF8_1; addi 31,31,16; 1:; rlwinm 0,31,0,16,31; cmplw 0,30; blt 0b; b 7f; 2:; lwz 4,-21552(13); lhz 0,0x692(4); cmplwi 0,640; bne 6f; cmplwi 30,480; bne 6f; b 4f; 3:; bl _s80393FF8_2; addi 31,31,16; 4:; rlwinm 0,31,0,16,31; cmplw 0,30; blt 3b; b 7f; b 6f; 5:; bl _s80393FF8_3; addi 31,31,16; 6:; rlwinm 0,31,0,16,31; cmplw 0,30; blt 5b; 7:; lwz 4,-21564(13); lwz 0,-21560(13); mtspr 917,4; mtspr 918,0; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80393FF8_0();
extern "C" void _s80393FF8_1();
extern "C" void _s80393FF8_2();
extern "C" void _s80393FF8_3();
extern "C" void f_80393FF8() {}
