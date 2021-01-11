#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <time.h> 
void encriptar();
void desencriptar();
int validar_cadena(char cadena[50]);       
int main()
{
      int opcion;
      int repetir=1;
      
	do{
      system ("cls");
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
     system("PAUSE");}while (opcion!=3);
    }



void encriptar()
{ 
char cadena1[50];  
int vector[50];
int vectorencriptador[50];
int sw;
char arreglo2[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};       
char arregloencriptado[50];
int key[2][2];  
int det=25;
int md2=1;
int md13= 1;
int flag=1;
int flag2=0;
int Dato1=0;
int Dato2=0;
int c=0;
srand(time(NULL));
    
    do{
    
              det=0;
              //vaciar la matriz llamada key
              for (int i=0; i< 2;i++)
                    {
                    for (int j=0; j< 2;j++)
                    {
                      key[i][j]= 0;
                    }
                   }
            
// llenado dinamico de matriz de 2 x 2
// aqui creamos una matriz que cumpla con las condiciones si no la busca hasta que la encuentre                  
                    for (int i=0; i< 2;i++)
                    {
                    for (int j=0; j< 2;j++)
                    {
        
                      key[i][j]=(rand() % 26);
         
        
                    }
                      
                      
      
                   }
      det = ((key[0][0] * key [1][1])-(key[1][0] * key [0][1])) ;
      md2 = det % 2;
      md13 = det % 13; 
      if((md2!=0) && (md13 != 0) && (det != 0))
          flag=0;
      }while(flag==1);
/*
  for (int i=0; i< 2;i++)
                 {
                     for (int j=0; j< 2;j++)
                          {
                          printf("%3d \t", key[i][j]);
                          }
                          printf ("\n");
                 }  
  printf ("\n");
printf ("%d",det);
*/
fflush(stdin);
int tamanocadena1;
printf ("\n Escribe Tu Cadena  a Encriptar: ");
gets(cadena1);
tamanocadena1=strlen(cadena1);
sw= validar_cadena(cadena1)  ; // LLAMA A LA FUNCION PARA VALIDAR LA CADENA  A ENCRIPTAR
strlwr (cadena1); 
if ((sw==0))// SI SON SOLO CARACTERES ENTRA AL PROCESO
{
if (tamanocadena1 % 2 !=0)
  {  
     cadena1[tamanocadena1] = 'x';// SI NO ES UNA CADENA PAR AGREGA UNA X AL FINAL
     flag2=1;
  }
          if (flag2 ==1)// SI LA CADENA NO ES PAR LE AGREGAMOS UN X ENTRA AQUI
          {
               for (int i=0; i<=tamanocadena1; i++)//AQUI RECORREMOS LAS CADENAS Y BUSCAMOS EN ARREGLO 2 SU POSICION
                    {         
                              for (int j=0; j<26; j++){
                              if (arreglo2[j]== cadena1[i])
                              vector[i] = j;
                              }
                            
                              
                    }                 
                     for (int i=0; i<=tamanocadena1; i++)
                    {         
                              int k = 0;
                              for (int j=0; j<2; j++)
                              {
                                  Dato1= (key[j][k]) * (vector[i]);
                                  Dato2= (key[j][k+1]) * (vector[i + 1]);
                                   if (j==0)
                                   vectorencriptador[i]= Dato1 + Dato2;
                                   else
                                   vectorencriptador[i+1]= Dato1 + Dato2;                                   
                              }
                            
                            i=i+1; 
                    }
                      for (int i=0; i<= tamanocadena1; i++) //sacamos el mod 26 de para mostrar las letras de cada numero
                       {      
                           c=(vectorencriptador[i])%26;
                           arregloencriptado[i]= arreglo2[c];
                          // printf("%c", desencriptado[i]);
                        }
                    
                    printf("\n\nESTA ES TU CADENA ENCRIPTADA        : ");
                    for (int i=0; i<= tamanocadena1; i++)
                       {   printf("%c", arregloencriptado[i]);
                        }  
                     printf("\n\nESTA ES TU MATRIZ DE DESENCRIPTACION:");   
                 //CICLO FOR QUE MUESTRA LA MATRIZ CREADA DINAMICAMENTE
                 for (int i=0; i< 2;i++)
                 {
                     for (int j=0; j< 2;j++)
                          {
                          printf("| %2d |", key[i][j]);
                          }
                          //printf ("\n");
                 }       
                                 
          }          
          else{// SI NO LE AGREGAMOS NADA AL FINAL ENTRA AQUI
               for (int i=0; i<tamanocadena1; i++)//AQUI RECORREMOS LAS CADENAS Y BUSCAMOS EN ARREGLO2 SU POSICION
                    {        
                              for (int j=0; j<26; j++)
                              {
                              if (arreglo2[j]== cadena1[i])
                              vector[i] = j;
                              }              
                    }     
                     for (int i=0; i<tamanocadena1; i++)
                    {         
                              int k = 0;
                              for (int j=0; j<2; j++)
                              {
                                  Dato1= (key[j][k]) * (vector[i]);
                                  Dato2= (key[j][k+1]) * (vector[i + 1]);
                                   if (j==0)
                                   vectorencriptador[i]= Dato1 + Dato2;
                                   else
                                   vectorencriptador[i+1]= Dato1 + Dato2;                                   
                              }
                            
                            i=i+1; 
                    }
                    
                    for (int i=0; i< tamanocadena1; i++) //sacamos el mod 26 de para mostrar las letras de cada numero
                       {      
                           c=(vectorencriptador[i])%26;
                           arregloencriptado[i]= arreglo2[c];
                        }
                    
                    printf("\n\nESTA ES TU CADENA ENCRIPTADA        : ");
                    for (int i=0; i< tamanocadena1; i++)
                       {   printf("%c", arregloencriptado[i]);
                        }  
                     printf("\n\nESTA ES TU MATRIZ DE DESENCRIPTACION:");   
                 //CICLO FOR QUE MUESTRA LA MATRIZ CREADA DINAMICAMENTE
                 for (int i=0; i< 2;i++)
                 {
                     for (int j=0; j< 2;j++)
                          {
                          printf("| %2d |", key[i][j]);
                          }
                 }                                   
          }                
                     



}
                           else{printf("\nTu Mensaje tiene contiene caracteres no permitidos");} 
  
}



void desencriptar()
{
char cadena1[50];  
int sw;
char desencriptado[50];
int vector[50];
char arreglo2[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};       
int key[2][2];       
fflush(stdin);
int tamanocadena1;
int valor=0;
int det =0;
int ndet =0;
int intercambio1=0;
int intercambio2=0;
int intercambio3=0;
int intercambio4=0;
int Dato1 =0;
int Dato2=0;
int c =0;
int vectordesencriptador[50];
printf ("\n A CONTINUACION ESCRIBE TU MATRIZ : ");
for(int i= 0; i < 2; i++)
{
        for(int j= 0; j < 2; j++)
             {
             printf ("\n Dame la Posicion de la Matriz [%d][%d] : ",i,j);
             scanf("%d",&valor);
             key[i][j] = valor;
             }
}
  det = ((key[0][0] * key [1][1])-(key[1][0] * key [0][1])) ;
intercambio1=key[1][1];
intercambio2=key[0][0];
intercambio3=( -1 * key[0][1]);
intercambio4=(-1 * key[1][0]);
//  if (det < 0)
  //{
ndet = -((-det) % 26 ) + 26;
int m =1;
int x =0;
int flag1=0;

while(flag1 == 0){//BUSCAMOS UN NUMERO QUE SE MULTIPLICADO POR EL DETERMINANTE -1 NOS DE COMO RESULTAD
                  // 1 EN EL MODULO 26
      x = (ndet * m) % 26 ;
     
     if (x == 1)
     {flag1 = 1;}
     
     m = m + 1;
     }

m = m - 1;

key[0][0] = m * intercambio1;
key[1][1] = m * intercambio2;
key[0][1] = m * intercambio3;
key[1][0] = m * intercambio4;
for (int i=0; i< 2;i++)
                 {
                     for (int j=0; j< 2;j++)
                          {
                              if (key[i][j] >= 0)
                             key[i][j] =   key[i][j] % 26;
                             else 
                             key[i][j] = -((-key[i][j]) % 26 ) + 26;
                              
                              
                         // printf("%3d \t", key[i][j]);
                          }
                          //printf ("\n");
                 }  
//printf ("%d",m);
fflush(stdin);
printf ("\n Escribe Tu Cadena  a Desencriptar    : ");
gets(cadena1);
tamanocadena1=strlen(cadena1);
sw= validar_cadena(cadena1);
strlwr (cadena1);
if ((sw==0))
{
          for (int i=0; i<tamanocadena1; i++)//AQUI RECORREMOS LAS CADENAS Y BUSCAMOS EN ARREGLO 2 SU POSICION
                    {         
                              for (int j=0; j<26; j++){
                              if (arreglo2[j]== cadena1[i])
                              vector[i] = j;
                              }
                    } 
                    
                    
          for (int i=0; i<tamanocadena1; i++)
                    {         
                              int k = 0;
                              for (int j=0; j<2; j++)
                              {
                                  Dato1= (key[j][k]) * (vector[i]);
                                  Dato2= (key[j][k+1]) * (vector[i + 1]);
                                   if (j==0)
                                   vectordesencriptador[i]= Dato1 + Dato2;
                                   else
                                   vectordesencriptador[i+1]= Dato1 + Dato2;                                   
                              }
                            
                            i=i+1; 
                    } 
                    for (int i=0; i< tamanocadena1; i++) //sacamos el mod 26 de para mostrar las letras de cada numero
                       {      
                           c=(vectordesencriptador[i])%26;
                           desencriptado[i]= arreglo2[c];
                        }
                    printf ("\n\n ESTE ES TU MENSAJE DESCIFRADO  : ");
                    for (int i=0; i< tamanocadena1; i++)
                       {   printf("%c", desencriptado[i]);
                        } 
                    printf ("\n\n");
            }

}



int validar_cadena(char cadena[50])
{// FUNCION QUE VALIDA LAS CADENAS QUE SE INTRODUCEN, SOLO PARA VERIFICAR QUE SEAN LETRAS
    int i = 0, sw=0, j;
    j=strlen(cadena);
    while(i<j && sw==0)
    {
              if(isalpha(cadena[i])!=0)i++;
              else sw=1;
              
           }
    return sw;
    }