// COMPILER: mwcc
// 0x8024C608 OSSetAlarmTag (8B) — Dolphin SDK os/OSAlarm.c
//
// Stores a user tag word into the alarm's tag field (offset 4). MWCC GC-1.2.5n.

struct OSAlarm { void* handler; unsigned int tag; };

extern "C" void OSSetAlarmTag(OSAlarm* alarm, unsigned int tag) {
    alarm->tag = tag;
}
