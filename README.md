# Red Dead Rosca

![Capturar](https://github.com/user-attachments/assets/ad73add0-a686-4f96-8e52-2db6d473813a)

Um jogo de duelo 2D no estilo Velho Oeste, com suporte para 2 Jogadores e 2 Modos de Jogo!
Desenvolvido como Projeto de Conclusão de Curso (TCC). O projeto foi criado do zero em C++ com a biblioteca Raylib, com o objetivo de demonstrar de forma didática a implementação de mecânicas de jogos básicos, como movimentação, colisão, estados de jogo, múltiplos modos e uma IA simples.

---

## Índice

* [Sobre o Jogo](#sobre-o-jogo)
* [Funcionalidades](#funcionalidades)
* [Gameplay](#gameplay)
* [Controles](#controles)
* [Como Jogar (Executável)](#como-jogar-executável)
* [Como Compilar (Para Desenvolvedores)](#como-compilar-para-desenvolvedores)
* [Autor](#autor)
* [Licença](#licença)

---

## Sobre o Jogo

**Red Dead Rosca** é um jogo de arena 2D que coloca dois caubóis um contra o outro em um duelo de vida ou morte. O jogo oferece dois modos distintos, testando tanto os reflexos rápidos quanto o raciocínio estratégico dos jogadores.

* **Modo Bang Bang:** Um modo de ação frenética onde os jogadores se movimentam livremente pela arena, pulando e se agachando para desviar de tiros. Cada jogador tem um revólver com 6 balas e precisa recarregar após esvaziar o cilindro. O último a ficar de pé vence a rodada.

* **Modo One Shot:** Um duelo estratégico baseado em turnos simultâneos, inspirado no clássico "Pedra, Papel e Tesoura". A cada rodada, os jogadores escolhem secretamente entre Carregar, Bloquear ou Atirar. Um tiro derrota uma carga, um bloqueio defende um tiro, e uma carga não tem efeito contra um bloqueio. Vence quem enganar e atirar no oponente no momento certo.

O jogo foi desenvolvido inteiramente em **C++** utilizando a biblioteca gráfica **Raylib**.

## Funcionalidades

- **Dois modos de jogo distintos**: Ação em tempo real e estratégia em turnos.
- **Suporte para 1 ou 2 jogadores**: Desafie um amigo no modo multiplayer local ou enfrente uma IA no modo solo.
- **IA Simples**: O oponente no modo solo reage aos movimentos do jogador, como pular e agachar para desviar de tiros.
- **Física Básica**: Inclui gravidade, pulo com altura variável, knockback ao ser atingido, chapéus com física própria e animações de morte.
- **Sistema de Áudio Completo**: Efeitos sonoros para tiros, hits, mortes, navegação de menu e música de fundo para ambientação.
- **Desenvolvido do Zero**: Uma demonstração prática de gerenciamento de estados, renderização, detecção de colisão e input em C++.
  

## Controles

| Ação | Jogador 1 | Jogador 2 |
| :--- | :---: | :---: |
| Mover Esquerda/Direita | **A** / **D** | **J** / **L** |
| Pular | **W** | **I** |
| Agachar | **S** | **K** |
| Atirar | **Espaço** | **M** |
| Emote | **Q** | **O** |
| Pausar | **P** | **P** |

## Como Jogar (Executável)

A maneira mais fácil de jogar é baixar a versão já compilada.

1.  Baixe o arquivo `.zip` da versão mais recente.
2.  Extraia o conteúdo do arquivo `.zip` em uma pasta no seu computador.
3.  **Importante:** Certifique-se de que o arquivo `RedDeadRosca.exe` esteja na **mesma pasta** que todos os arquivos de áudio (`.mp3`) e imagem (`.png`).
4.  Execute o `RedDeadRosca.exe` para jogar!

## Como Compilar (Para Desenvolvedores)

Se você deseja compilar o jogo a partir do código-fonte, siga os passos abaixo.

### Pré-requisitos
* Um compilador C++ (o projeto foi desenvolvido com **MinGW-w64** no Windows).
* A biblioteca **Raylib** configurada para o seu compilador.

### Comando de Compilação

Abra um terminal na pasta do projeto e execute o seguinte comando, substituindo `[caminho para a raylib]` pelo diretório onde sua biblioteca Raylib está localizada:

```bash
g++ RedDeadRosca1.cpp -o RedDeadRosca.exe -I"[caminho para a raylib]\include" -L"[caminho para a raylib]\lib" -lraylib -lopengl32 -lgdi32 -lwinmm
```
Após a compilação, mova os assets (imagens, sons e a fonte) para a mesma pasta do executável gerado.

## Autor

**[Giovani Giachini / Jivanis]**

## Licença
Este projeto foi feito para estudo e tem código aberto, portanto sinta-se à vontade para baixar e modificar.
