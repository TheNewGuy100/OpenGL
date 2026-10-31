![Foto Bob Esponja](https://i.imgur.com/JhboIM4.png)

# OpenGLSpongeBob

Projeto para praticar OpenGL: uma cena 3D em C++ com [freeglut](https://freeglut.sourceforge.net/), onde o Bob Esponja é montado só com formas simples (cubos, cilindros, esferas e polígonos) e uma curva de Bézier para a boca, sobre um grid de referência com os eixos X, Y e Z.

## O que tem

- **Personagem articulado:** o braço esquerdo balança em uma cadeia ombro, cotovelo, pulso e mão com dedos. O braço direito usa a mesma montagem em pose fixa.
- **Animação por tempo:** a pose do braço vem do relógio, então a velocidade é a mesma em qualquer taxa de quadros.
- **Câmera orbital com pivô móvel:** orbitar, mover e dar zoom, sempre em torno do ponto que você moveu.
- **Painel de controles na janela:** lista os atalhos e pode ser ocultado.
- **Formas coloridas ao fundo:** trocam de cor a cada 1 segundo.

## Controles

| Entrada | Ação |
| --- | --- |
| Mouse esquerdo + arrastar | Orbitar ao redor do personagem |
| Mouse direito + arrastar | Mover a câmera (o ponto de giro acompanha) |
| Scroll ou `W` / `S` | Zoom |
| Setas | Orbitar |
| `A` / `D` / `Q` / `E` | Mover a câmera (o ponto de giro acompanha) |
| `R` | Resetar a câmera |
| `H` | Mostrar ou ocultar o painel de controles |
| `ESC` | Sair |

O painel de controles aparece no canto da janela ao abrir o programa.

## Compilar

Projeto C++ com freeglut. No Dev-C++, abra `Preview.dev`; o linker usa `-lopengl32 -lfreeglut -lglu32`.

Com o compilador da Microsoft (MSVC), defina `_USE_MATH_DEFINES` (o código usa `M_PI`) e crie um arquivo `glut.h` que inclua `<freeglut.h>`, já que o código inclui os dois cabeçalhos pelo nome.

## Arquivos

| Arquivo | Função |
| --- | --- |
| `main.cpp` | Janela, projeção, variáveis globais e laço principal |
| `controllers.h` | Câmera (orbitar, mover, zoom, pivô), mouse e teclado |
| `hud.h` | Painel de controles em 2D |
| `drawCall.h` | Chamada de desenho de cada quadro |
| `tickCall.h` | Temporizador de 16 ms que atualiza a animação |
| `bobSponge.h` | Personagem, braços e a animação do braço |
| `basicObjects.h` | Formas geométricas coloridas ao fundo |
| `colorPicker.h` | Sorteio de cores, uma vez por segundo |
| `grid.h` | Grid de referência e eixos |
