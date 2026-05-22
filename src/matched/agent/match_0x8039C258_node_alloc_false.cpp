// 0x8039C258 __node_alloc<false, (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); addi 3,3,7; li 0,20; rlwinm 31,3,0,0,28; stw 0,0x8(1); mr 3,31; addi 4,1,8; bl _s8039C258_0; lwz 11,0x8(1); cmpwi 11,1; beq 1f; addi 0,31,-1; lis 9,-32698; add 10,3,31; rlwinm 0,0,31,1,29; addi 9,9,-22352; cmpwi 11,2; stwx 10,9,0; mr 11,10; li 8,1; add 10,11,31; bne 0f; li 0,0; stwx 0,3,31; b 1f; 0:; stw 10,0x0(11); addi 8,8,1; mr 11,10; lwz 9,0x8(1); add 10,11,31; addi 9,9,-1; cmpw 9,8; bne 0b; li 0,0; stw 0,0x0(11); 1:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void _s8039C258_0();
extern "C" void f_8039C258() {}
