/* GetLocalizableCommandTable::InstallCommand at 0x80178968 (132b) */

extern int strcmp(const char*, const char*);

struct CBFunctor1wRet_char_ptr_wchar_ptr {
    char data[8];
};

struct LocCommandNode {
    void* m_prev;
    LocCommandNode* m_next;
    char* m_name;
    CBFunctor1wRet_char_ptr_wchar_ptr m_functor;
};

struct GetLocalizableCommandTable {
    LocCommandNode* m_head;
    int m_pad04;
    int m_count;

    int InstallCommand(char* name, CBFunctor1wRet_char_ptr_wchar_ptr& functor);
    void AddNode(char* name, CBFunctor1wRet_char_ptr_wchar_ptr& functor);
};

int GetLocalizableCommandTable::InstallCommand(char* name, CBFunctor1wRet_char_ptr_wchar_ptr& functor) {
    if (m_count != 0) {
        LocCommandNode* node = m_head;
        while (node != 0) {
            if (strcmp(node->m_name, name) == 0) {
                return 0;
            }
            node = node->m_next;
        }
        AddNode(name, functor);
        return 1;
    }
    return 0;
}
