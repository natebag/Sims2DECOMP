// 0x8026094C cb (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; cmpwi 3,0; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); addi 31,4,0; ble 2f; lwz 0,-23376(13); cmpwi 0,1; beq 1f; bge 3f; cmpwi 0,0; bge 0f; b 3f; 0:; li 0,1; lwz 4,-23372(13); lis 3,-32730; stw 0,-23376(13); addi 7,3,2380; addi 3,31,0; li 5,32; li 6,1056; bl _s8026094C_0; b 3f; 1:; li 0,2; lwz 6,-23372(13); stw 0,-23376(13); lis 3,-32730; addi 7,3,2380; lwz 5,0x8(6); mr 3,31; lwz 4,0x10(6); addi 0,5,31; lwz 6,0x4(6); rlwinm 5,0,0,0,26; bl _s8026094C_1; b 3f; 2:; cmpwi 3,-1; beq 3f; cmpwi 3,-4; bne 3f; li 0,0; stw 0,-23376(13); bl _s8026094C_2; lis 3,-32730; lwz 4,-23368(13); addi 5,3,2380; addi 3,31,0; bl _s8026094C_3; 3:; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8026094C_0();
extern "C" void _s8026094C_1();
extern "C" void _s8026094C_2();
extern "C" void _s8026094C_3();
extern "C" void f_8026094C() {}
