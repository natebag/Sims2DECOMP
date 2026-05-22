// 0x8036F428 ConfigureVideo (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); li 0,480; stwu 1,-72(1); sth 3,0x10(1); li 3,40; sth 0,0x12(1); li 0,640; sth 4,0x14(1); sth 3,0x16(1); sth 0,0x1a(1); sth 4,0x1c(1); bl _s8036F428_0; cmpwi 3,2; beq 1f; bge 0f; cmpwi 3,0; beq 1f; bge 4f; b 5f; 0:; cmpwi 3,5; beq 3f; b 5f; 1:; lis 3,-13312; lhz 0,0x206c(3); rlwinm. 0,0,0,31,31; beq 2f; li 0,2; stw 0,0xc(1); li 0,0; sth 0,0x18(1); stw 0,0x20(1); b 5f; 2:; li 3,0; stw 3,0xc(1); li 0,1; sth 3,0x18(1); stw 0,0x20(1); b 5f; 3:; li 0,20; stw 0,0xc(1); li 3,0; li 0,1; sth 3,0x18(1); stw 0,0x20(1); b 5f; 4:; li 0,4; stw 0,0xc(1); li 3,47; li 0,1; sth 3,0x18(1); stw 0,0x20(1); 5:; addi 3,1,12; bl _s8036F428_1; li 3,0; li 4,0; li 5,640; li 6,480; bl _s8036F428_2; lwz 0,0x4c(1); addi 1,1,72; mtspr 8,0"
extern "C" void _s8036F428_0();
extern "C" void _s8036F428_1();
extern "C" void _s8036F428_2();
extern "C" void f_8036F428() {}
