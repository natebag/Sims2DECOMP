// 0x8022FAF4 ELightGrid::Flush(void) (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; li 9,3968; addi 10,29,27972; li 4,-1; li 5,-1; 0:; addi 6,9,-1; li 11,0; addi 7,10,36; addi 8,10,4; 1:; rlwinm 9,11,3,0,28; stbx 4,10,11; addi 0,11,1; add 9,9,8; li 11,4; addi 9,9,6; mtspr 9,11; 2:; sth 5,0x0(9); addi 9,9,-2; bdnz 2b; mr 11,0; cmpwi 11,3; ble 1b; mr 9,6; mr 10,7; cmpwi 9,-1; bne 0b; addi 31,29,24612; li 30,40; 3:; mr 3,31; bl _s8022FAF4_0; addi 31,31,84; addic. 30,30,-1; bne 3b; li 9,256; li 0,1; stw 30,0xc(29); stw 9,0x18(29); stw 0,0x0(29); stw 30,0x6020(29); stw 30,0x14(29); stw 30,0x10(29); stw 9,0x1c(29); stw 30,0x4(29); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8022FAF4_0();
extern "C" void f_8022FAF4() {}
