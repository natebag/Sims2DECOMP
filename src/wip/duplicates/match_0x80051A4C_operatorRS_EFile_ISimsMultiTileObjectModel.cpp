struct EStorable;
struct EFile;
struct ISimsMultiTileObjectModel;

EFile& operator>>(EFile&, EStorable*&);

EFile& operator>>(EFile& file, ISimsMultiTileObjectModel*& obj) {
    EStorable* storable;
    operator>>(file, storable);
    obj = (ISimsMultiTileObjectModel*)storable;
    return file;
}
