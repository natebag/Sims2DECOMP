void handleMemoryAwarenessAnim(void*);
void handleOtherAwareness(void*);
void handleAwarenessWithParam(void*, unsigned int);

void AM_handleAwarenessAnimations(void* self, unsigned int param) {
    handleMemoryAwarenessAnim(self);
    handleOtherAwareness(self);
    handleAwarenessWithParam(self, param);
}
