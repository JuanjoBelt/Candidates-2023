class Ultrasonic {
  private :
  int PinTrig;
  int PinEcho;
  const float VelSon = 34000.0; // Constante velocidad sonido en cm/s
  float distancia;
  unsigned long tiempo;

  void iniciarTrigger();

  public :
  void init(int, int);
  float read(); // Distancia en cm
  
  protected :
} ;
