/* GetVariableCommandTable::InstallCommand at 0x80177FDC (132b) */

extern int strcmp(const char*, const char*);

struct CBFunctor1wRet_char_ptr_char_ptr {
    char data[8];
};

struct CommandNode {
    void* m_prev;
    CommandNode* m_next;
    char* m_name;
    CBFunctor1wRet_char_ptr_char_ptr m_functor;
};

struct GetVariableCommandTable {
    CommandNode* m_head;
    int m_pad04;
    int m_count;

    int InstallCommand(char* name, CBFunctor1wRet_char_ptr_char_ptr& functor);
    void AddNode(char* name, CBFunctor1wRet_char_ptr_char_ptr& functor);
};

int GetVariableCommandTable::InstallCommand(char* name, CBFunctor1wRet_char_ptr_char_ptr& functor) {
    if (m_count != 0) {
        CommandNode* node = m_head;
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
