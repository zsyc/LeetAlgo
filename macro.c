#define sh(x) printf("n" #x "=%d, or%d\n",n##x,alt[x])
#define sub_z 26
sh(sub_z);

#define x 3
#define f(a) f(x*(a))
#undef x
#define x 2
#define g f
#define t(a) a
t(t(g)(0)+t)(1)

/* Macro example, using "cpp macro.c" to see the ergebnis*/
