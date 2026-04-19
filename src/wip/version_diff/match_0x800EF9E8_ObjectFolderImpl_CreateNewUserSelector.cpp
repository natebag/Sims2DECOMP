// 0x800EF9E8 (76B) ObjectFolderImpl::CreateNewUserSelector(void)

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
