// 0x80145354 ObjectSlot::GetHeightMask(StdHeight) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 0,3,-1; li 3,1; slw 3,3,0"
extern "C" int f_80145354() {}
