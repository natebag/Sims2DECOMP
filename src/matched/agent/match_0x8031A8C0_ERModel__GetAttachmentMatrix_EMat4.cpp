// 0x8031A8C0 ERModel::GetAttachmentMatrix(EMat4 (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; mr 29,4; mr 28,6; mr 27,7; mr. 31,5; beq 1f; lbz 4,0x134(31); cmpwi 4,0; beq 1f; lbz 0,0x135(31); lbz 9,0x13b(30); extsb 0,0; cmpw 0,9; bge 0f; cmpwi 0,0; bge 2f; 0:; mr 3,30; addi 5,31,309; bl _s8031A8C0_0; cmpwi 3,0; bne 2f; 1:; li 3,0; b 3f; 2:; lis 9,-32702; lfs f1,0x88(31); lfs f2,0x8e8(9); mr 3,30; lbz 5,0x135(31); mr 4,29; mr 6,28; mr 7,27; bl _s8031A8C0_1; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8031A8C0_0();
extern "C" void _s8031A8C0_1();
extern "C" void f_8031A8C0() {}
