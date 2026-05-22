// 0x80327A9C EResourceMap::Search(unsigned (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x4(3); li 10,0; cmpw 10,11; bge 3f; lwz 8,0x0(3); 0:; add 0,10,11; srawi 3,0,1; rlwinm 9,3,3,0,28; lwzx 0,9,8; cmplw 4,0; ble 1f; addi 10,3,1; b 2f; 1:; bgelr; mr 11,3; 2:; cmpw 10,11; blt 0b; 3:; mr 3,10"
extern "C" int f_80327A9C() {}
