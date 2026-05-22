// 0x8039A9D4 TArray<ENLatticePoints, (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 0,0x4(3); lwz 0,0x4(3); rlwinm. 0,0,0,31,31; beq 0f; lwz 5,0x0(3); lbz 4,0x0(5); addi 0,5,1; stw 0,0x0(3); rlwinm 0,4,28,0,3; srawi 5,0,28; b 1f; 0:; lwz 4,0x0(3); lbz 0,0x0(4); rlwinm 0,0,24,0,3; srawi 5,0,28; 1:; lwz 4,0x4(3); addi 0,4,1; stw 0,0x4(3); mr 3,5"
extern "C" void f_8039A9D4() {}
