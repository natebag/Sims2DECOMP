// 0x802C48B4 StringPool::CheckContent(void) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32694; lis 11,-32700; addi 30,9,-11332; addi 28,11,-6476; addi 29,30,4; li 9,0; 0:; rlwinm 4,9,2,0,29; lwzx 3,4,30; cmpw 3,28; beq 3f; addi 0,9,1; mr 31,0; cmpwi 0,177; bgt 4f; lwzx 4,4,29; cmpw 3,4; bne 1f; li 3,0; b 2f; 1:; addi 3,3,8; addi 4,4,8; bl _s802C48B4_0; 2:; cmpwi 3,0; blt 4f; 3:; li 3,0; b 5f; 4:; mr 9,31; cmpwi 9,177; ble 0b; li 3,1; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802C48B4_0();
extern "C" void f_802C48B4() {}
