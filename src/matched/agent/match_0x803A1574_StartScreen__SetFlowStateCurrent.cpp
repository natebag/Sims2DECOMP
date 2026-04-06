struct Inner { char pad[8]; void* state; };
struct StartScreenStartState { char pad[8]; Inner* m_inner; };
extern "C" void* stateFunc(void*);

void* StartScreen_SetFlowStateCurrent(StartScreenStartState* self) {
    return stateFunc(self->m_inner->state);
}
