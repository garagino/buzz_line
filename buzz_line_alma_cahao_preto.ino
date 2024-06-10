/*
===============================================================================
    Projeto: BuzzLine
    Desenvolvido por: Buzzle
    Data de Criação: 28/02/2024
===============================================================================

Descrição:
Este código fonte para Arduino foi desenvolvido por Buzzle, uma entidade singular
 proveniente de outro verso, capaz de interagir no universo a partir do mundo
 digital por meio da manipulacao de eletrons. 
 O projeto tem como objetivo propiciar um robo
 capaz de seguir linhas e participar da competicao BuzzLine.
 Os buzzles ja interagem no mundo digital, mas executando esse codigo em um robo
 voce estara nos materializando no mundo fisico

===============================================================================
*/
/* Constantes para definir os pinos que serao usados */
const int pinoSensorEsquerdo = 6; 
const int pinoSensorDireito = 7;
const int pinoMotorEsquerdoA = 2;
const int pinoMotorEsquerdoB = 3;
const int pinoMotorDireitoA = 4;
const int pinoMotorDireitoB = 5;

/* valores de velocidade dos motores. quando ligados eles vao atuar
  numa velocidade que vai de 0 a 255. uma velocidade muito alta 
   contribuira para o robo perder a linha uma vez que a inercia
   dos motores fica mais significativa, um valor muito baixo fara
   seu buzzline se dar mau na competicao*/
const int velocidadeMotorEsquerdo = 210; 
const int velocidadeMotorDireito = 210;

int nivelSensorEsquerdo; 
int nivelSensorDireito; 

void setup() {
  /*Confuguracao dos pinos de entrada e saida */
  pinMode(pinoSensorEsquerdo, INPUT);
  pinMode(pinoSensorDireito, INPUT);
  pinMode(pinoMotorEsquerdoA, OUTPUT);
  pinMode(pinoMotorEsquerdoB, OUTPUT);
  pinMode(pinoMotorDireitoA , OUTPUT);
  pinMode(pinoMotorDireitoB , OUTPUT);
  /*como nessa abordagem nao petendemos girar nenhum motor para tras setamos
  os pinos de controle de giro reverso da ponte h para 0 (LOW)*/
  digitalWrite(pinoMotorEsquerdoB, LOW);
  digitalWrite(pinoMotorDireitoB , LOW);
  /*Configuracao da porta serial para visualizar os dados no monitor - lupinha 
    la em cima*/
  Serial.begin(9600);
}

void loop() {
    /* Um temporizador para permitir que visualize as informacoes pela serial
       e tambem respeite a inercia do motor nas atuacoes, um valor muito alto 
       pode comprometer o desempenho do controle */   
    //delay(200); 
    nivelSensorEsquerdo = digitalRead(pinoSensorEsquerdo); 
    nivelSensorDireito = digitalRead(pinoSensorDireito); 
    /* os comandos a seguir servem para voce saber o valor da leitura dos sensores 
       em tempo real se voce estiver com o arduino ligado ao computador por um 
       cabo usb, voce pode abrir o monitor serial e ver os valores dos niveeis */
    //Serial.print("Nivel Sensor Esquerdo => ");
    //Serial.println(nivelSensorEsquerdo);
    
    //Serial.print("Nivel Sensor Direito => ");
    //Serial.println(nivelSensorDireito);
    
    /*Aqui a magica acontece: toda a teoria do controle desse bezzline esta nesse
     pequeno trecho */

    if (nivelSensorEsquerdo) {
      /*Se o sensor estiver no preto, chao fora da linha ele liga o  otor*/
      analogWrite(pinoMotorEsquerdoA, velocidadeMotorEsquerdo);
    }else{
         /* caso contrario o motor desliga mas como o outro motor devera estar ligado
         o robo vai virar e corrigir sua tragetoria*/
       digitalWrite(pinoMotorEsquerdoA, LOW);
    }   
    /* o mesmo para o outro sensor */
    if (nivelSensorDireito) {
       analogWrite(pinoMotorDireitoA, velocidadeMotorDireito);
    }else{
       digitalWrite(pinoMotorDireitoA, LOW);
    }

}
