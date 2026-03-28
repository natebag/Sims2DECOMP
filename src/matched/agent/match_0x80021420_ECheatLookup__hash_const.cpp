int HashString(char* str);

struct ECheatLookup {
    char pad[8];
    char m_name;
};

int ECheatLookup_hash(ECheatLookup* self) {
    return HashString(&self->m_name);
}
