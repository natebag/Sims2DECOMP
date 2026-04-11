void del_CTGDump__dtor_CTGDump_void(void*);
void CTGDump__dtor_CTGDump_void(void* self, int c) { if (c & 1) del_CTGDump__dtor_CTGDump_void(self); }
