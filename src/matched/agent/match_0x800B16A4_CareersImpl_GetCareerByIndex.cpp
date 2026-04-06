// FLAGS: -msdata=eabi -G 8
// 0x800B16A4 CareersImpl::GetCareerByIndex (20b)
struct Career { char data[20]; };
struct Container { int pad; Career* careers; };
struct CareersImpl { int vtable; int pad; Container* container; };

Career* CareersImpl_GetCareerByIndex(CareersImpl* self, int index) {
    return &self->container->careers[index];
}
