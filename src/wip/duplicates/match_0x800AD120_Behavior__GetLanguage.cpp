/* Behavior::GetLanguage(void) at 0x800AD120 (8B) */

struct Behavior {
    char pad[0x08];
    int m_language;

    int GetLanguage(void);
};

int Behavior::GetLanguage(void) {
    return m_language;
}
