
#define HASH_ID 5863474
#define HASH_SID 193505797
#define UNDEFINED_INDEX 0xFFFFFFFF
#define MAX_STATE_PROPERTIES 128
#define UNDEFINED_HASH_OFFSET 0xFFFFFFFF

typedef struct jsonProperty {
    unsigned int hash;
    unsigned char type;
    char *firstValue;
    char *lastValue;
    unsigned char isMaterial;
    union { 
        long i; 
        double d; 
        unsigned char b; 
    } value;
} jsonProperty;

typedef struct stateEntry {
    unsigned int nextHashOffset;
    unsigned int nextLruOffset;
    unsigned int prevLruOffset;
    unsigned int sidHash;
    unsigned int bindingIndex;
    unsigned int lastRefresh;
    unsigned int propertiesLength;
    jsonProperty properties[MAX_STATE_PROPERTIES];
    char *state;
    char *sid;
} stateEntry;

void rehydrateProperty(jsonProperty *property);
unsigned int refreshState(void *tree, char *sid);
unsigned int constructObject(char *parentName, 
                             char *object,
                             char createHashtable,
                             unsigned int maxProperties,
                             jsonProperty *properties, 
                             unsigned int *propertiesLength, 
                             unsigned int *midIndex, 
                             unsigned int *sidIndex,
                             char **next);
unsigned int resolveBinding(void *tree, 
                            char *sid, 
                            void **rulesBinding);
unsigned int fetchStateProperty(void *tree,
                                      char *sid, 
                                      unsigned int propertyHash, 
                                      unsigned int maxTime, 
                                      unsigned char ignoreStaleState,
                                      jsonProperty **property);
