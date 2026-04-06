// FLAGS: -fno-elide-constructors
// 0x800B8BF4 GoalUnlock::GetUnlockTotal (148b)
    virtual void V0();
    virtual void V1();
    virtual short V2(int type);
    virtual void V3();
    virtual int V4(int type, short idx);
};

int GetUnlockTotal_test(GoalBase* self, int type) {
    int count = 0;
    short i;
    for (i = 0; i < self->V2(type); i++) {
        if (self->V4(type, i)) {
            count++;
        }
    }
    return count;
}
