// 0x802DF2C8 DbgLogTraceOpen(char (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-136(1); mfspr 0,8; stw 0,0x8c(1); mr 6,3; lis 5,-32702; lis 4,-32702; addi 5,5,-6460; addi 4,4,-6456; addi 3,1,8; crxor 6,6,6; bl _s802DF2C8_0; lis 4,-32702; addi 3,1,8; addi 4,4,-6448; bl _s802DF2C8_1; stw 3,-26832(13); lwz 0,0x8c(1); mtspr 8,0; addi 1,1,136"
extern "C" void _s802DF2C8_0();
extern "C" void _s802DF2C8_1();
extern "C" void f_802DF2C8() {}
