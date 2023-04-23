//#include <stdio.h>
//#include <conio.h>
//#include <malloc.h>

    // Funcţie care determină numarul de divizori ai unui intreg
int nr_div (int);

    // Funcţie care citeşte de la tastatură valori pentru elementele unui tablou de intregi 
    //unidimensional; elementele sunt unice.
void citire(int*, int);

    // Funcţie care afiseaza elementele unui tablou de intregi
void afisare(int*, int);

int main()
{
    int* a, nr, i, j, k, nr_maxdiv=0;
    int * mat, maxdiv=1;

    FILE* f;

    printf("Nr. de numere: ");
    scanf("%d", &nr);

    a = (int*)malloc( nr * sizeof(int));

    citire(a, nr);
    afisare(a, nr);

    for(i=0; i<nr;i++)
    if(maxdiv<nr_div(a[i]))
    {
    maxdiv = nr_div(a[i]);
    nr_maxdiv = a[i];
 }
    printf("\nValoarea %d are cel mai mare numar de divizori: %d", nr_maxdiv, maxdiv);
    mat= (int*)malloc( nr * (maxdiv +2) * sizeof(int));
    for(i=0; i<nr ; i++)
 {
    mat[i*(maxdiv+2)] = a[i];
    mat[i*(maxdiv+2)+1] = nr_div(a[i]);
    j=2;
    for(k=2; k<=a[i]; k++)
    if(a[i]%k == 0)
 {
    mat[i*(maxdiv+2) +j] = k;
    j++;
 }
    for(; j<(maxdiv+2);j++)
    mat[i*(maxdiv+2) +j] = 0;
 }
    for(i=0; i<nr; i++)
 {
 printf("\n\nNumarul: %d", mat[i*(maxdiv+2)]);
 printf("\nNumarul de divizori: %d", mat[i*(maxdiv+2)+1]);
 printf("\nDivizorii sunt: ");
 for(j=2; j<(maxdiv+2);j++)
 if(mat[i*(maxdiv+2) +j]!=0)
 printf("%5d", mat[i*(maxdiv+2) +j]);
 }
 f= fopen("fis.txt", "w");
 for(i=0; i<nr; i++)
 {
 fprintf(f, "Nr: %5d ", mat[i*(maxdiv+2)]);
 fprintf(f, "Nr. div: %2d -", mat[i*(maxdiv+2)+1]);
 for(j=2; j<(maxdiv+2);j++)
 if(mat[i*(maxdiv+2) +j]!= 0)
 fprintf(f, "%5d", mat[i*(maxdiv+2) +j]);
 fprintf(f, "\n");
 }
 free(a);
 free(mat);
 fclose(f);
getch();
 return 0;
}
int nr_div(int nr)
{
 int i, d=1;
 for(i=2; i<nr; i++)
 if(nr%i == 0)
 d++;
 return d;
}
void citire(int* a, int n)
{
 int i, j, unic = 1;
 for(i=0; i<n; i++)
 {
 do
 { unic = 1;
 printf("\na[%d] = ", i);
 scanf("%u", &a[i]);
 for(j=0;j<i;j++)
 {
 if(a[i] == a[j])
 {
 printf("\nValoarea %d a fost deja introdusa !", a[i]);
 unic = 0;
 }
 if(a[i] < 0)
 {
 printf("\nValoarea %d este negativa !", a[i]);
 unic = 0;
 }
 }
 }
 while(unic == 0);
 }
}
void afisare(int* a, int n)
{
 int i;
 printf("\n");
 for(i=0; i<n; i++)
 printf("%d ", a[i]);
}