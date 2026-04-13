// cXObjectImpl::IsInWorld(void)
// Address: 0x800DCB50 | Size: 40 bytes

struct cXObjectImpl {
    char pad[104];
    int field_104;
    int field_108;
    int IsInWorld();
};

int cXObjectImpl::IsInWorld() {
    if ((this->field_108 >> 4) <= 0) goto ret0;
    if ((this->field_104 >> 4) > 0) goto ret1;
ret0:
    return 0;
ret1:
    return 1;
}
