#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
void encriptar();
void desencriptar();
       
int main()
{
      int opcion;
      printf("Que tal, Elige una de las Siguientes Opciones: \n");
      printf("\t 1.- Encriptar un Mensaje  \n ");
      printf("\t 2.- Desencriptar un Mensaje \n");
      printf("\t 3.- Salir \n");
      scanf("%d",&opcion);
  switch(opcion)
{
	case 1:
		encriptar();
		break;
	case 2:
		desencriptar();
		break;
	case 3:
		//acciones
		break;
	defalut:
		//acciones
		break;
}
  
  
     printf("\n");
     system("PAUSE");
    }


void encriptar()
{ 
char cadena[]="";  
char arreglo[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};       
char arreglo2[26]={'h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g'};       

int i, j;
int letra=0;
printf ("\n Escribe una Cadena  a Encriptar: ");
scanf("%s",cadena);
char encriptado[strlen (cadena)];
//VALIDAMOS SOLO LETRAS NO IMPORTA SI SON MAYUSCULAS O MINUSCULAS
for (int i = 0 ; i < strlen (cadena) ; i++){
if ((cadena[i]>= 65 && cadena[i] <= 90 ) || (cadena[i]>= 97 && cadena[i] <= 122 ))
letra = 1;
}
if (letra==1){
       //CAMBIAMOS DE MAYUSCULA A MINUSCULA
       strlwr (cadena);                                
int encriptado[strlen (cadena)];
for (i=0; i<strlen (cadena); i++)
 {    
      for (j=0;j<27;j++){
        if(cadena[i]==arreglo[j])
        {
                                
                encriptado[i]= arreglo2[j];                 
                
         }
        }                  
                          
       
 }     // MOSTRAMOS AL USUARIO SU CADENA ENCRIPTADA
       printf("\nEsta es tu Cadena Encriptada :  ");
       for (i=0; i< strlen(cadena); i++)
           {   printf("%c", encriptado[i]);
           }

}else if (letra==0){printf("La cadena tiene caracteres no permitidos");}
}



void desencriptar()
{
char cadena[]="";  
char arreglo[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};       
char arreglo2[26]={'h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g'};       

int i, j;
int letra=0;
printf ("\n Escribe una Cadena a Desencriptar: ");
scanf("%s",cadena);
char desencriptado[strlen (cadena)];
//VALIDAMOS SOLO LETRAS NO IMPORTA SI SON MAYUSCULAS O MINUSCULAS
for (int i = 0 ; i < strlen (cadena) ; i++){
if ((cadena[i]>= 65 && cadena[i] <= 90 ) || (cadena[i]>= 97 && cadena[i] <= 122 ))
letra = 1;
}
if (letra==1){
       //CAMBIAMOS DE MAYUSCULA A MINUSCULA
       strlwr (cadena);                                
int encriptado[strlen (cadena)];
for (i=0; i<strlen (cadena); i++)
 {    
      for (j=0;j<27;j++){
        if(cadena[i]==arreglo2[j])
        {
                                
                desencriptado[i]= arreglo[j];                 
                
         }
        }                  
                          
       
 }     // MOSTRAMOS AL USUARIO SU CADENA ENCRIPTADA
       printf("\nEsta es tu Cadena Desencriptada :  ");
       for (i=0; i< strlen(cadena); i++)
           {   printf("%c", desencriptado[i]);
           }

}else if (letra==0){printf("La cadena tiene caracteres no permitidos");}
}
