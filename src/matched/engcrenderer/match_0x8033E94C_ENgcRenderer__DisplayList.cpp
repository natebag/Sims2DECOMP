// 0x8033E94C ENgcRenderer::DisplayList(ENgcRendCommand *) (96B)
// Pattern: cache cmd->m_field_8 != 0 as flag (1/0), execute the EDL entry via field_4+72,
// then conditionally call g_graphics->DeallocateDL.

struct ENgcRendCommand {
    char pad[4];
    char* m_field_4;
    int m_field_8;
};

class EDLEntry;
class EDL;

class EGraphics {
public:
    void DeallocateDL(EDL* dl, int mode);
};

extern EGraphics* g_graphics;   // SDA at r13-26392

class ENgcRenderer {
public:
    void DisplayList(ENgcRendCommand* cmd);
    void Execute(EDLEntry* entry);
};

void ENgcRenderer::DisplayList(ENgcRendCommand* cmd) {
    int flag = 1;
    if (cmd->m_field_8 == 0) flag = 0;
    EDLEntry* entry = *(EDLEntry**)(cmd->m_field_4 + 72);
    Execute(entry);
    if (flag != 0) {
        g_graphics->DeallocateDL((EDL*)cmd->m_field_4, 0);
    }
}
