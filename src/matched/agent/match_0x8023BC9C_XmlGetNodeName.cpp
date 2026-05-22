// 0x8023BC9C XmlGetNodeName (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 0,0x0(3); cmpwi 0,60; beq 0f; li 3,-1; blr; 0:; addi 3,3,1; li 11,0; lbzx 9,3,11; addi 5,5,-1; b 2f; 1:; stbx 9,4,11; addi 11,11,1; lbzx 9,3,11; 2:; rlwinm 0,9,0,24,31; cmpwi 0,0; beq 3f; cmpwi 0,62; beq 3f; cmpwi 0,47; beq 3f; cmpwi 0,32; beq 3f; cmpw 11,5; blt 1b; 3:; li 0,0; addi 3,11,1; stbx 0,4,11"
extern "C" void f_8023BC9C() {}
