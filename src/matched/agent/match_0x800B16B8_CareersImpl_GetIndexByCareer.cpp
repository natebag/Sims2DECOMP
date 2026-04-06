// FLAGS: -msdata=eabi -G 8
// 0x800B16B8 CareersImpl::GetIndexByCareer (32b)
struct Career { char data[20]; };
struct Container { int pad; Career* careers; };
struct CareersImpl { int vtable; int pad; Container* container; };

int CareersImpl_GetIndexByCareer(CareersImpl* self, Career* career) {
    return career - self->container->careers;
}
