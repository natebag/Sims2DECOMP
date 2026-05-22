// 0x8024B30C InquiryCallback (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0xc(4); cmpwi 0,0; beq 0f; b 1f; 0:; lis 3,-32694; addi 3,3,-24896; lhz 0,0x2(3); lis 3,-32768; ori 0,0,32768; sth 0,0x30e6(3); b 2f; 1:; li 0,1; lis 3,-32768; sth 0,0x30e6(3); 2:"
extern "C" void f_8024B30C() {}
