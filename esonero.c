// programma per cifrare una stringa tramite XOR
#include <stdio.h>   //intestazioni
#include <time.h> //va inclusa per usare time_t
#include <string.h> //va inclusa per trattare le stringhe
#include <stdlib.h> //va inclusa per usare srand e rand

char m[129]; //m è la stringa da cifrare inserita dall'utente
char k[129]; //k è la chiave per cifrare la stringa inserita dall'utente
char c[129]; //c è la stringa cifrata
int a; //a è la scelta che l'utente effettuerà per cifrare la sua stringa m

int main()
{
  printf("Inserire una stringa di testo da cifrare, di massimo 128 caratteri.\n");
  printf("Se vengono inseriti pù caratteri di quelli richiesti, non sarà possibile continuare.\n\n");

  printf("Inserire stringa di testo: %s\n", m);
  fgets(m, 128, stdin); //prende la stringa inserita da tastiera
  fflush(stdin); //pulisce lo stdin
  printf("La stringa inserita è: %s\n", m);
  printf("La stringa inserita contiene %lu caratteri\n\n", strlen(m)-1);
// spiegazione su come procedere con la cifratura della stringa m, tramite una chiave k inserita o manualmente, o generata casualmente
  printf("Scegliere come si desidera procedere per cifare la stringa inserita: \n");
  printf(" 1) Digitando 1 verrà richiesto di inserire manualmente una chiave (stringa), con la quale verrà cifrata quella precedentemente inserita. \n\n");
  printf(" 2) Digitando 2 verrà generata una chiave (stringa) casuale, con la quale verrà cifrata quella precedentemente inserita. \n");

  scanf("%d", &a); //selezione della scelta effettuata dall'utente
  printf("Hai selezionato: %d\n\n", a);
//se la scelta dell'utente è 1, verrà eseguito questo if
  if (a == 1) {
    while(getchar() != '\n'); //pulisce il buffer
    printf("Inserire una chiave con la quale si intende cifrare %s \n", m);
    printf("La chiave da inserire deve contenere almeno %lu caratteri, ma non più di 128.\n", strlen(m)-1);
    printf("Inserire la chiave:\n");
    fgets(k, 128, stdin);//prende la chiave k da tastiera
    fflush(stdin);
    printf("La chiave inserita per cifrare %s è: %s \n", m, k);
//la lunghezza della chiave deve essere maggiore o uguale di quella della stringa
    if (strlen(k) < strlen(m)) {
      printf("Inserire una stringa che contenga almeno %lu caratteri\n", strlen(m)-1);
    } //fine if lunghezza k < lunghezza m
//se la lunghezza di k è maggiore o uguale alla lunghezza di m, si avvia la cifratura
    if (strlen(k) >= strlen(m)) {
      for ( int i = 0; i < strlen(m) ; i++) {
          c[i] = m[i] ^ k[i]; //cifratura di m con k tramite l'operatore XOR
          m[i] = c[i] ^ k[i]; //decifratura di c con k tramite XOR, per riottenere m
     }//fine for
     printf("La stringa cifrata in esadecimale è: ");
     for (int j = 0; j < strlen(m) ; j++) {
       printf("%x", c[j]); // stampa la stringa cifrata in esadecimale
     }//fine for
            printf("\nLa stringa decifrata è: %s\n", m);
       }//fine if lunghezza k >= lunghezza m
     }//fine if a == 1
//Se l'utente sceglie 2, viene eseguito questo if
if (a == 2) {
  while(getchar() != '\n');
  time_t t;                         // restituisce il numero di secondi trascorsi dalla mezzanotte del 01/01/1970;
  srand((unsigned) time(&t));       //il suo valore (unsigned int), serve a creare un seme per generare numerri casuali.

  for (int i = 0 ; i <= strlen(m)-1; ++i) {
    k[i] = (33 + rand() %96); //la chiave viene scritta utilizzando i caratteri della tabella ASCII, escludendo quelli speciali
    for (int j = 0; j <= strlen(m)-1; j++) {
      c[j] = m[j] ^ k[j]; //cifratura
      m[j] = c[j] ^ k[j]; //decifratura
    }//fine for
}//fine for
printf("La chiave generata è: %s\n\n", k);
printf("La stringa cifrata in esadecimale è: ");
for (int k = 0; k < strlen(m) ; k++) {
  printf("%x", c[k]); //stampa c in essadecimale
}//fine for
       printf("\nLa stringa decifrata è: %s\n", m);
}//fine if a == 2

//se l'utente non inserisce i valori richiesti al momento della scelta, verranno stampati i seguenti messaggi di errore.
    if (a > 2) { //se il valore è maggiore di 2, viene stampato il seguente messaggio di errore
      printf("VALORE INSERITO ERRATO.\n Inserire 1 o 2.\n");
    }//fine if a>2

    if (a < 1) { //se il valore è minore di 1, viene stampato il seguente messaggio di errore
      printf("VALORE INSERITO ERRATO. \nInserire 1 o 2.\n");
    }//fine if a<1

}//fine main
