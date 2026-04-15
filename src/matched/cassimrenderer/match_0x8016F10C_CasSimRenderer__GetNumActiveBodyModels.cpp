/* CasSimRenderer::GetNumActiveBodyModels(void) - 0x8016F10C (48B) */

class CasSimRenderer {
public:
    char pad[112];
    int m_models[26];

    int GetNumActiveBodyModels(void);
};

int CasSimRenderer::GetNumActiveBodyModels(void) {
    int count = 0;
    int* p = m_models;
    for (int i = 0; i < 26; i++) {
        if (*p++ != 0) count++;
    }
    return count;
}
