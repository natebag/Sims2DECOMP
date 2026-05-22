// 0x8039320C __THPSetupBuffers (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,-21556(13); lis 3,-32688; addi 5,3,-20040; addi 0,4,31; clrlwi 6,0,26; stw 6,0x0(5); addi 3,6,128; addi 0,6,256; stw 3,0x4(5); addi 4,6,384; addi 3,6,512; stw 0,0x8(5); addi 0,6,640; stw 4,0xc(5); stw 3,0x10(5); stw 0,0x14(5)"
extern "C" void f_8039320C() {}
