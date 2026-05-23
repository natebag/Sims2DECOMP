// FLAGS: -fno-schedule-insns
/* 0x802296F8 (4 bytes) - EInstance::AddedToLevel(ERLevel*) */
struct ERLevel;
struct EInstance { void AddedToLevel(ERLevel*); };
void EInstance::AddedToLevel(ERLevel*) {}
