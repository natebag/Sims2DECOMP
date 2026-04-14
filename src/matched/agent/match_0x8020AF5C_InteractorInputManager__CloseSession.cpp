// 0x8020AF5C InteractorModule::InteractorInputManager::CloseSession(int) (44B)
struct Session {
    char data[32];
};

struct InteractorInputManager {
    Session* m_sessions;
};

extern void InteractorInputManager__CloseSessionImpl(Session* sess);

void InteractorInputManager__CloseSession(InteractorInputManager* self, int playerId) {
    InteractorInputManager__CloseSessionImpl(&self->m_sessions[playerId]);
}
