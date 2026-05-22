// 0x80039498 EyeToyClient::Debug::GetTierNthRepShader(int, (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mulli 3,3,12; lis 9,-32702; addi 9,9,15808; rlwinm 4,4,3,0,28; lwzx 0,9,3; add 4,4,0; lwz 3,0x4(4)"
extern "C" int f_80039498() {}
