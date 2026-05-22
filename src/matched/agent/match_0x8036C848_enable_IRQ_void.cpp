// 0x8036C848 enable_IRQ(void) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,-25812(13); cmpwi 9,0; beq 0f; addi 0,9,-1; cmpwi 0,0; stw 0,-25812(13); bne 0f; lwz 3,-22396(13); bl _s8036C848_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8036C848_0();
extern "C" void f_8036C848() {}
