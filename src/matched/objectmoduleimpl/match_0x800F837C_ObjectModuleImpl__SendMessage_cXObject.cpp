// 0x800F837C ObjectModuleImpl::SendMessage(cXObject (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); sth 6,0x8(1); addi 9,1,8; li 0,0; mr 31,4; sth 0,0x6(9); mr 30,5; sth 0,0x2(9); mr 28,9; sth 0,0x4(9); lwz 11,0x4(31); lwz 0,0x37c(11); lha 3,0x378(11); mtspr 8,0; add 3,31,3; blrl; mr 29,3; mr 4,30; lwz 9,0x0(29); lha 3,0x48(9); lwz 0,0x4c(9); add 3,29,3; mtspr 8,0; blrl; mr. 30,3; beq 2f; cmpwi 31,0; beq 0f; lwz 9,0x4(31); lha 3,0x520(9); lwz 0,0x524(9); add 3,31,3; mtspr 8,0; blrl; b 1f; 0:; li 3,0; 1:; lwz 3,0x0(3); mr 4,29; mr 6,30; mr 7,28; li 5,0; bl _s800F837C_0; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"

extern "C" void _s800F837C_0();

struct ObjectModuleImpl {
    void SendMessage_cXObject();
};

void ObjectModuleImpl::SendMessage_cXObject() {
}
