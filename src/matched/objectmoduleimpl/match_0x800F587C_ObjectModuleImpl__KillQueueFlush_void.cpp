// 0x800F587C ObjectModuleImpl::KillQueueFlush(void) (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; addi 11,30,8260; lwz 9,0x2044(30); lwz 0,0x4(11); subf 0,9,0; rlwinm. 9,0,31,1,31; beq 4f; mr 29,11; 0:; lwz 3,0x2044(30); lwz 5,0x4(29); addi 4,3,2; lha 28,0x0(3); cmpw 4,5; beq 1f; cmpw 5,4; beq 1f; subf 5,4,5; bl _s800F587C_0; 1:; lwz 9,0x4(29); mr 4,28; addi 9,9,-2; stw 9,0x4(29); lwz 11,0x0(30); lha 3,0x90(11); lwz 0,0x94(11); add 3,30,3; mtspr 8,0; blrl; mr. 31,3; beq 3f; lwz 9,0x4(31); lha 3,0x390(9); lwz 0,0x394(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 2f; lwz 3,0x0(31); li 4,3; bl _s800F587C_1; mr. 31,3; beq 2f; lwz 9,0x4(31); lha 3,0x40(9); lwz 0,0x44(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 2f; lwz 9,0x4(31); lha 3,0x50(9); lwz 0,0x54(9); add 3,31,3; mtspr 8,0; blrl; 2:; lwz 9,0x0(30); mr 4,28; lha 3,0x58(9); lwz 0,0x5c(9); add 3,30,3; mtspr 8,0; blrl; 3:; lwz 9,0x2044(30); lwz 0,0x4(29); subf 0,9,0; rlwinm. 9,0,31,1,31; bne 0b; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s800F587C_0();
extern "C" void _s800F587C_1();

struct ObjectModuleImpl {
    void KillQueueFlush();
};

void ObjectModuleImpl::KillQueueFlush() {
}
