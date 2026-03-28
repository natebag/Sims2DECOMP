struct CTilePt {
    char x;
    char y;
    char z;
    CTilePt& operator=(CTilePt& other);
};

CTilePt& CTilePt::operator=(CTilePt& other) {
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}
