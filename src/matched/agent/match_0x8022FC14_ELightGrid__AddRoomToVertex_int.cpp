// 0x8022FC14 ELightGrid::AddRoomToVertex(int, (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmplwi 4,62; bgtlr; cmpwi 5,0; bltlr; cmpwi 5,62; bgtlr; mulli 9,4,2268; li 10,0; mulli 11,5,36; addi 9,9,27972; add 9,3,9; add 4,9,11; b 1f; 0:; addi 10,10,1; cmpwi 10,3; bgt 4f; 1:; lbzx 0,4,10; extsb 0,0; cmpwi 0,-1; beq 2f; cmpw 0,6; bne 0b; 2:; cmpwi 10,3; bgt 4f; rlwinm 9,10,3,0,28; li 11,4; addi 9,9,4; mtspr 9,11; stbx 6,4,10; add 9,4,9; li 0,-1; addi 4,9,6; 3:; sth 0,0x0(4); addi 4,4,-2; bdnz 3b; 4:; li 0,1; stw 0,0x0(3)"
extern "C" void f_8022FC14() {}
