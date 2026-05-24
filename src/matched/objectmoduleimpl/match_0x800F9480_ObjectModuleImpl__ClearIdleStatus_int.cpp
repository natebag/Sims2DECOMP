// 0x800F9480 ObjectModuleImpl::ClearIdleStatus(int) (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); mr 29,3; mr 28,4; lwz 9,0x0(29); lha 3,0x90(9); lwz 0,0x94(9); add 3,29,3; mtspr 8,0; blrl; mr. 3,3; beq 0f; lwz 3,0x0(3); lwz 9,0x18(3); lha 0,0x50(9); lwz 9,0x54(9); add 3,3,0; mtspr 8,9; blrl; mr. 31,3; beq 0f; lwz 30,0x10(31); mr 3,31; bl _s800F9480_0; mr 4,3; lha 5,0x2(31); mr 3,30; addi 6,1,8; bl _s800F9480_1; cmpwi 3,0; beq 0f; lhz 0,0x8(1); andi. 9,0,32767; bne 0f; lwz 9,0x0(29); mr 4,28; lha 3,0x238(9); lwz 0,0x23c(9); add 3,29,3; mtspr 8,0; blrl; extsh 30,3; cmpwi 30,0; blt 0f; mr 3,31; bl _s800F9480_2; sth 30,0x0(3); 0:; lwz 9,0x0(29); mr 4,28; li 5,-2; lha 3,0x228(9); lwz 0,0x22c(9); add 3,29,3; mtspr 8,0; blrl; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"

extern "C" void _s800F9480_0();
extern "C" void _s800F9480_1();
extern "C" void _s800F9480_2();

struct ObjectModuleImpl {
    void ClearIdleStatus();
};

void ObjectModuleImpl::ClearIdleStatus() {
}
