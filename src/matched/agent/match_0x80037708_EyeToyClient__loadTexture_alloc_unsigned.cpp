// 0x80037708 EyeToyClient::loadTexture_alloc(unsigned (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-25032(13)"
extern "C" int f_80037708() {}
