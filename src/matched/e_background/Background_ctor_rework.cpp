// 0x802E1BFC Background::Background (20b)

extern int Background_vtable[];

struct Background {
    int* m_vt;
    
    Background();
};

Background::Background() {
    *(int**)this = Background_vtable;
}
