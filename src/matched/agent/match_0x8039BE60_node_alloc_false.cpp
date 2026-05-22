// 0x8039BE60 __node_alloc<false, (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); addi 4,4,-1; lis 9,-32698; rlwinm 4,4,31,1,29; addi 9,9,-22352; lwzx 0,4,9; stw 0,0x0(3); stwx 3,4,9; addi 1,1,16"
extern "C" void f_8039BE60() {}
