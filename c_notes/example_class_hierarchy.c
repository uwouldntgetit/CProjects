// basic class structure and instance structure
struct _GTypeClass{
    GType g_type;
};

struct _GTypeInstance{
    GTypeClass *g_class;
};

// definition of A
typedef struct{
    GTypeInstance parent;
    int field_a;
    int field_b;
}A;

typedef struct{
    GTypeClass parent_class;
    void (*method_a) (void);
    void (*method_b) (void);
}A_class;

// definition of B
typedef struct{
    A parent;
    int field_c;
    int field_d;
}B;

typedef struct{
    A_class parent_class;
    void (*method_c) (void);
    void (*method_d) (void);
}B_class;

// it is possible to detect the type of every object instance by doing this:
// B *b;
// b->parent.parent.g_class->g_type
// or more compactly:
// ((GTypeInstance *) b)->g_class->g_type

