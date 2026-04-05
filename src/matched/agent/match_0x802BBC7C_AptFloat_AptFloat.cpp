extern int AptFloat_vtable[];
extern void AptValue_ctor(void *, int);

struct AptFloat {
    char pad[0x10];
    float m_val;
    AptFloat(float val);
};

AptFloat::AptFloat(float val)
{
    AptValue_ctor(this, 6);
    *(float*)((char*)this + 0x0C) = val;
    *(int*)((char*)this + 0x08) = (int)AptFloat_vtable;
}
