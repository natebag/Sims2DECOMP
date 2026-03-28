
int ObjectDataID_InternalCompare(void *, void *);

struct ObjectDataID {
    int operator==(ObjectDataID& other) const;
};

int ObjectDataID::operator==(ObjectDataID& other) const {
    return ObjectDataID_InternalCompare((void*)this, &other);
}
