// 0x801D49D0 PCTTarget::get_cell_info_array_index(unsigned (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0xb4(3); mulli 3,3,6; add 3,3,4"
extern "C" int f_801D49D0() {}
