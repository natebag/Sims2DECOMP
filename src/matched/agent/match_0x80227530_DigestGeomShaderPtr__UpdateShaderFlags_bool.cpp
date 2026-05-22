// 0x80227530 DigestGeomShaderPtr::UpdateShaderFlags(bool (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(3); lwz 0,0x14(9); cmpwi 0,0; beq 0f; mr 11,0; b 1f; 0:; lwz 9,0x18(9); li 11,0; cmpwi 9,0; beq 1f; lwz 11,0x14(9); 1:; lwz 9,0x4(11); li 10,0; addi 11,11,100; stw 9,0x8(3); lwz 0,0xc(11); andi. 9,0,64; beq 3f; lbz 0,0x1c(11); cmpwi 0,1; beq 2f; lbz 0,0x1d(11); cmpwi 0,1; beq 2f; lbz 0,0x1f(11); cmpwi 0,1; bne 3f; 2:; li 10,1; 3:; cmpwi 10,0; beq 4f; lwz 0,0x8(3); andi. 9,0,2048; bne 4f; ori 0,0,32768; stw 0,0x8(3); 4:; lwz 0,0x8(3); andi. 9,0,32; beqlr; li 0,1; stw 0,0x0(4)"
extern "C" void f_80227530() {}
