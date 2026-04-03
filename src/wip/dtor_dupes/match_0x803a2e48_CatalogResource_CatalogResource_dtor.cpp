extern int VT_CatalogResource_CatalogResource[];
void del_CatalogResource_CatalogResource(void *);
void dtor_CatalogResource_CatalogResource(char *self, int __in_chrg) {
    *(int **)self = VT_CatalogResource_CatalogResource;
    if (__in_chrg & 1) {
        del_CatalogResource_CatalogResource(self);
    }
}
