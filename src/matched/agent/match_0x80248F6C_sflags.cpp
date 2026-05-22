// 0x80248F6C __sflags (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 0,0x0(4); mr 9,3; extsb 0,0; cmpwi 0,114; beq 1f; bgt 0f; cmpwi 0,97; beq 3f; b 4f; 0:; cmpwi 0,119; beq 2f; b 4f; 1:; li 3,4; li 9,0; li 11,0; b 5f; 2:; li 3,8; li 9,1; li 11,1536; b 5f; 3:; li 3,264; li 9,1; li 11,520; b 5f; 4:; li 0,22; li 3,0; stw 0,0x0(9); blr; 5:; lbz 0,0x1(4); cmpwi 0,43; beq 6f; lbz 0,0x2(4); cmpwi 0,43; bne 7f; 6:; li 3,16; li 9,2; 7:; or 0,9,11; stw 0,0x0(5)"
extern "C" void f_80248F6C() {}
