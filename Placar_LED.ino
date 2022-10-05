// C++ code
//
int valor;

byte numeros[10][7] = {
 
 { 0,1,1,1,1,1,1 },  //DIGITO 0
 { 0,0,0,0,1,1,0 },  //DIGITO 1
 { 1,0,1,1,0,1,1 },  //DIGITO 2
 { 1,0,0,1,1,1,1 },  //DIGITO 3
 { 1,1,0,0,1,1,0 },  //DIGITO 4
 { 1,1,0,1,1,0,1 },  //DIGITO 5
 { 1,1,1,1,1,0,1 },  //DIGITO 6
 { 0,0,0,0,1,1,1 },  //DIGITO 7
 { 1,1,1,1,1,1,1 },  //DIGITO 8
 { 1,1,0,1,1,1,1 }   //DIGITO 9

};
void setup() {
  //SEGMENTOS 
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  //BOTÕES
  pinMode(5, INPUT);
  pinMode(3, INPUT);
  //INICIALIZAR O VISOR COM UM VALOR
  valor = 0;
  numeroPainel(valor);
  Serial.begin(9600); 
}
void loop() {
 //BOTÃO PARA AUMENTAR O VALOR NUMERICO
 switch (digitalRead(3)) {
  case 0:
    
    break;
  case 1:
    delay(500);
    valor++;
   	if (valor > 9){
  	valor = 0;
  }
    numeroPainel(valor);
    break;
  }
  //BOTÃO PARA DIMINUIR O VALOR NUMERICO
  switch (digitalRead(5)) {
   case 0:
    break;
   case 1:
     delay(500);
     valor--;
    if (valor < 0){
  	valor = 0;
  }
     numeroPainel(valor);
    break;
  } 
}
// FUNÇÃO PARA ACIONAR O O PAINEL COM O NÚMERO DESEJADO
void numeroPainel (byte digito){
  
  byte pino = 7;
  //Serial.println(digito);
  //PROTEÇÃO DE ERRO COM DIGITOS MAIORES QUE 9
    
  for (byte contadorSegmentos = 0; //INICIO DO FOR
       contadorSegmentos < 7; //LIMITE DO FOR
       ++contadorSegmentos){ //INCREMENTO DO VARIAVEL
    
    digitalWrite(pino, 
                 numeros[digito][contadorSegmentos]);       
    ++pino;
    
    Serial.print("digitalWrite(");
    Serial.print(pino);
    Serial.print(", ");
    Serial.print(numeros[digito][contadorSegmentos]);
    //Serial.print(digito);
    //Serial.print("] [");
    //Serial.print(contadorSegmentos);
    Serial.println(");");    
  }
}