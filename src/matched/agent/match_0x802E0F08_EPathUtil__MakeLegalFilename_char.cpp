// 0x802E0F08 EPathUtil::MakeLegalFilename(char (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 0,0x0(4); mr 9,3; cmpwi 0,0; beqlr; li 11,95; 0:; extsb 0,0; cmpwi 0,58; beq 3f; bgt 1f; cmpwi 0,34; blt 4f; cmpwi 0,35; ble 3f; cmpwi 0,42; beq 3f; cmpwi 0,47; beq 3f; b 4f; 1:; cmpwi 0,63; bgt 2f; cmpwi 0,62; bge 3f; cmpwi 0,60; beq 3f; b 4f; 2:; cmpwi 0,92; beq 3f; cmpwi 0,124; bne 4f; 3:; stb 11,0x0(9); b 5f; 4:; lbz 0,0x0(4); stb 0,0x0(9); 5:; lbzu 0,0x1(4); addi 9,9,1; cmpwi 0,0; bne 0b"
extern "C" void f_802E0F08() {}
