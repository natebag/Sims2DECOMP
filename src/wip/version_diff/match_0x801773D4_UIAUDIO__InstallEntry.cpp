/* UIAUDIO::InstallEntry at 0x801773D4 (168b) */

extern int strcmp(const char*, const char*);

struct UIAudioRecord;

struct UIAUDIO {
    UIAudioRecord* m_head;
    int m_pad04;
    int m_count;

    int InstallEntry(char* name, unsigned int id, char* sndname);
    void AddEntry(char* name, unsigned int id, char* sndname);
    void RemoveEntry(UIAudioRecord* rec);
};

struct UIAudioRecord {
    void* m_prev;
    UIAudioRecord* m_next;
    char* m_name;
};

int UIAUDIO::InstallEntry(char* name, unsigned int id, char* sndname) {
    if (m_count != 0) {
        UIAudioRecord* node = m_head;
        int found = 0;
        while (node != 0) {
            if (strcmp(node->m_name, name) == 0) {
                RemoveEntry(node);
                found = 1;
            }
            node = node->m_next;
            if (node == 0) break;
            if (found == 0) continue;
            break;
        }
        AddEntry(name, id, sndname);
        return 1;
    }
    return 0;
}
