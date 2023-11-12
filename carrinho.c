// Pinos de controle do Sensor
#define pinSensorD 4
#define pinSensorE 12

// Pinos de controle do Motor
#define negativoMotor1 3
#define positivoMotor1 9
#define positivoMotor2 6
#define negativoMotor2 5

int velocidadeMotor = 250;

// Define os pinos (Entrada para os Sensores e Saída para os Motores)
void setup() {


  // put your setup code here, to run once:
  pinMode(pinSensorD, INPUT);
  pinMode(pinSensorE, INPUT);

  pinMode(negativoMotor1, OUTPUT);
  pinMode(positivoMotor1, OUTPUT);
  pinMode(positivoMotor2, OUTPUT);
  pinMode(negativoMotor2, OUTPUT);

}

void loop() {

  // Lendo o estado (Status) dos sensores
  bool sensorDireitoAtivo = digitalRead(pinSensorD);
  bool sensorEsquerdoAtivo = digitalRead(pinSensorE);

  if (!sensorDireitoAtivo && !sensorEsquerdoAtivo)
  {
    andaPraFrenteLadoDireito();
    andaPraFrenteLadoEsquerdo();
  }
  else
  {
      // Verifica se o sensor do lado direito está recebendo sinal (branco)
      if (!sensorDireitoAtivo)
      {
        andaPraFrenteLadoDireito();
        andaPraTrazLadoEsquerdo();
      }
      else if (!sensorEsquerdoAtivo)
      {
        andaPraFrenteLadoEsquerdo();
        andaPraTrazLadoDireito();
      }
      else
      {
        pararLadoDireito();
        pararLadoEsquerdo();
      }
  }

}

// Metodo para andar o motor do lado direito
void andaPraFrenteLadoDireito()
{
  digitalWrite(negativoMotor1, 0); // Define pino do motor 1 como negativo
  analogWrite(positivoMotor1, velocidadeMotor); // Define pino do motor 
}

void andaPraTrazLadoDireito()
{
  analogWrite(negativoMotor1, velocidadeMotor);
  digitalWrite(positivoMotor1, 0);
}

void pararLadoDireito()
{
  digitalWrite(negativoMotor1, 0);
  digitalWrite(positivoMotor1, 0);
}

void andaPraFrenteLadoEsquerdo()
{
  analogWrite(positivoMotor2, velocidadeMotor);
  digitalWrite(negativoMotor2, 0);
}

void andaPraTrazLadoEsquerdo()
{
  digitalWrite(positivoMotor2, 0);
  analogWrite(negativoMotor2, velocidadeMotor);
}

void pararLadoEsquerdo()
{
  digitalWrite(positivoMotor2, 0);
  digitalWrite(negativoMotor2, 0);
}