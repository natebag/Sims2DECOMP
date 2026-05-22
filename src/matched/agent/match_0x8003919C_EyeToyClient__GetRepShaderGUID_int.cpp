// 0x8003919C EyeToyClient::GetRepShaderGUID(int) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mulli 3,3,12; lis 9,-32702; addi 9,9,15808; lwzx 11,9,3; lwz 3,0x0(11)"
extern "C" int f_8003919C() {}
