// 0x80181244 UIButtonImages::UIButtonImages(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 11,-32698; mr 10,3; addi 11,11,26512; lis 9,-32706; stw 11,0xb0(10); li 0,0; li 11,14; lfs f0,0x3d6c(9); mtspr 9,11; addi 9,10,112; 0:; stw 0,-56(9); stfs f0,0x0(9); addi 9,9,4; bdnz 0b; lis 9,-32706; lis 11,-32706; lfs f13,0x3d70(9); li 0,0; lfs f0,0x3d74(11); li 9,3; stw 0,0xa8(10); mr 3,10; stw 9,0xac(10); stfs f13,0x74(10); stfs f0,0x84(10)"
extern "C" void f_80181244() {}
