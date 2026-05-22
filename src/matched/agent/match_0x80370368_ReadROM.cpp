// 0x80370368 ReadROM (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); stw 30,0x20(1); addi 30,5,0; stw 29,0x1c(1); addi 29,4,0; stw 28,0x18(1); addi 28,3,0; b 4f; 0:; cmpwi 29,256; bgt 1f; mr 31,29; b 2f; 1:; li 31,256; 2:; subf 29,31,29; 3:; addi 3,28,0; addi 4,31,0; addi 5,30,0; bl _s80370368_0; cmpwi 3,0; beq 3b; add 30,30,31; add 28,28,31; 4:; cmpwi 29,0; bgt 0b; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); lwz 28,0x18(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s80370368_0();
extern "C" void f_80370368() {}
