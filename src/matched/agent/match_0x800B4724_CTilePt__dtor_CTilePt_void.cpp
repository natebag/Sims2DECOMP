void del_CTilePt__dtor_CTilePt_void(void*);
void CTilePt__dtor_CTilePt_void(void* self, int c) { if (c & 1) del_CTilePt__dtor_CTilePt_void(self); }
