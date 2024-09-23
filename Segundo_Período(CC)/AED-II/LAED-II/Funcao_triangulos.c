#include <stdio.h>
#include <math.h>

typedef struct ponto
{
    float coordX, coordY;
} Ponto;

void registraPonto(Ponto *p);
float calculoTriangulo(Ponto i, Ponto j);//<--
int verificaTipoTriangulo(Ponto *p); //<--


int main()
{
    Ponto Bill_Cypher[3];

    for(int i=0; i<3; i++)
        registraPonto(&Bill_Cypher[i]);

    int result = verificaTipoTriangulo(Bill_Cypher);

    if(result == 1)
        printf(">>Triangulo isosceles");
    if(result == 2)
        printf(">>Triangulo equilatero");
    if(result == 3)
        printf(">>Triangulo escaleno");
}

void registraPonto(Ponto *p)
{
    printf("Digite as coordX e coordY:");
    scanf("%f %f", &p->coordX, &p->coordY);
}

float calculoTriangulo(Ponto i, Ponto j)//<--
{
    int resultado;
    resultado = sqrt(pow((i.coordX - j.coordY), 2)+ pow((i.coordY - j.coordY), 2));

    return resultado;
}

int verificaTipoTriangulo(Ponto *p)//<--
{
    int a, b, c;

    a = calculoTriangulo(p[0], p[1]);
    b = calculoTriangulo(p[0], p[2]);
    c = calculoTriangulo(p[1], p[2]);

    if(a==b && b==c)
        return 2; //equilatero
    if(a==b && b != c)
        return 1; //isosceles
    if(a != b && a!=c && b!= c)
        return 3; //escaleno
}
