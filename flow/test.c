#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "flow.h"

int main()
{
    arrKata *dict, a, b, c, d, e, f, g, h, i, j, k, l, key;
    int n = 2, printed;
    time_t t;
    
    //set seed utk random
    srand((unsigned) time(&t));
    //Saya mahasiswa ITB yang rajin. Saya mahasiswa ITB yang malas. Oleh sebab itu saya belajar. Saya mahasiswa

    initializeArrKata(&a);
    initializeArrKata(&b);
    initializeArrKata(&c);
    initializeArrKata(&d);
    initializeArrKata(&e);
    initializeArrKata(&f);
    initializeArrKata(&g);
    initializeArrKata(&h);
    initializeArrKata(&i);
    initializeArrKata(&j);
    initializeArrKata(&k);
    initializeArrKata(&l);
    pushArrKata(&a, "Saya");
    pushArrKata(&a, "mahasiswa");
    pushArrKata(&a, "ITB");
    pushArrKata(&b, "mahasiswa");
    pushArrKata(&b, "ITB");
    pushArrKata(&b, "yang");
    pushArrKata(&c, "ITB");
    pushArrKata(&c, "yang");
    pushArrKata(&c, "rajin.");
    pushArrKata(&c, "malas.");
    pushArrKata(&d, "yang");
    pushArrKata(&d, "rajin.");
    pushArrKata(&d, "Saya");
    pushArrKata(&e, "rajin.");
    pushArrKata(&e, "Saya");
    pushArrKata(&e, "mahasiswa");
    pushArrKata(&f, "yang");
    pushArrKata(&f, "malas.");
    pushArrKata(&f, "Oleh");
    pushArrKata(&g, "malas.");
    pushArrKata(&g, "Oleh");
    pushArrKata(&g, "sebab");
    pushArrKata(&h, "Oleh");
    pushArrKata(&h, "sebab");
    pushArrKata(&h, "itu");
    pushArrKata(&i, "sebab");
    pushArrKata(&i, "itu");
    pushArrKata(&i, "saya");
    pushArrKata(&j, "itu");
    pushArrKata(&j, "saya");
    pushArrKata(&j, "belajar.");
    pushArrKata(&k, "saya");
    pushArrKata(&k, "belajar.");
    pushArrKata(&k, "Saya");
    pushArrKata(&l, "belajar.");
    pushArrKata(&l, "Saya");
    pushArrKata(&l, "mahasiswa");
    
    k.next = &l;
    j.next = &k;
    i.next = &j;
    h.next = &i;
    g.next = &h;
    f.next = &g;
    e.next = &f;
    d.next = &e;
    c.next = &d;
    b.next = &c;
    a.next = &b;
    dict = &a;

    key = getRandomKey(dict, 2);
    Flow(key, dict, 2, 3, 200);

    return 0;
}