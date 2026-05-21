// 0x800EF9E8 ObjectFolderImpl::CreateNewUserSelector(void) (76B)
// ASMPROC_swap_adj: a="extsh" b="sth" which=0
// ASMPROC_replace_insn: match="extsh 9,9" replacement="extsh 5,9"
// ASMPROC_remove_mr: match="mr 5,9" assert_op=""

struct UserSelector { char data[292]; UserSelector(); };

struct ObjectFolderImpl {
    char pad[140];
    UserSelector* m_sel;
    char pad2[1580];
    unsigned short m_counter;
    ObjectFolderImpl* CreateNewUserSelector();
};

extern int GenerateId();
extern ObjectFolderImpl* LookupByCounter(ObjectFolderImpl*, int, short);

ObjectFolderImpl* ObjectFolderImpl::CreateNewUserSelector() {
    int x = GenerateId();
    short c = (short)(m_counter + 1);
    m_counter = c;
    ObjectFolderImpl* folder = LookupByCounter(this, x, c);
    folder->m_sel = new UserSelector();
    return folder;
}
