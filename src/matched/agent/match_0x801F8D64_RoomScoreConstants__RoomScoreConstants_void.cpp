// 0x801F8D64 RoomScoreConstants::RoomScoreConstants(void) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,1; stw 29,0x9c(31); stw 0,0x8c(31); lis 9,-32697; lwz 4,0x98(31); li 5,1; lwz 3,0x5bcc(9); bl _s801F8D64_0; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24; blr; li 0,1; stw 0,0x94(3)"
extern "C" void _s801F8D64_0();
extern "C" void f_801F8D64() {}
