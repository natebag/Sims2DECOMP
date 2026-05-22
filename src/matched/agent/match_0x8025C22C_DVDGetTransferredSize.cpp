// 0x8025C22C DVDGetTransferredSize (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0xc(3); cmpwi 0,2; beq 3f; bge 0f; cmpwi 0,1; bge 4f; cmpwi 0,-1; bge 2f; blr; 0:; cmpwi 0,10; bge 1f; cmpwi 0,8; bgelr; b 2f; 1:; cmpwi 0,12; bgelr; 2:; lwz 3,0x20(3); blr; 3:; li 3,0; blr; 4:; lis 4,-13312; lwz 0,0x1c(3); lwz 5,0x20(3); lwz 3,0x6018(4); subf 0,3,0; add 3,5,0"
extern "C" int f_8025C22C() {}
