
#include <imageprocessing.h>


int main() {
  imagem img;
  img = abrir_imagem("data/cachorro.jpg");
  unsigned int tmp;

  float alpha = 0.998;

  for (int i=0; i<(img.width); i++) {
    for (int j=0; j<(img.height); j++) {
      /* Ganho no canal R */
      tmp = img.r[j*img.width + i] * 2;
      if (tmp > 255) tmp=255;
      img.r[j*img.width + i] = tmp;

      /* Reducao no canal B */
      img.b[j*img.width + i] /= 2;

      /* Blur exponencial no canal G */
      if (i!=0) {
        img.g[j*img.width + i] = (1-alpha)*img.g[j*img.width + i] +(alpha)* img.g[j*img.width + i -1];
      }

    }
  }

  salvar_imagem("cachorro-out.jpg", &img);
  liberar_imagem(&img);
  return 0;
}
