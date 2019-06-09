# include <stdio.h>


enum enfasis {ELECTRONICA=1,REDES,POTENCIA,CONTROL};

struct datos_persona
{
	char nombre[20];
	char apellido[20];
	int telefono;
	char carnet[6];
	//enfi es el nombre de un enum tipo enfasis
	enum enfasis enfi;	
};

void set_struct(struct datos_persona *puntero)
{
	int a;
	printf("Digite el nombre: \n");
	scanf("%s", puntero->nombre);
	printf("Digite el apellido: \n");
	scanf("%s",puntero->apellido);
	printf("Digite el telefono: \n");
	//El int es diferente y hay que ponerle &
	scanf("%d",&puntero->telefono);
	printf("Digite el carnet: \n");
	scanf("%s",puntero->carnet);
	printf("Digite el numero que corresponde a su enfasis: \n");
	printf("1 : Electronica\n 2 : Redes \n 3: Potencia \n 4 : Control \n");
	scanf("%d",&a);

	switch (a)
	{
		case 1:	
			puntero->enfi = ELECTRONICA;
			break;
		case 2:
			puntero->enfi = REDES;
			break;
		case 3:
			puntero->enfi = POTENCIA;
			break;
		case 4:
			puntero->enfi = CONTROL;	
			break;	
			
		default : printf( "\n   ERROR: esa opcion no existe." );
	}

};

void print_struct(struct datos_persona *puntero)
{
	printf("Nombre: %s \n", puntero->nombre);
	printf("Apellido: %s \n",puntero->apellido);
	printf("Telefono: %d \n", puntero->telefono);
	printf("Carnet: %s \n",puntero->carnet);
	
	switch(puntero->enfi)
	{
		case 1:
			printf("Enfasis: Electronica \n \n");
			break;
		case 2:
			printf("Enfasis: Redes \n \n");
			break;
		case 3:
			printf("Enfasis: Potencia \n \n ");
			break;
		case 4:
			printf("Enfasis: Control \n \n");
			break;
		default : printf( "\n   Digito una opcion que no existe. \n" );
	}
	//printf("Enfasis: %d \n",puntero->enfi);  solo va a imprimir 1,2,3 o 4.
};

int main()
{
	// struct datos_persona estructura es si creara uno solo
	int personas=5;
	struct datos_persona estructura[personas];
	struct datos_persona *puntero;
	puntero = &estructura[0];
	//para que el puntero sea usado tengo que llamar a una funcion que lo use
	int contador;
	for( contador=0 ; contador < personas ; contador++ )
	{
		set_struct(puntero);
		puntero++;
	}
	puntero = &estructura[0];
	for( contador=0 ; contador < personas ; contador++ )
	{
		print_struct(puntero);
		puntero++;
	}
		
}

