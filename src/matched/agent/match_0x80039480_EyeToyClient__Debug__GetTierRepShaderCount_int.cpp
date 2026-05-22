// 0x80039480 EyeToyClient::Debug::GetTierRepShaderCount(int) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mulli 3,3,12; lis 9,-32702; addi 9,9,15808; addi 9,9,4; lwzx 3,9,3"
extern "C" int f_80039480() {}
