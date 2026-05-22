// 0x80325E6C EResourceManager::BinarySearch(unsigned (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 10,3; mr. 5,5; beq 3f; addi 5,5,-1; li 3,0; 0:; cmpw 3,5; bge 2f; add 0,3,5; srawi 11,0,1; rlwinm 9,11,2,0,29; lwzx 0,9,4; cmplw 0,10; bge 1f; addi 3,11,1; b 0b; 1:; mr 5,11; b 0b; 2:; rlwinm 9,3,2,0,29; lwzx 0,9,4; cmpw 0,10; beqlr; li 3,-1; blr; 3:; li 3,-1"
extern "C" int f_80325E6C() {}
