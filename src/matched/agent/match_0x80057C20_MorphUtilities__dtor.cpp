struct MorphUtilities {
    int* m_vtable;

    ~MorphUtilities();
};

MorphUtilities::~MorphUtilities() {
    m_vtable = 0;
}
