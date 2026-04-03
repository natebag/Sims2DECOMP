extern int VT_CatalogResourceImpl_CatalogResourceImpl[];
void del_CatalogResourceImpl_CatalogResourceImpl(void *);
void dtor_CatalogResourceImpl_CatalogResourceImpl(char *self, int __in_chrg) {
    *(int **)self = VT_CatalogResourceImpl_CatalogResourceImpl;
    if (__in_chrg & 1) {
        del_CatalogResourceImpl_CatalogResourceImpl(self);
    }
}
