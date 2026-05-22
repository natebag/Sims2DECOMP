// 0x80258140 EXIGetType (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); addi 31,5,0; addi 5,1,20; bl _s80258140_0; cmpwi 3,0; bne 0f; b 10f; 0:; lwz 6,0x14(1); rlwinm 5,6,0,0,23; lis 4,1026; addi 0,4,768; cmpw 5,0; beq 2f; bge 1f; addi 0,4,512; cmpw 5,0; beq 2f; bge 3f; addi 0,4,256; cmpw 5,0; beq 2f; b 3f; 1:; lis 0,1030; cmpw 5,0; beq 2f; b 3f; 2:; stw 5,0x0(31); b 10f; 3:; rlwinm 4,6,0,0,15; lis 0,1287; cmpw 4,0; beq 8f; bge 9f; cmpwi 4,0; beq 4f; b 9f; 4:; andi. 0,6,14339; bne 9f; rlwinm 0,6,0,24,29; cmpwi 0,32; beq 7f; bge 6f; cmpwi 0,8; beq 7f; bge 5f; cmpwi 0,4; beq 7f; b 9f; 5:; cmpwi 0,16; beq 7f; b 9f; 6:; cmpwi 0,128; beq 7f; bge 9f; cmpwi 0,64; beq 7f; b 9f; 7:; stw 0,0x0(31); b 10f; 8:; stw 0,0x0(31); b 10f; 9:; stw 6,0x0(31); 10:; lwz 0,0x24(1); lwz 31,0x1c(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80258140_0();
extern "C" void f_80258140() {}
