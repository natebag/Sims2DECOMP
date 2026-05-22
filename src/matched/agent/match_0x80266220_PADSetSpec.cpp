// 0x80266220 PADSetSpec (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; cmpwi 3,1; stw 0,-23140(13); beq 2f; bge 0f; cmpwi 3,0; bge 1f; b 4f; 0:; cmpwi 3,6; bge 4f; b 3f; 1:; lis 4,-32730; addi 0,4,25224; stw 0,-27636(13); b 4f; 2:; lis 4,-32730; addi 0,4,25596; stw 0,-27636(13); b 4f; 3:; lis 4,-32730; addi 0,4,26080; stw 0,-27636(13); 4:; stw 3,-27640(13)"
extern "C" void f_80266220() {}
