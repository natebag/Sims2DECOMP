struct ERLevel {
    unsigned int FindInstance(unsigned int id);
    unsigned int FindInstance(char* name);
};

unsigned int HashString(char* str, int param);

unsigned int ERLevel::FindInstance(char* name) {
    unsigned int id = HashString(name, 0);
    return FindInstance(id);
}
