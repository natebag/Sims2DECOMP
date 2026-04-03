struct ObjectDataID {
    int type;
    short id;
    ObjectDataID& operator=(ObjectDataID& other);
};

ObjectDataID& ObjectDataID::operator=(ObjectDataID& other) {
    type = other.type;
    id = other.id;
    return *this;
}
