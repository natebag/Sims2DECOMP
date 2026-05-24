// 0x800F974C ObjectModuleImpl::CreateNeighbor(Neighbor (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 4,0xc(4); lwz 9,0x0(30); li 5,0; lwz 0,0x54(9); lha 3,0x50(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x0(30); mr 4,3; lha 3,0x90(9); lwz 0,0x94(9); add 3,30,3; mtspr 8,0; blrl; mr. 3,3; beq 0f; lwz 3,0x0(3); li 4,2; bl _s800F974C_0; b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s800F974C_0();

struct ObjectModuleImpl {
    void CreateNeighbor_Neighbor();
};

void ObjectModuleImpl::CreateNeighbor_Neighbor() {
}
