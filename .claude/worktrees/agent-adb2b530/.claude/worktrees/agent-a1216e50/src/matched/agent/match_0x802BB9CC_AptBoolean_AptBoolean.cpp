extern int AptBoolean_vtable[];
extern void AptValue_ctor(void *, int);

struct AptBoolean {
    char pad[0x10];
    AptBoolean(int val);
};

AptBoolean::AptBoolean(int val)
{
    AptValue_ctor(this, 5);
    *(int*)((char*)this + 0x0C) = val;
    *(int*)((char*)this + 0x08) = (int)AptBoolean_vtable;
}
