// 0x8015E1DC TreeTableQuickData::GetEntryByTreeID(short, (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0x4(31); cmpwi 3,0; beq 0f; bl _s8015E1DC_0; lwz 9,0x0(31); mr 4,3; lha 3,0x78(9); lwz 0,0x7c(9); add 3,31,3; mtspr 8,0; blrl; b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8015E1DC_0();
extern "C" void f_8015E1DC() {}
