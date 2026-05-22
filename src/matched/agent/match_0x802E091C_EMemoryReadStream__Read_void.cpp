// 0x802E091C EMemoryReadStream::Read(void (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,5; mr. 8,4; bne 0f; li 3,0; b 8f; 0:; lwz 11,0x20(3); mr 9,8; lwz 10,0x1c(3); cmpwi 31,2; add 0,11,31; stw 0,0x20(3); add 4,10,11; beq 5f; bgt 1f; cmpwi 31,0; beq 7f; cmpwi 31,1; beq 6f; b 2f; 1:; cmpwi 31,3; beq 4f; cmpwi 31,4; beq 3f; 2:; mr 3,8; mr 5,31; crxor 6,6,6; bl _s802E091C_0; b 7f; 3:; lbzx 0,10,11; addi 4,4,1; stb 0,0x0(9); addi 9,9,1; 4:; lbz 0,0x0(4); addi 4,4,1; stb 0,0x0(9); addi 9,9,1; 5:; lbz 0,0x0(4); addi 4,4,1; stb 0,0x0(9); addi 9,9,1; 6:; lbz 0,0x0(4); stb 0,0x0(9); 7:; mr 3,31; 8:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802E091C_0();
extern "C" void f_802E091C() {}
