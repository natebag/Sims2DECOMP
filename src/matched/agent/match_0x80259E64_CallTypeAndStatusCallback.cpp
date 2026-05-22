// 0x80259E64 CallTypeAndStatusCallback (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stmw 27,0x14(1); addi 27,3,0; lis 3,-32694; rlwinm 5,27,4,0,27; addi 0,3,-21520; add 30,0,5; addi 28,4,0; li 29,0; li 31,0; 0:; lwz 0,0x0(30); cmplwi 0,0; mr 12,0; beq 1f; stw 31,0x0(30); mtspr 8,12; addi 3,27,0; addi 4,28,0; blrl; 1:; addi 29,29,1; cmpwi 29,4; addi 30,30,4; blt 0b; lmw 27,0x14(1); lwz 0,0x2c(1); addi 1,1,40; mtspr 8,0"
extern "C" void f_80259E64() {}
