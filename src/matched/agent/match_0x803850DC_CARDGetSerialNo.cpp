// 0x803850DC CARDGetSerialNo (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; cmpwi 3,0; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); addi 31,4,0; blt 0f; cmpwi 3,2; blt 1f; 0:; li 3,-128; b 3f; 1:; addi 4,1,16; bl _s803850DC_0; cmpwi 3,0; bge 2f; b 3f; 2:; lwz 3,0x10(1); li 7,0; li 6,0; lwz 5,0x80(3); li 4,0; lwz 3,0x4(5); lwz 0,0x0(5); xor 7,7,3; addi 3,5,8; xor 6,6,0; lwz 0,0x8(5); lwz 3,0x4(3); xor 6,6,0; xor 7,7,3; addi 3,5,16; lwz 0,0x10(5); lwz 3,0x4(3); xor 6,6,0; xor 7,7,3; addi 3,5,24; lwz 0,0x18(5); lwz 3,0x4(3); xor 6,6,0; xor 7,7,3; stw 7,0x4(31); stw 6,0x0(31); lwz 3,0x10(1); bl _s803850DC_1; 3:; lwz 0,0x24(1); lwz 31,0x1c(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s803850DC_0();
extern "C" void _s803850DC_1();
extern "C" void f_803850DC() {}
