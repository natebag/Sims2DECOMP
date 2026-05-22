// 0x80336938 ProperTimingForStart(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32691; lwz 0,0x39c8(9); andi. 9,0,1; beq 0f; bl _s80336938_0; cmpwi 3,0; b 1f; 0:; andi. 9,0,2; beq 2f; bl _s80336938_1; cmpwi 3,1; 1:; bne 3f; 2:; li 3,1; b 4f; 3:; li 3,0; 4:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80336938_0();
extern "C" void _s80336938_1();
extern "C" void f_80336938() {}
