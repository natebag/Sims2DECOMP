struct CTilePt {
    char x;
    char y;
    CTilePt& operator*=(int n);
};

CTilePt& CTilePt::operator*=(int n) {
    x = (char)((int)x * n);
    y = (char)((int)y * n);
    return *this;
}
