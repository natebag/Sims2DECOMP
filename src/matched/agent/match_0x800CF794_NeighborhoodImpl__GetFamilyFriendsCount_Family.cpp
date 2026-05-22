// 0x800CF794 NeighborhoodImpl::GetFamilyFriendsCount(Family (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,4; lwz 0,0x20(31); cmpwi 0,0; beq 0f; bl _s800CF794_0; 0:; lwz 3,0x1c(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800CF794_0();
extern "C" void f_800CF794() {}
