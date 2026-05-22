// 0x8033AACC ENgcRC::TextureMatrix(EMat4 (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); mr. 4,4; beq 3f; li 0,16; stw 4,0xc(1); stb 0,0x8(1); cmpwi 8,0; stb 5,0x9(1); li 0,128; beq 0f; li 0,256; 0:; cmpwi 6,0; beq 1f; ori 0,0,512; 1:; cmpwi 7,0; beq 2f; ori 0,0,1024; 2:; rlwinm 0,0,25,7,31; lis 3,-32691; stb 0,0xa(1); addi 3,3,21688; addi 4,1,8; bl _s8033AACC_0; b 5f; 3:; lwz 9,0x70(3); cmpwi 8,0; li 4,128; lha 0,0x130(9); addi 11,9,304; add 3,3,0; beq 4f; li 4,256; 4:; lwz 0,0x4(11); mtspr 8,0; blrl; 5:; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s8033AACC_0();
extern "C" void f_8033AACC() {}
