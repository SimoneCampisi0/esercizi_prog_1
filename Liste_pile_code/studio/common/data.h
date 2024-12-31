#ifndef DATA_H
    #define DATA_H
    struct Dato {
        int value;
    };

    /* Impostando i parametri passati come const struct Dato *d, si rende immutabile
    il valore puntato dall'indirizzo di memoria del puntatore.
    Si può tuttavia modificare l'indirizzo di memoria puntato */


    /*
    return 0 - se i dati sono uguali
    -1 se ((*d1).value < (*d2).value)
    1 se ((*d1).value > (*d2).value)
    */
    int confrontaDati(const struct Dato *d1, const struct Dato *d2);

    /* Stampa il dato contenuto in d */
    void printDato(const struct Dato *d);

    /* Dealloca eventuali dati allocati dinamicamente */
    void freeData(const struct Dato *d);

    /* Copia valore da src a dst */
    void copyData(const struct Dato *src, struct Dato *dst);

#endif