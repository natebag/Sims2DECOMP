// 0x80245918 _vfwrite (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 29,3; mr 27,4; mr 31,5; cmpwi 6,1; bne 1f; lis 30,-32694; lwz 5,-27976(13); addi 4,30,-26044; bl _s80245918_0; addi 30,30,-26044; li 0,0; stw 0,-27976(13); stw 30,-27972(13); b 5f; 0:; li 3,0; b 5f; 1:; li 30,0; cmplw 30,31; bge 4f; lis 28,-32694; li 25,0; addi 26,28,-26044; 2:; lbzx 0,27,30; lwz 9,-27972(13); stb 0,0x0(9); lwz 11,-27972(13); lwz 9,-27976(13); addi 11,11,1; addi 5,9,1; stw 11,-27972(13); stw 5,-27976(13); cmpwi 5,127; ble 3f; mr 3,29; addi 4,28,-26044; bl _s80245918_1; cmpwi 3,0; stw 26,-27972(13); stw 25,-27976(13); beq 0b; 3:; addi 30,30,1; cmplw 30,31; blt 2b; 4:; mr 3,30; 5:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s80245918_0();
extern "C" void _s80245918_1();
extern "C" void f_80245918() {}
