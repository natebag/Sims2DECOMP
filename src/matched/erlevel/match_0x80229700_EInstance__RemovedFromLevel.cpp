// FLAGS: -fno-schedule-insns
/* 0x80229700 (4 bytes) - EInstance::RemovedFromLevel(ERLevel*) */
struct ERLevel;
struct EInstance { void RemovedFromLevel(ERLevel*); };
void EInstance::RemovedFromLevel(ERLevel*) {}
