// 0x8013E624 LogInteractionSample::LogInteractionSample (72b)
// FLAGS: -fno-schedule-insns

struct LogInteractionSample {
    char pad[0x28];
    int field28;
    int field2C;
    int field30;
    int field34;
};

extern void BaseInit(LogInteractionSample*, int);

LogInteractionSample* LogInteractionSample_ctor(LogInteractionSample* self) {
    BaseInit(self, 0);
    self->field34 = 0;
    self->field28 = 0;
    self->field2C = 0;
    self->field30 = 0;
    return self;
}
