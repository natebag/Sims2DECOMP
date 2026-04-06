// 0x800B8438 GoalUnlock::GoalUnlock (60b)
extern int g_vtable_GoalUnlock[8];
void GoalUnlock_init(void*);

void* GoalUnlock_ctor(void* self) {
    *(void**)self = (void*)g_vtable_GoalUnlock;
    GoalUnlock_init(self);
    return self;
}
