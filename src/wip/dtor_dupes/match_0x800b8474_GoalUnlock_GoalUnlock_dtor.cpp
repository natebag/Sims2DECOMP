extern int VT_GoalUnlock_GoalUnlock[];
void del_GoalUnlock_GoalUnlock(void *);
void dtor_GoalUnlock_GoalUnlock(char *self, int __in_chrg) {
    *(int **)self = VT_GoalUnlock_GoalUnlock;
    if (__in_chrg & 1) {
        del_GoalUnlock_GoalUnlock(self);
    }
}
