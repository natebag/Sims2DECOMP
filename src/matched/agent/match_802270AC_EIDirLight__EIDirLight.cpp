extern int EIDirLight_vtable[];

void EILight_ctor(void*);

struct EVec3 {
    float x, y, z;
};

struct EIDirLight {
    char pad_00[0xAC];
    EVec3 m_direction;

    EIDirLight();
};

EIDirLight::EIDirLight() {
    EILight_ctor(this);
    *(int**)this = EIDirLight_vtable;
    EVec3* dir = &m_direction;
    dir->x = 0.0f;
    dir->y = 0.0f;
    dir->z = -1.0f;
}
