// 0x80039200 EyeToyClient::GetRepTexture(int) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mulli 3,3,12; lis 9,-32702; addi 9,9,15808; lwzx 11,3,9; lwz 10,0x4(11); lwz 9,0x20(10); lwz 3,0x14(9)"
extern "C" int f_80039200() {}
