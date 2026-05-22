// 0x80252BA8 OSSetVideoMode (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); addi 30,3,0; cmplwi 30,2; lis 3,-32694; addi 31,3,-24704; ble 0f; li 30,0; 0:; bl _s80252BA8_0; lwz 0,0x48(31); addi 4,31,72; cmpwi 0,0; beq 1f; bl _s80252BA8_1; li 31,0; b 2f; 1:; stw 3,0x44(31); li 0,1; stw 0,0x0(4); 2:; lbz 3,0x13(31); rlwinm 0,3,0,30,31; cmplw 30,0; bne 3f; li 3,0; li 4,0; bl _s80252BA8_2; b 4f; 3:; rlwinm 0,3,0,0,29; stb 0,0x13(31); li 3,1; li 4,0; lbz 0,0x13(31); or 0,0,30; stb 0,0x13(31); bl _s80252BA8_3; 4:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80252BA8_0();
extern "C" void _s80252BA8_1();
extern "C" void _s80252BA8_2();
extern "C" void _s80252BA8_3();
extern "C" void f_80252BA8() {}
