// 0x8012D140 PlayerFamilyImpl::GetStatValue(int) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmplwi 4,24; bgt 0f; add 0,4,4; addi 9,3,3240; lhax 3,9,0; blr; 0:; li 3,0"
extern "C" int f_8012D140() {}
