// 0x8035EF04 ERTQuantize4D::InitializeCube(void) (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 31,0x1c(1); stw 0,0x24(1); li 0,10; mr 31,3; stw 0,0x101c(31); li 11,40; li 0,-1; addi 8,1,8; 0:; addi 11,11,-1; rlwinm. 0,0,31,1,31; bne 0b; lwz 0,0x101c(31); li 10,0; cmplw 10,0; bgt 3f; addi 9,31,4144; 1:; stw 11,0x0(9); cmpwi 11,0; addi 9,9,4; beq 2f; addi 11,11,-1; 2:; lwz 0,0x101c(31); addi 10,10,1; cmplw 10,0; ble 1b; 3:; lis 9,-32702; mr 7,8; lfs f0,0x2e34(9); mr 3,31; li 4,0; li 5,0; stfs f0,0xc(8); li 6,0; stfs f0,0x8(8); stfs f0,0x4(8); stfs f0,0x8(1); bl _s8035EF04_0; mr. 3,3; beq 4f; lwz 9,0x1008(31); lis 0,14563; ori 0,0,36409; subf 9,9,3; mullw 9,9,0; rlwinm 11,9,29,16,31; b 5f; 4:; li 11,0; 5:; sth 11,0x1004(31); li 0,-1; stw 0,0x10(3); li 9,0; sth 11,0x18(3); stw 9,0x1024(31); lwz 0,0x24(1); mtspr 8,0; lwz 31,0x1c(1); addi 1,1,32"
extern "C" void _s8035EF04_0();
extern "C" void f_8035EF04() {}
