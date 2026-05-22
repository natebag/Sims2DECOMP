// 0x80266B9C OnReset (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); addi 31,3,0; lwz 0,-23148(13); cmplwi 0,0; beq 0f; li 3,0; bl _s80266B9C_0; 0:; cmpwi 31,0; bne 4f; lwz 0,-23176(13); li 31,0; addi 3,31,0; cmplwi 0,0; bne 1f; lwz 0,-27652(13); cmpwi 0,32; bne 1f; li 3,1; 1:; cmpwi 3,0; beq 2f; bl _s80266B9C_1; cmpwi 3,0; bne 2f; li 31,1; 2:; lwz 0,-23144(13); cmpwi 0,0; bne 3f; cmpwi 31,0; beq 3f; lis 3,-4096; bl _s80266B9C_2; stw 3,-23144(13); li 3,0; b 5f; 3:; mr 3,31; b 5f; 4:; li 0,0; stw 0,-23144(13); li 3,1; 5:; lwz 0,0x24(1); lwz 31,0x1c(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80266B9C_0();
extern "C" void _s80266B9C_1();
extern "C" void _s80266B9C_2();
extern "C" void f_80266B9C() {}
