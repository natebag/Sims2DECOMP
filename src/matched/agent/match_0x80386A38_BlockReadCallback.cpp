// 0x80386A38 BlockReadCallback (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); addi 31,3,0; lis 3,-32688; stw 30,0x18(1); mulli 5,31,272; stw 29,0x14(1); addi 0,3,-24000; mr. 29,4; add 30,0,5; blt 0f; lwz 3,0xb8(30); addi 0,3,512; stw 0,0xb8(30); lwz 3,0xb0(30); addi 0,3,512; stw 0,0xb0(30); lwz 3,0xb4(30); addi 0,3,512; stw 0,0xb4(30); lwz 3,0xac(30); addic. 0,3,-1; stw 0,0xac(30); ble 0f; lis 3,-32712; addi 4,3,27192; addi 3,31,0; bl _s80386A38_0; mr. 29,3; bge 2f; 0:; lwz 0,0xd0(30); cmplwi 0,0; bne 1f; addi 3,30,0; addi 4,29,0; bl _s80386A38_1; 1:; lwz 0,0xd4(30); cmplwi 0,0; mr 12,0; beq 2f; li 0,0; mtspr 8,12; stw 0,0xd4(30); addi 3,31,0; addi 4,29,0; blrl; 2:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80386A38_0();
extern "C" void _s80386A38_1();
extern "C" void f_80386A38() {}
