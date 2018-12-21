int finish=9; //sensor de posición final 
int contador=0; //inicializa cuando start detecta presencia
int mili=0; //contador de segundos en 0.01
int seg=0; //contador de segundos
float times=0; //tiempo de finalización 
float vel=0; //variable que guarda la velocidad en m/s
float vf=0; //variable que guarda la velocidad en km/h 
int v=0;//display imprime valor decimal del resultado
int f=0;//display imprime valor fraccionario del resultado
int start=0;//dato recibido del modulo de bluetooth 
void encender(int a, int b, int c, int d, int e, int f, int g)
{
  //Funcion que permite mostrar los numeros del 0 al 9
  //Asigna un segmento del display1 a cada pin

  digitalWrite(22, a);  //Asigna el segmento 'a' al pin 2
  digitalWrite(23, b);  //Asigna el segmento 'b' al pin 3
  digitalWrite(24, c);  //Asigna el segmento 'c' al pin 4
  digitalWrite(25, d);  //Asigna el segmento 'd' al pin 5
  digitalWrite(26, e);  //Asigna el segmento 'e' al pin 6
  digitalWrite(27, f);  //Asigna el segmento 'f' al pin 7
  digitalWrite(28, g);  //Asigna el segmento 'g' al pin 8
}

void encender2(int h, int i, int j, int k, int l, int m, int n)
{
  //Funcion que permite mostrar los numeros del 0 al 9
  //Asigna un segmento del display2 a cada pin

  digitalWrite(29, h);  //Asigna el segmento 'a' al pin 2
  digitalWrite(30, i);  //Asigna el segmento 'b' al pin 3
  digitalWrite(31, j);  //Asigna el segmento 'c' al pin 4
  digitalWrite(32, k);  //Asigna el segmento 'd' al pin 5
  digitalWrite(33, l);  //Asigna el segmento 'e' al pin 6
  digitalWrite(34, m);  //Asigna el segmento 'f' al pin 7
  digitalWrite(35, n);  //Asigna el segmento 'g' al pin 8
}

void setup()
{
  pinMode(finish,INPUT);
  Serial.begin(9600);
   /////////////////////// 
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(28, OUTPUT);
   /////////////////////// 
  pinMode(29, OUTPUT); 
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(35, OUTPUT);
  //////////////////////// 
  digitalWrite(22,LOW); 
  digitalWrite(23,LOW);  
  digitalWrite(24,LOW);   
  digitalWrite(25,LOW); 
  digitalWrite(26,LOW); 
  digitalWrite(27,LOW); 
  digitalWrite(28,HIGH); 
  //////////////////////// 
  digitalWrite(29,LOW); 
  digitalWrite(30,LOW);  
  digitalWrite(31,LOW);   
  digitalWrite(32,LOW); 
  digitalWrite(33,LOW); 
  digitalWrite(34,LOW); 
  digitalWrite(35,HIGH); 
  }
  void loop()
  {
    while(true){
   inicio();
   cronometro();
   fin();
    }
    }
    void inicio()
    {
      if(Serial.available()>0)
    {
      start = Serial.read();
      if(start == '1')
      {
        contador = true;
        times=0;
        vel=0;
        vf=0;
          }
       }
      }
     void cronometro()
    {
      inicio();
      while(contador == true){
      if(mili == 44)//44 
    {
      seg++;
      delay(mili=0);
      //Serial.println(mili ); 
        Serial.println(seg); 
      if(seg > 59)
       {
        seg=0;
        //Serial.println(seg);
        }
      } 
      else
      {
        delay(mili=mili+1); 
         //Serial.println(mili);
        }
        if(finish)
        {break;}
      }
    }
      void fin()
      {
        if(digitalRead(finish)==HIGH) 
        {
          while(true){
          mili=0; 
          times=seg; 
          if(times>0)
          {break;}
           }
           seg=0;
           //Serial.print("Tu valor es ");
           //Serial.println(times); 
           vel= 10/times; 
           //Serial.println(vel);
           vf=vel*(3.6); 
           Serial.println(vf);
           v=vf+0;
           f=((vf-v)/0.1)+1; 
    switch (v)
  {
    //Dependiendo del contador, se muestra el numero indicado
    case 0:
      encender (0, 0, 0, 0, 0, 0, 1); //Muestra el numero 0
      break;

    case 1:
      encender (1, 0, 0, 1, 1, 1, 1); //Muestra el numero 1
      break;

    case 2:
      encender (0, 0, 1, 0, 0, 1, 0); //Muestra el numero 2
      break;

    case 3:
      encender (0, 0, 0, 0, 1, 1, 0); //Muestra el numero 3
      break;

    case 4:
      encender (1, 0, 0, 1, 1, 0, 0); //Muestra el numero 4
      break;

    case 5:
      encender (0, 1, 0, 0, 1, 0, 0); //Muestra el numero 5
      break;

    case 6:
      encender (0, 1, 0, 0, 0, 0, 0); //Muestra el numero 6
      break;

    case 7:
      encender (0, 0, 0, 1, 1, 1, 1); //Muestra el numero 7
      break;

    case 8:
      encender (0, 0, 0, 0, 0, 0, 0); //Muestra el numero 8
      break;

    case 9:
      encender (0, 0, 0, 1, 1, 0, 0); //Muestra el numero 9
      break;
  } 
///////////////////
  switch (f)
  {
    case 0:
      encender2 (0, 0, 0, 0, 0, 0, 1); //Muestra el numero 0
      break;

    case 1:
      encender2 (1, 0, 0, 1, 1, 1, 1); //Muestra el numero 1
      break;

    case 2:
      encender2 (0, 0, 1, 0, 0, 1, 0); //Muestra el numero 2
      break;

    case 3:
      encender2 (0, 0, 0, 0, 1, 1, 0); //Muestra el numero 3
      break;

    case 4:
      encender2 (1, 0, 0, 1, 1, 0, 0); //Muestra el numero 4
      break;

    case 5:
      encender2 (0, 1, 0, 0, 1, 0, 0); //Muestra el numero 5
      break;

    case 6:
      encender2 (0, 1, 0, 0, 0, 0, 0); //Muestra el numero 6
      break;

    case 7:
      encender2 (0, 0, 0, 1, 1, 1, 1); //Muestra el numero 7
      break;

    case 8:
      encender2 (0, 0, 0, 0, 0, 0, 0); //Muestra el numero 8
      break;

    case 9:
      encender2 (0, 0, 0, 1, 1, 0, 0); //Muestra el numero 9
      break;
      }
     }
     
    }
    
      
      
        
