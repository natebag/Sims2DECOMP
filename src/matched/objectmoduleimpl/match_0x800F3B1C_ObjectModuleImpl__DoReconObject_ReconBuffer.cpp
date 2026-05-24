// 0x800F3B1C ObjectModuleImpl::DoReconObject(ReconBuffer (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,4; mr 30,3; lwz 0,0xc(31); mr 29,5; cmpwi 0,0; beq 2f; lwz 9,0x0(29); cmpwi 9,0; beq 0f; lwz 3,0x4(9); lwz 9,0x4(3); lha 0,0x328(9); lwz 9,0x32c(9); add 3,3,0; mtspr 8,9; blrl; b 1f; 0:; li 3,0; 1:; sth 3,0x8(1); 2:; mr 3,31; addi 4,1,8; li 5,1; bl _s800F3B1C_0; lwz 0,0xc(31); cmpwi 0,0; bne 5f; lwz 9,0x0(30); lha 4,0x8(1); lha 3,0x90(9); lwz 0,0x94(9); add 3,30,3; mtspr 8,0; blrl; mr. 11,3; beq 3f; lwz 9,0x4(11); lha 3,0x520(9); lwz 0,0x524(9); add 3,11,3; mtspr 8,0; blrl; b 4f; 3:; li 3,0; 4:; stw 3,0x0(29); 5:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"

extern "C" void _s800F3B1C_0();

struct ObjectModuleImpl {
    void DoReconObject();
};

void ObjectModuleImpl::DoReconObject() {
}
