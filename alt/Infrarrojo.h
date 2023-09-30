class Infrarrojo {
  private :
  int pin;
  int valor;
  int sens = 45;
  int sensG = 80;

  public :
  void init(int);
  int read(); // Valor entero
  int readL(); // Interpretacion
  
  protected :
} ;
