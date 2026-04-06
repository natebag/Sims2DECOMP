// 0x801410EC cSimulatorImpl::SetSpeed (72b)

extern void cSimulatorImpl_UpdateSpeed(void*);
extern void GlobalDispatch(short, int);
extern float g_speedFloat[];

struct cSimulatorImpl {
    char pad[0x34];
    short speed;
    char pad2[0x6A];
    float speedMul;
};

void cSimulatorImpl_SetSpeed(cSimulatorImpl* self, short spd) {
    self->speed = spd;
    cSimulatorImpl_UpdateSpeed(self);
    self->speedMul = *g_speedFloat;
    GlobalDispatch(189, 0);
}
