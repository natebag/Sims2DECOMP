// 0x8023BD50 XmlGetAttribName (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,5; mr 31,6; bl _s8023BD50_0; mr. 3,3; bne 0f; li 3,-1; b 4f; 0:; li 11,0; addi 31,31,-1; b 2f; 1:; stbx 9,30,11; addi 11,11,1; 2:; lbzx 9,3,11; rlwinm 0,9,0,24,31; cmpwi 0,0; beq 3f; cmpwi 0,61; beq 3f; cmpw 11,31; blt 1b; 3:; li 0,0; addi 3,11,1; stbx 0,30,11; 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8023BD50_0();
extern "C" void f_8023BD50() {}
