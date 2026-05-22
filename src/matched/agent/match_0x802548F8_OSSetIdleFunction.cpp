// 0x802548F8 OSSetIdleFunction (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; cmplwi 3,0; stw 0,0x4(1); lis 8,-32694; addi 10,4,0; stwu 1,-32(1); addi 9,5,0; addi 7,6,0; stw 31,0x1c(1); addi 31,8,-24616; beq 0f; lhz 0,0x3c8(31); cmplwi 0,0; bne 1f; addi 4,3,0; addi 6,9,0; addi 5,10,0; addi 3,31,256; li 8,31; li 9,1; bl _s802548F8_0; addi 3,31,256; bl _s802548F8_1; addi 3,31,256; b 2f; 0:; lhz 0,0x3c8(31); cmplwi 0,0; beq 1f; addi 3,31,256; bl _s802548F8_2; 1:; li 3,0; 2:; lwz 0,0x24(1); lwz 31,0x1c(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s802548F8_0();
extern "C" void _s802548F8_1();
extern "C" void _s802548F8_2();
extern "C" void f_802548F8() {}
