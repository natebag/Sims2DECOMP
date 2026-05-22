// 0x8037EF68 __CARDExtHandler (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); addi 29,3,0; mulli 4,29,272; lis 3,-32688; addi 0,3,-24000; add 30,0,4; lwz 0,0x0(30); cmpwi 0,0; beq 2f; li 31,0; stw 31,0x0(30); addi 3,29,0; li 4,0; bl _s8037EF68_0; addi 3,30,224; bl _s8037EF68_1; lwz 0,0xcc(30); cmplwi 0,0; mr 12,0; beq 0f; stw 31,0xcc(30); mtspr 8,12; addi 3,29,0; li 4,-3; blrl; 0:; lwz 0,0x4(30); cmpwi 0,-1; beq 1f; li 0,-3; stw 0,0x4(30); 1:; lwz 12,0xc4(30); cmplwi 12,0; beq 2f; lwz 0,0x24(30); cmpwi 0,7; blt 2f; li 0,0; mtspr 8,12; stw 0,0xc4(30); addi 3,29,0; li 4,-3; blrl; 2:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8037EF68_0();
extern "C" void _s8037EF68_1();
extern "C" void f_8037EF68() {}
