int LEDS_F[5];
int LEDS_C[3];
int tetris[5][3];
int n = 1;
#define TAM_F 5
#define TAM_C 3
int x = 0;
int y = 0;

class Figura
{
  public:
    virtual ~Figura() {}
    virtual void crearFigura() = 0;
    virtual bool puedeBajar(int x, int y) = 0;
    virtual bool puedeGirar(int x, int y) = 0;
    virtual bool puedeIrDer(int x, int y) = 0;
    virtual bool puedeIrIzq(int x, int y) = 0;
    virtual void bajar(int x, int& y) = 0;
    virtual void girar(int x, int y) = 0;
    virtual void irIzq(int& x, int y) = 0;
    virtual void irDer(int& x, int y) = 0;
};


class Figura1 : public Figura
{
  public:
    ~Figura1() {}
    void crearFigura();
    bool puedeBajar(int x, int y);
    bool puedeGirar(int x, int y);
    bool puedeIrDer(int x, int y);
    bool puedeIrIzq(int x, int y);
    void bajar(int x, int& y);
    void girar(int x, int y);
    void irIzq(int& x, int y);
    void irDer(int& x, int y);
};
void Figura1::crearFigura()
{
  tetris[0][0] = 1;
  tetris[0][1] = 1;
  tetris[1][1] = 1;
  tetris[1][2] = 1;
}
bool Figura1::puedeBajar(int x, int y)
{
  if (y > TAM_F - 3)
  {
    return false;
  }
  if (tetris[y + 1][x] == 1)
  {
    return false;
  }
  if (tetris[y + 2][x + 1] == 1)
  {
    return false;
  }
  if (tetris[y + 2][x + 2] == 1)
  {
    return false;
  }
  return true;
}
bool Figura1::puedeGirar(int x, int y)
{
  if (tetris[y][x + 2] == 1)
  {
    return false;
  }
  if (tetris[y + 2][x + 1] == 1)
  {
    return false;
  }
  return true;
}
bool Figura1::puedeIrDer(int x, int y)
{
  if (x > TAM_C - 4)
  {
    return false;
  }
  if (tetris[y][x + 2] == 1)
  {
    return false;
  }
  if (tetris[y + 1][x + 3] == 1)
  {
    return false;
  }
  return true;
}
bool Figura1::puedeIrIzq(int x, int y)
{
  if (x < 1)
  {
    return false;
  }
  if (tetris[y][x - 1] == 1)
  {
    return false;
  }
  if (tetris[y + 1][x] == 1)
  {
    return false;
  }
  return true;
}
void Figura1::bajar(int x, int& y)
{
  tetris[y][x] = 0;
  tetris[y][x + 1] = 0;
  tetris[y + 1][x + 2] = 0;
  tetris[y + 1][x] = 1;
  tetris[y + 2][x + 1] = 1;
  tetris[y + 2][x + 2] = 1;
  y++;
}
void Figura1::girar(int x, int y)
{
  tetris[y][x] = 0;
  tetris[y][x + 1] = 0;
  tetris[y][x + 2] = 1;
  tetris[y + 2][x + 1] = 1;
}
void Figura1::irIzq(int& x, int y)
{
  tetris[y][x + 1] = 0;
  tetris[y + 1][x + 2] = 0;
  tetris[y][x - 1] = 1;
  tetris[y + 1][x] = 1;
  x--;
}
void Figura1::irDer(int& x, int y)
{
  tetris[y][x] = 0;
  tetris[y + 1][x + 1] = 0;
  tetris[y][x + 2] = 1;
  tetris[y + 1][x + 3] = 1;
  x++;
}

class Figura2 : public Figura
{
  public:
    ~Figura2() {}
    void crearFigura();
    bool puedeBajar(int x, int y);
    bool puedeGirar(int x, int y);
    bool puedeIrDer(int x, int y);
    bool puedeIrIzq(int x, int y);
    void bajar(int x, int& y);
    void girar(int x, int y);
    void irIzq(int& x, int y);
    void irDer(int& x, int y);
};
void Figura2::crearFigura()
{
  tetris[0][2] = 1;
  tetris[1][1] = 1;
  tetris[1][2] = 1;
  tetris[2][1] = 1;
}
bool Figura2::puedeBajar(int x, int y)
{
  if (y > TAM_F - 4)
  {
    return false;
  }
  if (tetris[y + 3][x + 1] == 1)
  {
    return false;
  }
  if (tetris[y + 2][x + 2] == 1)
  {
    return false;
  }
  return true;
}
bool Figura2::puedeGirar(int x, int y)
{
  if (tetris[y][x] == 1)
  {
    return false;
  }
  if (tetris[y][x + 1] == 1)
  {
    return false;
  }
  return true;
}
bool Figura2::puedeIrDer(int x, int y)
{
  if (x > TAM_C - 4)
  {
    return false;
  }
  if (tetris[y][x + 3] == 1)
  {
    return false;
  }
  if (tetris[y + 1][x + 3] == 1)
  {
    return false;
  } if (tetris[y + 2][x + 2] == 1)
  {
    return false;
  }
  return true;
}
bool Figura2::puedeIrIzq(int x, int y)
{
  if (x < 0)
  {
    return false;
  }
  if (tetris[y][x + 1] == 1)
  {
    return false;
  }
  if (tetris[y + 1][x] == 1)
  {
    return false;
  }
  if (tetris[y + 2][x] == 1)
  {
    return false;
  }
  return true;
}
void Figura2::bajar(int x, int& y)
{
  tetris[y][x + 2] = 0;
  tetris[y + 1][x + 1] = 0;
  tetris[y + 2][x + 2] = 1;
  tetris[y + 3][x + 1] = 1;
  y++;
}
void Figura2::girar(int x, int y)
{
  tetris[y][x + 2] = 0;
  tetris[y + 2][x + 1] = 0;
  tetris[y][x] = 1;
  tetris[y][x + 1] = 1;
}
void Figura2::irIzq(int& x, int y)
{
  tetris[y][x + 2] = 0;
  tetris[y + 1][x + 2] = 0;
  tetris[y + 2][x + 1] = 0;
  tetris[y][x + 1] = 1;
  tetris[y + 1][x] = 1;
  tetris[y + 2][x] = 1;
  x--;
}
void Figura2::irDer(int& x, int y)
{
  tetris[y][x + 2] = 0;
  tetris[y + 1][x + 1] = 0;
  tetris[y + 2][x + 1] = 0;
  tetris[y][x + 3] = 1;
  tetris[y + 1][x + 3] = 1;
  tetris[y + 2][x + 2] = 1;
  x++;
}


void inicializarLeds() {
  LEDS_F[0] = 0;
  LEDS_F[1] = 0;
  LEDS_F[2] = 3;
  LEDS_F[3] = 5;
  LEDS_F[4] = 6;
  LEDS_C[0] = 9;
  LEDS_C[1] = 10;
  LEDS_C[2] = 11;
  pinMode(LEDS_F[2], OUTPUT);
  pinMode(LEDS_F[3], OUTPUT);
  pinMode(LEDS_F[4], OUTPUT);
  pinMode(LEDS_C[0], OUTPUT);
  pinMode(LEDS_C[1], OUTPUT);
  pinMode(LEDS_C[2], OUTPUT);
}

void inicializarTetris() {
  for (int i = 0; i < TAM_F; i++) {
    for (int j = 0; j < TAM_C; j++) {
      tetris[i][j] = 0;
    }
  }
}

void mostrarFila(int fila) {
  for (int i = 2; i < TAM_F; i++) {
    if (i == fila) {
      digitalWrite(LEDS_F[i], LOW);
    } else {
      digitalWrite(LEDS_F[i], HIGH);
    }
  }
  for (int i = 0; i < TAM_C; i++) {
    if (tetris[fila][i] > 0) {
      digitalWrite(LEDS_C[i], HIGH);
    } else {
      digitalWrite(LEDS_C[i], LOW);
    }
  }
}

void mostrarTetris() {
  for (int i = 2; i < TAM_F; i++) {
    mostrarFila(i);
    delay(1);
  }
}

Figura* figura = new Figura1();
int fig = 1;
char input;

void setup() {
  Serial.begin(9600);
  inicializarLeds();
  inicializarTetris();
  x = 0;
  y = 0;
  figura->crearFigura();
}

void loop() {
  mostrarTetris();
  if (Serial.available()) {
    input = Serial.read();
    if (input == 's') {
      if (figura->puedeBajar(x, y))
      {
        figura->bajar(x, y);
      }
    }
    if (input == 'w') {
      if (figura->puedeGirar(x, y))
      {
        figura->girar(x, y);
        delete figura;
        if (fig == 1) {
          figura = new Figura2();
          fig = 2;
        } else {
          figura = new Figura1();
          fig = 1;
        }
      }
    }
  }
}
