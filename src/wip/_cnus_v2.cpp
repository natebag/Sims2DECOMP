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
    m_counter++;
    ObjectFolderImpl* folder = LookupByCounter(this, x, m_counter);
    folder->m_sel = new UserSelector();
    return folder;
}
