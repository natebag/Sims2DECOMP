struct AptTextFormat {
    void* operator new[](unsigned int size);
};

void* AptTextFormat::operator new[](unsigned int size) {
    return 0;
}
