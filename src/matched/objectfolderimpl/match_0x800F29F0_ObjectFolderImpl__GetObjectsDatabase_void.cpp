// 0x800F29F0 ObjectFolderImpl::GetObjectsDatabase(void) (8 B)
struct ObjectFolderImpl { char _pad[0x690]; unsigned m_objectsDatabase; unsigned GetObjectsDatabase(); };
unsigned ObjectFolderImpl::GetObjectsDatabase() { return m_objectsDatabase; }
