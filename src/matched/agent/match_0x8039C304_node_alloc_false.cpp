// 0x8039C304 __node_alloc<false, (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); mr 10,3; lis 9,-32698; addi 0,10,-1; addi 9,9,-22352; rlwinm 11,0,31,1,29; lwzx 3,11,9; cmpwi 3,0; beq 0f; lwz 0,0x0(3); stwx 0,11,9; b 1f; 0:; mr 3,10; bl _s8039C304_0; 1:; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s8039C304_0();
extern "C" void f_8039C304() {}
