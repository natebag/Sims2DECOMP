// 0x802907E4 AptCIH::Release(char (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x5c(3); lwz 9,0x0(3); rlwinm 0,0,20,30,31; rlwinm 9,9,18,20,31; cmpwi 0,1; bne 0f; cmpwi 9,1; beq 1f; 0:; bl _s802907E4_0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802907E4_0();
extern "C" void f_802907E4() {}
