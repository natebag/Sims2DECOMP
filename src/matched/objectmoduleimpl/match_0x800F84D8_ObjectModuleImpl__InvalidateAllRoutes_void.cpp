// 0x800F84D8 ObjectModuleImpl::InvalidateAllRoutes(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; addi 9,30,8280; lwz 31,0x2058(30); lwz 0,0x4(9); cmpw 31,0; beq 1f; mr 29,9; 0:; lwz 11,0x0(31); addi 31,31,4; lwz 10,0x4(11); lwz 9,0x4(10); lwz 0,0x264(9); lha 3,0x260(9); mtspr 8,0; add 3,10,3; blrl; lwz 0,0x4(29); cmpw 31,0; bne 0b; 1:; mr 3,30; bl _s800F84D8_0; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s800F84D8_0();

struct ObjectModuleImpl {
    void InvalidateAllRoutes();
};

void ObjectModuleImpl::InvalidateAllRoutes() {
}
