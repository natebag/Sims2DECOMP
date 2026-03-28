// 0x8015BA4C (8 bytes)
// ObjectDataFactoryIFF<StringSet>::operator()(void) const
// li r3, 0; blr
class StringSet;

template<typename T>
class ObjectDataFactoryIFF {
public:
    T* operator()() const;
};

template<>
StringSet* ObjectDataFactoryIFF<StringSet>::operator()() const {
    return 0;
}
