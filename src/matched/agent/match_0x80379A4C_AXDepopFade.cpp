// 0x80379A4C __AXDepopFade (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 6,26214; lwz 7,0x0(3); addi 0,6,26215; mulhw 0,0,7; srawi 0,0,6; rlwinm 6,0,1,31,31; add. 0,0,6; beq 2f; mr 6,0; cmpwi 6,20; ble 0f; li 6,20; 0:; cmpwi 6,-20; bge 1f; li 6,-20; 1:; stw 7,0x0(4); neg 0,6; mulli 6,6,160; lwz 4,0x0(3); subf 4,6,4; stw 4,0x0(3); extsh 0,0; sth 0,0x0(5); blr; 2:; li 0,0; stw 0,0x0(3); stw 0,0x0(4); sth 0,0x0(5)"
extern "C" void f_80379A4C() {}
