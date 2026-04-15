/* MUStatesAutoSaveExisting::Reset(void) - 0x80092988 (16 bytes) */

extern int g_MUStateCounter;

class MUStatesAutoSaveExisting {
public:
    char pad[32];
    int m_counter;

    void Reset(void);
};

void MUStatesAutoSaveExisting::Reset(void) {
    g_MUStateCounter = 0;
    m_counter = 0;
}
