// 0x80214100 InteractorModule::InteractorVisualizer::PreDraw(InteractorModule::FloorPainter &) (76B)

struct EOrderTableData;

struct EHouse {
    void InsertHouseObject(EOrderTableData* data);
};

struct OrderTableData;
struct Interactor;
struct FloorPainter;
struct InteractorResourceSet;

extern char g_pHouse[16];
extern InteractorResourceSet* GetInteractorResourceSet(Interactor*);
extern OrderTableData* GetOrderTableData(InteractorResourceSet*, unsigned int);

struct InteractorVisualizer {
    void PreDraw(FloorPainter& fp);
};

void InteractorVisualizer::PreDraw(FloorPainter& fp) {
    InteractorResourceSet* rs = GetInteractorResourceSet((Interactor*)this);
    OrderTableData* data = GetOrderTableData(rs, 0);
    *(int*)((char*)data + 24) = *(int*)((char*)&fp + 0);
    (*(EHouse**)g_pHouse)->InsertHouseObject((EOrderTableData*)data);
}
