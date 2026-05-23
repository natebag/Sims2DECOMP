// FLAGS: -fno-schedule-insns
/* 0x80233364 (4 bytes) - ERLevel::ValidateInstanceInLevel(EInstance*) */
struct EInstance;
struct ERLevel { void ValidateInstanceInLevel(EInstance*); };
void ERLevel::ValidateInstanceInLevel(EInstance*) {}
