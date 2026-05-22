// 0x802E09EC EMemoryBufferWriteStream::Write(void (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 11,0x20(3); mr 31,5; lwz 10,0x1c(3); cmpwi 31,2; add 0,11,31; mr 9,4; stw 0,0x20(3); add 3,10,11; beq 4f; bgt 0f; cmpwi 31,0; beq 6f; cmpwi 31,1; beq 5f; b 1f; 0:; cmpwi 31,3; beq 3f; cmpwi 31,4; beq 2f; 1:; mr 5,31; crxor 6,6,6; bl _s802E09EC_0; b 6f; 2:; lbz 0,0x0(9); addi 3,3,1; addi 9,9,1; stbx 0,10,11; 3:; lbz 0,0x0(9); addi 9,9,1; stb 0,0x0(3); addi 3,3,1; 4:; lbz 0,0x0(9); addi 9,9,1; stb 0,0x0(3); addi 3,3,1; 5:; lbz 0,0x0(9); stb 0,0x0(3); 6:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802E09EC_0();
extern "C" void f_802E09EC() {}
