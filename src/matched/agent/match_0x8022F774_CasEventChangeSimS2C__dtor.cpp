// CasEventChangeSimS2C::~CasEventChangeSimS2C(void)
// Address: 0x8022F774 | Size: 36 bytes
// Thunk: calls internal with (this, 2), no saved regs

extern void CasEvent_dtor_base(void* self, int flag);

void CasEventChangeSimS2C_dtor(void* self) {
    CasEvent_dtor_base(self, 2);
}
