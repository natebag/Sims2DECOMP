// 0x80268FEC AptAllocatorShutdown(void) (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 3,-23016(13); lwz 0,0x18(3); cmpwi 0,0; bne 0f; bl _s80268FEC_0; cmpwi 3,0; beq 2f; 0:; lwz 3,-23016(13); bl _s80268FEC_1; mr. 4,3; beq 2f; 1:; lwz 3,-23016(13); bl _s80268FEC_2; mr. 4,3; bne 1b; 2:; lwz 3,-23020(13); cmpwi 3,0; beq 3f; li 4,3; bl _s80268FEC_3; 3:; lwz 31,-23016(13); cmpwi 31,0; beq 4f; mr 3,31; li 4,0; bl _s80268FEC_4; lis 9,-32694; mr 3,31; lwz 0,-16280(9); li 4,32; mtspr 8,0; blrl; 4:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80268FEC_0();
extern "C" void _s80268FEC_1();
extern "C" void _s80268FEC_2();
extern "C" void _s80268FEC_3();
extern "C" void _s80268FEC_4();
extern "C" void f_80268FEC() {}
