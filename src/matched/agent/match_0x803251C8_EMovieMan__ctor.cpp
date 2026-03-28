/* EMovieMan::EMovieMan at 0x803251C8 (68 bytes) */

extern int EMovieMan_vtable[];

void BaseInit_Stream(void*);

struct EMovieMan {
    char _pad_00[0x54];
    int m_field_54;
    char _pad_58[0xCC4];
    int* _vtable_D1C;

    EMovieMan();
};

EMovieMan::EMovieMan()
{
    BaseInit_Stream(this);
    m_field_54 = 1;
    _vtable_D1C = EMovieMan_vtable;
}
