struct EAStringData { char hdr[8]; char buf[1]; };
struct EAStringC { EAStringData* m_data; };
extern "C" int strcmp_impl(char*, char*);
int EAStringC__Equal_char_ptr(EAStringC* self, char* str) {
    return strcmp_impl(self->m_data->buf, str) == 0;
}
