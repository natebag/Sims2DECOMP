// 0x80119E50 ActionQueue::ActionQueue (96b)
// FLAGS: -fno-schedule-insns

extern void InitAction(void*);

struct ActionQueue {
    char actions[680];
    int field_2A8;
    int field_2AC;
    char field_2B0;
};

ActionQueue* ActionQueue_ctor(ActionQueue* self) {
    char* ptr = (char*)self;
    int count = 9;
    do {
        InitAction(ptr);
        ptr += 68;
    } while (count-- != 0);

    self->field_2A8 = 0;
    self->field_2B0 = 1;
    self->field_2AC = 0;
    return self;
}
