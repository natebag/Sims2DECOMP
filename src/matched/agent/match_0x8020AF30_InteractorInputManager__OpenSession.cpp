// 0x8020AF30 InteractorModule::InteractorInputManager::OpenSession(...) (44B)
struct Session {
    char data[32];
};

struct InteractorInputManager {
    Session* m_sessions;
};

struct Interactor;
struct ButtonSemantic;
struct StickSemantic;

extern void InteractorInputManager__OpenSessionImpl(Session* sess, int playerId, Interactor* i, int a,
                                                    ButtonSemantic* b, int c, StickSemantic* s, char* d);

void InteractorInputManager__OpenSession(InteractorInputManager* self, int playerId, Interactor* i, int a,
                                         ButtonSemantic* b, int c, StickSemantic* s, char* d) {
    InteractorInputManager__OpenSessionImpl(&self->m_sessions[playerId], playerId, i, a, b, c, s, d);
}
