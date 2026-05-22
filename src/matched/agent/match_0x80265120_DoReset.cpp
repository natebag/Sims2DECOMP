// 0x80265120 DoReset (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); lwz 5,-23176(13); cntlzw 0,5; stw 0,-27652(13); lwz 4,-27652(13); cmpwi 4,32; beq 0f; lis 0,-32768; srw 0,0,4; andc 0,5,0; mulli 4,4,12; stw 0,-23176(13); lis 3,-32694; addi 0,3,-16400; add 3,0,4; li 4,0; li 5,12; bl _s80265120_0; lis 4,-32730; lwz 3,-27652(13); addi 4,4,21916; bl _s80265120_1; 0:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80265120_0();
extern "C" void _s80265120_1();
extern "C" void f_80265120() {}
