// 0x802C82F4 EFixedString::MakeLegalFilename(void) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="" lines="lwz 9,0x0(3); li 11,95; 0:; lbz 0,0x0(9); extsb 0,0; cmpwi 0,58; beq 4f; bgt 2f; cmpwi 0,35; bgt 1f; cmpwi 0,34; bge 4f; cmpwi 0,0; beqlr; b 5f; 1:; cmpwi 0,42; beq 4f; cmpwi 0,47; beq 4f; b 5f; 2:; cmpwi 0,63; bgt 3f; cmpwi 0,62; bge 4f; cmpwi 0,60; beq 4f; b 5f; 3:; cmpwi 0,92; beq 4f; cmpwi 0,124; bne 5f; 4:; stb 11,0x0(9); 5:; addi 9,9,1; b 0b"
extern "C" void f_802C82F4() {}
