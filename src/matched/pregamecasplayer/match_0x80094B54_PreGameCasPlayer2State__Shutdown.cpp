/* PreGameCasPlayer2State::Shutdown(void) - 0x80094B54 (20 bytes) */

extern char g_PreGameCasPlayer2State[100];

class PreGameCasPlayer2State {
public:
    char pad[940];
    int m_field_940;

    static void Shutdown(void);
};

void PreGameCasPlayer2State::Shutdown(void) {
    PreGameCasPlayer2State* self = *(PreGameCasPlayer2State**)g_PreGameCasPlayer2State;
    self->m_field_940 = -1;
}
