// 0x8038F2E8 GXSetTevIndBumpST (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; cmpwi 5,2; stw 0,0x4(1); stwu 1,-48(1); stw 31,0x2c(1); stw 30,0x28(1); stw 29,0x24(1); addi 29,4,0; stw 28,0x20(1); addi 28,3,0; beq 2f; bge 0f; cmpwi 5,1; bge 1f; b 4f; 0:; cmpwi 5,4; bge 4f; b 3f; 1:; li 7,5; li 30,9; b 4f; 2:; li 7,6; li 30,10; b 4f; 3:; li 7,7; li 30,11; 4:; li 31,0; stw 31,0x8(1); addi 3,28,0; addi 4,29,0; stw 31,0xc(1); li 5,0; li 6,3; li 8,6; li 9,6; li 10,0; bl _s8038F2E8_0; stw 31,0x8(1); addi 4,29,0; addi 7,30,0; stw 31,0xc(1); addi 3,28,1; li 5,0; li 6,3; li 8,6; li 9,6; li 10,1; bl _s8038F2E8_1; stw 31,0x8(1); addi 4,29,0; addi 3,28,2; stw 31,0xc(1); li 5,0; li 6,0; li 7,0; li 8,0; li 9,0; li 10,1; bl _s8038F2E8_2; lwz 0,0x34(1); lwz 31,0x2c(1); lwz 30,0x28(1); lwz 29,0x24(1); lwz 28,0x20(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s8038F2E8_0();
extern "C" void _s8038F2E8_1();
extern "C" void _s8038F2E8_2();
extern "C" void f_8038F2E8() {}
