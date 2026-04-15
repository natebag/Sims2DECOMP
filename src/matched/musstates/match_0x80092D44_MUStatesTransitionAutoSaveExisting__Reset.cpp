/* MUStatesTransitionAutoSaveExisting::Reset(void) - 0x80092D44 (16 bytes) */

extern int g_MUStateCounter;

class MUStatesTransitionAutoSaveExisting {
public:
    char pad[32];
    int m_counter;

    void Reset(void);
};

void MUStatesTransitionAutoSaveExisting::Reset(void) {
    g_MUStateCounter = 0;
    m_counter = 0;
}
