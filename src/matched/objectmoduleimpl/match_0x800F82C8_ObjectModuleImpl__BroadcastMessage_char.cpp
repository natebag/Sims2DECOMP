// 0x800F82C8 ObjectModuleImpl::BroadcastMessage(char (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); sth 5,0x8(1); addi 9,1,8; li 0,0; mr 28,9; sth 0,0x6(9); mr 29,4; sth 0,0x2(9); sth 0,0x4(9); lwz 30,0x2c(3); cmpwi 30,0; beq 2f; 0:; lwz 11,0x4(30); lwz 9,0x4(11); lwz 0,0x37c(9); lha 3,0x378(9); mtspr 8,0; add 3,11,3; blrl; mr 31,3; mr 4,29; lwz 9,0x0(31); lha 3,0x48(9); lwz 0,0x4c(9); add 3,31,3; mtspr 8,0; blrl; mr. 6,3; beq 1f; lwz 3,0x0(30); mr 4,31; li 5,0; mr 7,28; bl _s800F82C8_0; 1:; lwz 30,0x5c(30); cmpwi 30,0; bne 0b; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"

extern "C" void _s800F82C8_0();

struct ObjectModuleImpl {
    void BroadcastMessage();
};

void ObjectModuleImpl::BroadcastMessage() {
}
