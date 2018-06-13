

unsigned int max_sensor = 13;
unsigned int contador_sensor = 0;
unsigned int max_comunicador = 57;
unsigned int contador_comunicador = 0;

int time_flag = false;

void rotina_de_interrupcao_periodica() {
  time_flag = true;
}

void contar(unsigned int *contador, unsigned int max_contador, *((void)func())) {
  (*contador) += 1;
  if ((*contador) >= max_contador) {
    (*contador) = 0;
    func();
  }
}

void f_sensor() {
  ler_sensores();
}

void f_comunicador() {
  realizar_comunicacao();
}

void main() {
  while(1) {
    if (time_flag==true) {
      time_flag = false;
      contar(&contador_sensor, max_sensor, f_sensor);
      contar(&contador_comunicador, max_comunicador, f_comunicador);
    }
  }
  return;
}




