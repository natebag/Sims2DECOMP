// UrbzCreditsState::Shutdown - Uses SDA (r13 relative)

struct SomeGlobal {
    void Shutdown(int);
};

// Global at r13 - 26524 (0xFFFF9864)
extern SomeGlobal* g_pUrbzCreditsState;

void UrbzCreditsState_Shutdown() {
    g_pUrbzCreditsState->Shutdown(0);
}
