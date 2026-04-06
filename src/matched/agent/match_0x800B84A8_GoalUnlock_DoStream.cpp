// FLAGS: -fno-elide-constructors
// 0x800B84A8 GoalUnlock::DoStream (104b)
    virtual void VFunc1();
    virtual void VFunc2();
};

void readStream(void* buf, void* data, int count);

void GoalUnlock_DoStream(GoalBase* self, void* buf, int mode) {
    if (mode <= 16) {
        readStream(buf, (char*)self + 4, 39);
        self->VFunc2();
    } else {
        readStream(buf, (char*)self + 4, 64);
    }
}
