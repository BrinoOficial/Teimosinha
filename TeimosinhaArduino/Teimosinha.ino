const int  m1=8; // Motor 1
const int  m2=7; // Motor 2
const int  botao = 2;
const int  pinoVelocidade = 9;
int  velocidadeMax =255;
int  velocidadeMedia = 180;
int  velocidadeMin= 150;
int  estadoBotao = 0;
int  opcao = 0;
int  valorMin= 1; // Valor minimo do aleatorio
int  valorMax = 1; // Valor maximo do aleatorio

void setup(){
	Serial.begin(19200);
	pinMode(m1, OUTPUT);
	pinMode(m2, OUTPUT);
	pinMode(botao, INPUT_PULLUP);
	pinMode(pinoVelocidade, OUTPUT);		
	randomSeed(analogRead(0)); // randomSeed(analogRead(0));
	 ajustarVelocidade(velocidadeMax);
	
}
void loop(){
	opcao= random(valorMin,valorMax);  //opcao= numeroAleatorio(valorMin,valorMax); 	
	estadoBotao = digitalRead(botao);
	if(estadoBotao == LOW){
		fecharCaixa(opcao);
	}

	

}

void ajustarVelocidade(int  velocidade){
	analogWrite(pinoVelocidade, velocidade);
}

void fecharCaixa(int  opcao){
	switch(opcao){
		case 1:
			estadoBotao = digitalRead(botao);
			ajustarVelocidade(velocidadeMedia);
			int  tempoInicio = millis();
			while( estadoBotao == LOW){
				Serial.print("entrou do while");
				Serial.print("\n");
				girarParaFrente();
				estadoBotao = digitalRead(botao);	
			}
			Serial.print("saiu do while");
			Serial.print("\n");
			int  intervalo = millis() - tempoInicio;
			if(intervalo >= 1200){
				intervalo = 500;
			}
			pararGirar();
			delay(100);
			girarParaTras();
			delay(intervalo/5);
			pararGirar();
			delay(100);
		break;
	}
}


void girarParaFrente(){
	digitalWrite(m1,HIGH);
	digitalWrite(m2,LOW);
}

void girarParaTras(){
	digitalWrite(m1,LOW);
	digitalWrite(m2,HIGH);
}

void pararGirar(){
	digitalWrite(m1,LOW);
	digitalWrite(m2,LOW);
}





