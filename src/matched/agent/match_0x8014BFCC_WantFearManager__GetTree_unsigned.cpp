// 0x8014BFCC WantFearManager::GetTree(unsigned (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(3); lwz 9,0x8(9); cmpwi 9,0; bne 0f; li 3,0; blr; 0:; addi 10,9,-1; lwz 6,0xc(3); rlwinm 0,10,1,31,31; li 8,0; add 0,10,0; cmpwi 10,0; srawi 11,0,1; ble 4f; mr 7,6; 1:; rlwinm 9,11,2,0,29; lwzx 3,9,7; lhz 0,0x0(3); cmplw 4,0; bge 2f; addi 10,11,-1; b 3f; 2:; cmplw 4,0; blelr; addi 8,11,1; 3:; add 9,8,10; cmpw 10,8; rlwinm 0,9,1,31,31; add 9,9,0; srawi 11,9,1; bgt 1b; 4:; rlwinm 9,11,2,0,29; lwzx 3,9,6; lhz 0,0x0(3); cmpw 4,0; beqlr; li 3,0"
extern "C" int f_8014BFCC() {}
