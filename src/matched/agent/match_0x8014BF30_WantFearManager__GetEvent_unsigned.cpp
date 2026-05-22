// 0x8014BF30 WantFearManager::GetEvent(unsigned (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 6,3; li 7,0; lwz 11,0x4(6); lwz 9,0x4(11); addi 10,9,-1; rlwinm 0,10,1,31,31; cmpwi 10,0; add 0,10,0; srawi 11,0,1; ble 3f; lwz 8,0x8(6); 0:; mulli 9,11,36; lhzx 0,9,8; add 3,9,8; cmplw 4,0; bge 1f; addi 10,11,-1; b 2f; 1:; cmplw 4,0; blelr; addi 7,11,1; 2:; add 9,7,10; cmpw 10,7; rlwinm 0,9,1,31,31; add 9,9,0; srawi 11,9,1; bgt 0b; 3:; mulli 9,11,36; lwz 3,0x8(6); lhzx 0,9,3; add 3,9,3; cmpw 4,0; beqlr; li 3,0"
extern "C" int f_8014BF30() {}
