void del_EGlobal__dtor_EGlobal_void(void*);
void EGlobal__dtor_EGlobal_void(void* self, int c) { if (c & 1) del_EGlobal__dtor_EGlobal_void(self); }
