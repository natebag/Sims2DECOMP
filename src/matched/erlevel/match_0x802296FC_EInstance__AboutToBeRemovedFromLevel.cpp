// FLAGS: -fno-schedule-insns
/* 0x802296FC (4 bytes) - EInstance::AboutToBeRemovedFromLevel(ERLevel*) */
struct ERLevel;
struct EInstance { void AboutToBeRemovedFromLevel(ERLevel*); };
void EInstance::AboutToBeRemovedFromLevel(ERLevel*) {}
