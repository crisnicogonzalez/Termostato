#include <stdio.h> //printf()
#include <stdlib.h> //atoi()
#include <math.h> //pow()
#include <string.h>

//Este modulo se encarga de todo lo que respecta al calcula y validación de
//un temperatura recibida en notación hexadecimal



float calcularVelocidad(int frecuencia){
  //printf("La cantidad rencuencia es:%d\n",frecuencia);
  //printf("La velocidad es:%d\n",velocidad);
  return 1000.0/frecuencia;
  }


//calcula de manera lineal la temperatura
float tranformar(int temp){
  float tempf = (float)temp;
  //printf("conversion:%f\n",tempf);
  return (0.1)*tempf - 17.0;
}

int conversionHexDec(char* hexadecimal) {
    //printf("Hexadecimal:%s ",hexadecimal);
    int numDecimal = 0;
    char hexDigitos[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D'
    ,'E','F'};
    int i, j;
    int potencia = 0; // potencia a la que se eleva el numero 16

    /* Converting hexadecimal number to decimal number */
    for (i = strlen(hexadecimal)-1; i >= 0; i--) {
        for (j = 0; j < 16; j++){
            if (hexadecimal[i] == hexDigitos[j]){
                numDecimal += j*pow(16, potencia);
            }
        }
        potencia++;
    }
    //printf("Decimal:%d ", numDecimal);
    return numDecimal;
}

int calcular(char hexa[5],char temp[5],int largo){
  int num = conversionHexDec(hexa);
  //printf("El num entero:%d ",num);
  float numTrans = tranformar(num);
  //printf("float:%f\n", numTrans);
  snprintf(temp,largo,"%.2f",numTrans);
  return 0;
}
