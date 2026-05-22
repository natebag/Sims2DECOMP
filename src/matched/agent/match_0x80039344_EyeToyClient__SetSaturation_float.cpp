// 0x80039344 EyeToyClient::SetSaturation(float) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 4,-32697; fadds f1,f1,f1; addi 4,4,23136; li 3,0; stfs f1,0x1c(4); bl _s80039344_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80039344_0();
extern "C" void f_80039344() {}
