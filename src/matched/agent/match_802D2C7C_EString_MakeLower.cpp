void strlwr_fn(char*);

struct EString_ML {
    char* m_buf;
    EString_ML* MakeLower();
};

EString_ML* EString_ML::MakeLower() {
    strlwr_fn(m_buf);
    return this;
}
