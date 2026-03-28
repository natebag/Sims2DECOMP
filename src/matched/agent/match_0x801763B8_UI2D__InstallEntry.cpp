/* UI2D::InstallEntry at 0x801763B8 (132b) */

struct UI2DRecord;
struct ERShader;

struct UI2D {
    int m_pad00;
    int m_pad04;
    int m_count;

    int InstallEntry(char* name, unsigned int id, char* texname, int param);
    int AddEntry(char* name, unsigned int id, ERShader* shader, char* texname, int param);
    UI2DRecord* FindEntry(char* name);
    void RemoveEntry(UI2DRecord* rec);
};

int UI2D::InstallEntry(char* name, unsigned int id, char* texname, int param) {
    if (m_count != 0) {
        UI2DRecord* existing = FindEntry(name);
        if (existing != 0) {
            RemoveEntry(existing);
        }
        AddEntry(name, id, (ERShader*)0, texname, param);
        return 1;
    }
    return 0;
}
