// 0x80039178 EyeToyClient::DoesRepSlotHaveEyetoyImage(int) (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mulli 3,3,12; lis 9,-32702; addi 9,9,15808; addi 9,9,8; lwzx 3,9,3; xori 3,3,1; subfic 0,3,0; adde 3,0,3"
extern "C" int f_80039178() {}
