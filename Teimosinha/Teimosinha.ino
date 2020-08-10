// Inclui biblioteca para uso do servo
#include <Servo.h>

// Declara nossas variaveis de posicao
int  alto = 140;
int  baixo = 0;
// Declara as conexoes dos componentes
int  portaServo = 9;
int  botao = 13;

// Cria uma variável para o tempo (sera alterada)
int  tempo = 5;

// Cria um objeto para controlar o motor
Servo meuServo;

// Variavel para armazenar o angulo
int  pos = 0;

void setup() {
	meuServo.write(baixo);
	delay(1000);
	// Informa que o servo esta conectado na porta digital 9
	meuServo.attach(portaServo);
	pinMode(botao, INPUT_PULLUP);
}

void loop() {
	if(!digitalRead(botao)){	// Movimenta o servo do angulo baixo ate o angulo alto de um a um grau
		for (pos = baixo; pos <= alto; pos += 1) {
			// Movimenta o servo para o angulo especificado
			meuServo.write(pos);        
			pos > (alto/2) ? tempo = 2 : tempo = 8;      
			// Espera o motor se mover
			delay(tempo);
		}
		int  aleatorio = random(15);
		// Movimenta o servo do angulo alto ate o angulo baixo de um a um grau
		for (pos = alto; pos >= (baixo-10); pos -= 1) {
			// Movimenta o servo para o angulo especificado
			meuServo.write(pos);
			// Espera o motor se mover
			delay(aleatorio);
		}
		meuServo.write(baixo);
	}
}

