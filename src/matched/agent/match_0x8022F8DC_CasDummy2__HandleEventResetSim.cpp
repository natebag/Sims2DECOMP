// {anonymous}::CasDummy2::HandleEventResetSim(CasEventResetSim &)
// Address: 0x8022F8DC | Size: 48 bytes

extern void* HandleResetSim_func1(void* self);
extern void HandleResetSim_func2(void* a, void* b);

void CasDummy2_HandleEventResetSim(void* self) {
    void* r = HandleResetSim_func1(self);
    HandleResetSim_func2(r, self);
}
