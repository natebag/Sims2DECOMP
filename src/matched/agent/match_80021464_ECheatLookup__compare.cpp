/* ECheatLookup::compare(char *) const at 0x80021464 (52B) */

extern int strcmp(const char*, const char*);

struct ECheatLookup {
    char pad[8];
    char m_name[1];
    int compare(char* str) const;
};

int ECheatLookup::compare(char* str) const {
    return strcmp(str, m_name) == 0;
}
