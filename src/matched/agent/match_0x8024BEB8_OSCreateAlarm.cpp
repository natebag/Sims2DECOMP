// FLAGS: -fno-schedule-insns
// 0x8024BEB8 OSCreateAlarm (16B)
// li r0,0; stw r0,0x0(r3); stw r0,0x4(r3); blr
struct OSAlarm { int m_tag; int m_unused; };
void OSCreateAlarm(OSAlarm* alarm) {
    alarm->m_tag = 0;
    alarm->m_unused = 0;
}
