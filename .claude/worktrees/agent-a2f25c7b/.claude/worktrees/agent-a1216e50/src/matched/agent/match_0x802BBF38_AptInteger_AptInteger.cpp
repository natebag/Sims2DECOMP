extern int AptInteger_vtable[];
extern void AptValue_ctor_int(void *, int);

struct AptInteger {
    char pad[0x10];
    AptInteger(int val);
};

AptInteger::AptInteger(int val)
{
    AptValue_ctor_int(this, 7);
    *(int*)((char*)this + 0x0C) = val;
    *(int*)((char*)this + 0x08) = (int)AptInteger_vtable;
}
