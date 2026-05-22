// 0x8031A7FC ERModel::GetAttachmentID(unsigned (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x138(3); li 11,0; cmpw 11,0; bge 2f; li 10,0; 0:; lwz 9,0x13c(3); add 9,10,9; lbz 0,0x7(9); cmpw 0,4; bne 1f; stb 11,0x0(5); li 3,1; blr; 1:; lwz 0,0x138(3); addi 11,11,1; addi 10,10,64; cmpw 11,0; blt 0b; 2:; li 3,0"
extern "C" void f_8031A7FC() {}
