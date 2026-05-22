// 0x8034EA38 enable_IRQ(void) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,-22476(13); cmpwi 9,0; beq 0f; addi 0,9,-1; cmpwi 0,0; stw 0,-22476(13); bne 0f; lwz 3,-22480(13); bl _s8034EA38_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8034EA38_0();
extern "C" void f_8034EA38() {}
