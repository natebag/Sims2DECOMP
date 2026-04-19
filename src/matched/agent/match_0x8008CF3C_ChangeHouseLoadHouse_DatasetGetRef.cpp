// 0x8008CF3C (88B) ChangeHouseLoadHouse::DatasetGetRef()
// Call _datasetman.GetRef(handle); normalize result to 0/1; if nonzero, clear handle.

class EDatasetManager {
public:
    int GetRef(unsigned int);
};
extern char _datasetman[0xd24];

class ChangeHouseLoadHouse {
public:
    char pad[0x1c];
    unsigned int handle;
    int DatasetGetRef();
};

int ChangeHouseLoadHouse::DatasetGetRef() {
    int ok = ((EDatasetManager*)_datasetman)->GetRef(this->handle) ? 1 : 0;
    if (ok) {
        this->handle = 0;
    }
    return ok;
}
