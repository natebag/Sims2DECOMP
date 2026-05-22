// 0x80236E88 ERLevel::UpdateLightsIntensityScale(int, (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 4,4; bltlr; addis 9,3,3; lwz 0,-23884(9); cmpw 4,0; bgtlr; mulli 9,4,84; addi 11,3,56; add 9,3,9; addi 3,9,24636; lwz 7,0x4c(3); lwz 0,0x50(3); cmpw 7,0; bgelr; rlwinm 9,7,5,0,26; li 4,1; addi 9,9,28; add 6,9,11; 0:; lwz 11,0x0(6); addi 7,7,1; lwz 10,0x0(5); addi 6,6,32; lwz 0,0x8(5); addi 9,11,156; lwz 8,0x4(5); stw 10,0x9c(11); stw 0,0x8(9); stw 8,0x4(9); stw 4,0xa8(11); lwz 0,0x50(3); cmpw 7,0; blt 0b"
extern "C" void f_80236E88() {}
