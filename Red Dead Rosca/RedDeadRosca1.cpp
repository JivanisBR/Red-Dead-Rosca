#include "raylib.h"
#include <string>
#include <vector>
#include <cmath> 
#include "clouds.h"

using std::string;

//==================================================================================
// VARIÁVEIS GLOBAIS
//==================================================================================

Texture2D cenario, roleta, bala, p1wins, p2wins, neg, oneshotcontrols, bangbangcontrols, start, p1controls, p2controls, contag, back, pauser;
Texture2D cb1, cb1i, cb2, cb2i, chapeu1, chapeu2, credits, menui, logo, modoi;
Sound hit1, hit2, menu1, menu2, contagen, rico1, rico2, rico3, rico4, tiro1, tiro2, tirof, mort1, mort2, pulo, agach, chapeucai, emot1, emot2;
Music vento;

int cenario_x=0, cenario_y=0;
std::vector<CloudCluster> cloudLayer;
const int NUM_CLOUD_CLUSTERS = 5;
int bot=0;
int p1wins_x=230, p1wins_y=100;
int p2wins_x=200, p2wins_y=100;
int neg_x=350, neg_y=0;
int dnv=0;
Font fnt;

// PLAYER 1
float cb_x = 100, cb_y = 560;
int jmp=0, mun=6, abx=0, dead1=0, fall=0;
int bala_x = 153, bala_y = 608;
float hb1x=110, hb1y=570;
bool r1=false, tomo=false;
int r1c=600, vida=100, passos=0;
int qntsang = 0;

bool sang1 = false, sang2 = false, sang3 = false, sang4 = false, sang5 = false;
// Sangue 1
float sangx1 = 0, sangy1 = 0;
float tamsangx1 = 0, tamsangy1 = 0; 
int contsang1 = 0;
// Sangue 2
float sangx2 = 0, sangy2 = 0;
float tamsangx2 = 0, tamsangy2 = 0; 
int contsang2 = 0;
// Sangue 3
float sangx3 = 0, sangy3 = 0;
float tamsangx3 = 0, tamsangy3 = 0; 
int contsang3 = 0;
// Sangue 4
float sangx4 = 0, sangy4 = 0;
float tamsangx4 = 0, tamsangy4 = 0; 
int contsang4 = 0;
// Sangue 5
float sangx5 = 0, sangy5 = 0;
float tamsangx5 = 0, tamsangy5 = 0; 
int contsang5 = 0;

// PLAYER 2
float cb2_x = 1100, cb2_y = 563;
int jmp2=0, mun2=6, abx2=0, dead2=0, fall2=0;
int bala2_x = 1090, bala2_y = 603;
float hb2x=1140, hb2y=573;
bool r2=false, tomo2=false;
int r2c=600, vida2=100, passos2=0;

bool sang21 = false, sang22 = false, sang23 = false, sang24 = false, sang25 = false;
// Sangue 1
float sang2x1 = 0, sang2y1 = 0;
float tamsang2x1 = 0, tamsang2y1 = 0; 
int cont2sang1 = 0, qntsang2=0;
// Sangue 2
float sang2x2 = 0, sang2y2 = 0;
float tamsang2x2 = 0, tamsang2y2 = 0; 
int cont2sang2 = 0;
// Sangue 3
float sang2x3 = 0, sang2y3 = 0;
float tamsang2x3 = 0, tamsang2y3 = 0; 
int cont2sang3 = 0;
// Sangue 4
float sang2x4 = 0, sang2y4 = 0;
float tamsang2x4 = 0, tamsang2y4 = 0; 
int cont2sang4 = 0;
// Sangue 5
float sang2x5 = 0, sang2y5 = 0;
float tamsang2x5 = 0, tamsang2y5 = 0; 
int cont2sang5 = 0;

// VARIÁVEIS DOS CHAPÉUS
float chapeu1_x = 102, chapeu1_y = 565;
float chapeu1_vel_x = 0.0f, chapeu1_vel_y = 0.0f;
bool tem_chapeu1 = true;
bool chapeu1_caindo = false;
float chapeu2_x = 1129, chapeu2_y = 563;
float chapeu2_vel_x = 0.0f, chapeu2_vel_y = 0.0f;
bool tem_chapeu2 = true;
bool chapeu2_caindo = false;
const float GRAVIDADE_CHAPEU = 0.2f;

// MENU
int tamtelax=1200, tamtelay=700;
bool menu=true;
int cdpause=0, pisca=0;
int opt=1;
bool creds = false;
bool modo = false;
bool quit = false;
bool bangbang=false;
bool oneshot=false;
bool solo = false;
bool pause = false;
int ldr=0;

// MODO BANGBANG
const int MAX_BALAS = 10;
int bala1v_x[MAX_BALAS], bala1v_y[MAX_BALAS], bala1_ativo[MAX_BALAS];
int bala2v_x[MAX_BALAS], bala2v_y[MAX_BALAS], bala2_ativo[MAX_BALAS];
int direcao_bala1[MAX_BALAS], direcao_bala2[MAX_BALAS];
int y_inicial_bala1[MAX_BALAS], y_inicial_bala2[MAX_BALAS];
int cooldown1 = 0, cooldown2 = 0;
int reload1 = 0, reload2 = 0;
const int VELOCIDADE_BALA = 15;
const int DANOO = 25;
bool espaco_pressionado = false;
bool m_pressionado = false;
bool inv1=false, inv2=false;
int win1=0, win2=0;
bool bangmenu=false;
int bala1_lifetime[MAX_BALAS];
int bala2_lifetime[MAX_BALAS];

// Variáveis de pulo para Player 1
float vel_y1 = 0.0f;
bool pulando1 = false;
const float GRAVIDADE = 0.9f;
const float FORCA_PULO_INICIAL = 15.0f;
const float FORCA_PULO_SUSTENTADA = 0.4f;
const float CHAO = 560.0f;

// Variáveis de pulo para Player 2
float vel_y2 = 0.0f;
bool pulando2 = false;

// Variáveis de knockback
float vel_x_knock1 = 0.0f;
float vel_x_knock2 = 0.0f;
const float KNOCKBACK_FORCA = 5.0f;
const float DESACELERACAO_KNOCK = 0.2f;

// Variáveis de morte
float vel_x_morte1 = 0.0f, vel_y_morte1 = 0.0f;
bool morrendo1 = false;
float vel_x_morte2 = 0.0f, vel_y_morte2 = 0.0f;
bool morrendo2 = false;
const float EMPURRAO_CHAO = 5.0f;
const float EMPURRAO_AR_X = 7.0f;
const float EMPURRAO_AR_Y = -8.0f;
const float DESACELERACAO_X = 0.2f;

// Variáveis de agachamento
bool agachado1 = false;
bool agachado2 = false;

// Particulas de Sangue (Velocidades)
float sang_vel_x1 = 0.0f, sang_vel_y1 = 0.0f;
float sang_vel_x2 = 0.0f, sang_vel_y2 = 0.0f;
float sang_vel_x3 = 0.0f, sang_vel_y3 = 0.0f;
float sang_vel_x4 = 0.0f, sang_vel_y4 = 0.0f;
float sang_vel_x5 = 0.0f, sang_vel_y5 = 0.0f;
float sang2_vel_x1 = 0.0f, sang2_vel_y1 = 0.0f;
float sang2_vel_x2 = 0.0f, sang2_vel_y2 = 0.0f;
float sang2_vel_x3 = 0.0f, sang2_vel_y3 = 0.0f;
float sang2_vel_x4 = 0.0f, sang2_vel_y4 = 0.0f;
float sang2_vel_x5 = 0.0f, sang2_vel_y5 = 0.0f;
const float GRAVIDADE_PARTICULA = 0.5f;

//MODO ONESHOT
int chose=0;

// ESTADO DE JOGO
bool bangbang_iniciando = false;
bool oneshot_iniciando = false;
int timer_inicio = 0;

// IA (BANGBANG)
int ia_timer = 0;
int ia_acao = 0; 
int ia_direcao = 1;
int ia_distancia_reacao = 300;
bool ia_pulando_alto = false;
int ia_timer_pulo_alto = 0;
bool ia_alvo_agachado = false;
int ia_timer_reacao = 0;

// Emotes
bool emote1=false, emote2=false;
int contemt1=0, contemt2=0;

// MODO ONE SHOT
int os_timer = 300;
int os_estado = 0;
int os_p1_escolha = 0, os_p2_escolha = 0;
int os_p1_mun = 0, os_p2_mun = 0;
string os_acao_texto1 = "", os_acao_texto2 = "";
int os_timer_mensagem = 0;
bool oneshotmenu=false;

// Nomes
bool colocarnomes=false;
string nome1="", nome2="";
int jogador_atual = 1;
bool nomes_confirmados = false;


//==================================================================================
// DECLARAÇÃO DAS FUNÇÕES
//==================================================================================
void adicionar_caracter(string c);
void atirar_bot();
void atualizar_chapeus();
void controle();
void bangbanger(); 
void oneshoter(); 
void desenhar(); 
void TocarSomHitAleatorio();
void TocarSomMenuAleatorio();
void TocarSomRicocheteAleatorio();

//==================================================================================
// FUNÇÃO PRINCIPAL (inicio)
//==================================================================================
int main(void)
{
    InitWindow(1200, 700, "Red Dead Rosca");
    InitAudioDevice();
    SetTargetFPS(120);

    // Carregando todas as texturas
    fnt = LoadFont("CHINESER.ttf");
    cenario = LoadTexture("senaryo t.png");
    roleta = LoadTexture("roleta.png");
    bala = LoadTexture("bala.png");
    p1wins = LoadTexture("viado 1 wins.png");
    p2wins = LoadTexture("viado 2 wins.png");
    neg = LoadTexture("negao da pica cort.png");
    oneshotcontrols = LoadTexture("ONESHOT CONTROLS.png");
    bangbangcontrols = LoadTexture("BANGBANG CONTROLS.png");
    start = LoadTexture("START.png");
    p1controls = LoadTexture("player1controls.png");
    p2controls = LoadTexture("player2controls.png");
    contag = LoadTexture("3 2 1.png");
    back = LoadTexture("BACK.png");
    pauser = LoadTexture("pause.png");
    cb1 = LoadTexture("cb1 completo.png");
    cb1i = LoadTexture("cb1inv.png");
    cb2 = LoadTexture("cb2 completo.png");
    cb2i = LoadTexture("cb2inv.png");
    chapeu1 = LoadTexture("chapeu1.png");
    chapeu2 = LoadTexture("chapeu2.png");
    credits = LoadTexture("red dead rosca credits.png");
    menui = LoadTexture("menurosca1.png");
    logo = LoadTexture("RDR logo.png");
    modoi = LoadTexture("selesao de modo rosca.png");

    //Audios
    hit1 = LoadSound("hit1.mp3");
    hit2 = LoadSound("hit2.mp3");
    menu1 = LoadSound("menu1.mp3");
    menu2 = LoadSound("menu2.mp3");
    contagen = LoadSound("contagem regressiva.mp3");
    rico1 = LoadSound("ricochet1.mp3");
    rico2 = LoadSound("ricochet2.mp3");
    rico3 = LoadSound("ricochet3.mp3");
    rico4 = LoadSound("ricochet4.mp3");
    tiro1 = LoadSound("tiro1.mp3");
    tiro2 = LoadSound("tiro2.mp3");
    tirof = LoadSound("tiro final.mp3");
    mort1 = LoadSound("mort1.mp3");
    mort2 = LoadSound("mort2.mp3");
    pulo = LoadSound("pulo.mp3");
    agach = LoadSound("agacha.mp3");
    vento = LoadMusicStream("vento.mp3");
    PlayMusicStream(vento);
    chapeucai = LoadSound("chapeucai.mp3");
    emot1 = LoadSound("emote1.mp3");
    //fundo = LoadMusicStream("fundo.mp3");

    // Nuvens
    cloudLayer.clear(); 
    for (int i = 0; i < NUM_CLOUD_CLUSTERS; i++) {
        cloudLayer.push_back(CloudCluster());
    }

    // Loop principal do jogo
    while(!quit && !WindowShouldClose()){
        UpdateMusicStream(vento);
        controle();
        desenhar();
        for (auto& cluster : cloudLayer) {
            cluster.Update();
        }
    }
    
    // Descarregando texturas
    UnloadFont(fnt);
    UnloadTexture(cenario); UnloadTexture(roleta); UnloadTexture(bala); UnloadTexture(p1wins);
    UnloadTexture(p2wins); UnloadTexture(neg); UnloadTexture(oneshotcontrols); UnloadTexture(bangbangcontrols);
    UnloadTexture(start); UnloadTexture(p1controls); UnloadTexture(p2controls); UnloadTexture(contag);
    UnloadTexture(back); UnloadTexture(pauser); UnloadTexture(cb1); UnloadTexture(cb1i);
    UnloadTexture(cb2); UnloadTexture(cb2i); UnloadTexture(chapeu1); UnloadTexture(chapeu2);
    UnloadTexture(credits); UnloadTexture(menui); UnloadTexture(logo); UnloadTexture(modoi);
    UnloadSound(hit1); UnloadSound(hit2); UnloadSound(menu1); UnloadSound(menu2);
    UnloadSound(contagen); UnloadSound(rico1); UnloadSound(rico2); UnloadSound(rico3); UnloadSound(rico4);
    UnloadSound(tiro1); UnloadSound(tiro2); UnloadSound(tirof); UnloadSound(mort1); UnloadSound(mort2);
    UnloadSound(pulo); UnloadSound(agach); UnloadSound(chapeucai); UnloadSound(emot1);
    UnloadMusicStream(vento);

    CloseAudioDevice();
    CloseWindow();
    return 0;
}

//==================================================================================
// DEFINIÇÃO DAS FUNÇÕES 
//==================================================================================

void adicionar_caracter(string c) {
    if (jogador_atual == 1 && nome1.length() < 20) {
        nome1 = nome1 + c;
    }
    cdpause = 0;
    if (jogador_atual == 2 && nome2.length() < 20) {
        nome2 = nome2 + c;
    }
    cdpause = 0; 
}

void TocarSomHitAleatorio() {
    if (GetRandomValue(0, 1) == 0) {
        PlaySound(hit1);
    } else {
        PlaySound(hit2);
    }
}

void TocarSomMenuAleatorio() {
    if (GetRandomValue(0, 1) == 0) {
        PlaySound(menu1);
    } else {
        PlaySound(menu2);
    }
}

void TocarSomRicocheteAleatorio() {
    int som = GetRandomValue(1, 4);
    if (som == 1) PlaySound(rico1);
    if (som == 2) PlaySound(rico2);
    if (som == 3) PlaySound(rico3);
    if (som == 4) PlaySound(rico4);
}

void atirar_bot() {
    if (mun2 > 0 && cooldown2 == 0 && r2 == false && timer_inicio<1 && pause==false && dead2==0) {
        for (int i = 0; i < MAX_BALAS; i++) {
            if (bala2_ativo[i] == 0) {
                bala2v_x[i] = cb2_x - 10;
                if (abx2 == 1) {
                    bala2v_y[i] = cb2_y + 70;
                } else {
                    bala2v_y[i] = cb2_y + 48;
                }
                y_inicial_bala2[i] = bala2v_y[i];
                bala2_ativo[i] = 1;
                mun2--;
                if (inv2 == false) {
                    direcao_bala2[i] = -1;
                } else {
                    direcao_bala2[i] = 1;
                }
                bala2_lifetime[i] = 240;
                PlaySound(tiro2);
                cooldown2 = 60; 
                break;
            }
        }
    }
}

void atualizar_chapeus() {
    if (tem_chapeu1 && pause==false) {
        float alvo_x1, alvo_y1;
        if(agachado1){
            if(!inv1){ alvo_x1 = cb_x + 15; alvo_y1 = cb_y+30; }
            else{ alvo_x1 = cb_x + 37; alvo_y1 = cb_y+32; }
        } else if(emote1){
            if(contemt1>=20 && contemt1<40){ 
                if(!inv1){ alvo_x1 = cb_x + 7; alvo_y1 = cb_y+6; }
                else{ alvo_x1 = cb_x+15; alvo_y1 = cb_y+6; }
            }
            else if(contemt1>=40 && contemt1<=60){
                if(!inv1){ alvo_x1 = cb_x + 2; alvo_y1 = cb_y+5; }
                else{ alvo_x1 = cb_x+10; alvo_y1 = cb_y+6; }
            }
            else {
                if(!inv1){ alvo_x1 = cb_x + 2; alvo_y1 = cb_y+5; }
                else{ alvo_x1=cb_x+17; alvo_y1 = cb_y+5; }
            }
        } else if(passos>=15){
            if(!inv1){ alvo_x1 = cb_x + 4; alvo_y1 = cb_y+7; }
            else{ alvo_x1=cb_x+34; alvo_y1 = cb_y+8; }
        } else {
            if(!inv1){ alvo_x1 = cb_x + 2; alvo_y1 = cb_y+5; }
            else{ alvo_x1=cb_x+32; alvo_y1 = cb_y+5; }
        }

        bool chapeu_esta_na_cabeca = (fabsf(chapeu1_y - alvo_y1) < 5.0f);

        if (chapeu_esta_na_cabeca && pulando1 && vel_y1 < 0.0f && pause==false) {
            chapeu1_vel_y = vel_y1;
        }
        chapeu1_vel_y += GRAVIDADE_CHAPEU;
        chapeu1_y += chapeu1_vel_y;
        if (chapeu1_y > alvo_y1) {
            chapeu1_y = alvo_y1;
            chapeu1_vel_y = 0.0f;
        }
        chapeu1_x = alvo_x1;
        if(tem_chapeu1==true && dead1==1 && pause==false){
            if(!inv1){ chapeu1_x=cb_x+30; } else{ chapeu1_x=cb_x+20; }
            tem_chapeu1=false;
            chapeu1_caindo=true;
        }
        if(chapeu1_y<=315){
            chapeu1_y=315;
        }
    } else if (chapeu1_caindo && pause==false) { 
        PlaySound(chapeucai);
        chapeu1_x += chapeu1_vel_x;
        chapeu1_y += chapeu1_vel_y;
        chapeu1_vel_y += GRAVIDADE;
        if (chapeu1_y >= CHAO + 105) {
            chapeu1_y = CHAO + 105;
            chapeu1_caindo = false;
        }
    }
    
    if (tem_chapeu2) {
        float alvo_x2, alvo_y2;
        if(agachado2){
            if(!inv2){ alvo_x2 = cb2_x+33; alvo_y2 = cb2_y+32; }
            else{ alvo_x2 = cb2_x+12; alvo_y2 = cb2_y+29; }
        } else if(passos2<=15){
            if(!inv2){ alvo_x2 = cb2_x + 29; alvo_y2 = cb2_y; }
            else{ alvo_x2 = cb2_x-1; alvo_y2 = cb2_y; }
        } else {
            if(!inv2){ alvo_x2 = cb2_x + 28; alvo_y2 = cb2_y+1; }
            else{ alvo_x2 = cb2_x + 7; alvo_y2 = cb2_y+1; }
        }

        bool chapeu2_esta_na_cabeca = (fabsf(chapeu2_y - alvo_y2) < 5.0f);
        if (chapeu2_esta_na_cabeca && pulando2 && vel_y2 < 0.0f && pause==false) {
            chapeu2_vel_y = vel_y2;
        }
        chapeu2_vel_y += GRAVIDADE_CHAPEU;
        chapeu2_y += chapeu2_vel_y;
        if (chapeu2_y > alvo_y2) {
            chapeu2_y = alvo_y2;
            chapeu2_vel_y = 0.0f;
        }
        chapeu2_x = alvo_x2;
        if(tem_chapeu2==true && dead2==1 && pause==false){
            if(!inv2){ chapeu2_x=cb2_x+45; } else{ chapeu2_x=cb2_x-15; }
            tem_chapeu2=false;
            chapeu2_caindo=true;
        }
        if(chapeu2_y<=315){
            chapeu2_y=315;
        }
    }
    else if (chapeu2_caindo && pause==false) {
        PlaySound(chapeucai);
        chapeu2_x += chapeu2_vel_x;
        chapeu2_y += chapeu2_vel_y;
        chapeu2_vel_y += GRAVIDADE;
        if (chapeu2_y >= CHAO + 105) {
            chapeu2_y = CHAO + 105;
            chapeu2_caindo = false;
        }
    }
    if(tem_chapeu2==true && emote2==true){
        if(contemt2>=0 && contemt2<=20){
            if(!inv2){ chapeu2_x=cb2_x+20; }
            else{ chapeu2_x=cb2_x-1; }
        }
        if(contemt2>=20 && contemt2<=40){
            if(!inv2){ chapeu2_x=cb2_x+10; }
            else{ chapeu2_x=cb2_x-1; }
        }
        if(contemt2>=40 && contemt2<=60){
            if(!inv2){ chapeu2_x=cb2_x+12; chapeu2_y=cb2_y+2; }
            else{ chapeu2_x=cb2_x-3; chapeu2_y=cb2_y+2; }
        }
    }
}
void controle(){
    if(menu==true){
        cdpause++;
        if(IsKeyPressed(KEY_S) && cdpause>50){
            TocarSomMenuAleatorio();
            opt++;
            cdpause=0;
        }
        if(opt>4){
            opt=1;
        }
        if(IsKeyPressed(KEY_W) && cdpause>50){
            TocarSomMenuAleatorio();
            opt--;
            cdpause=0;
        }
        if(opt<1){
            opt=4;
        }
        if(opt==1 && IsKeyPressed(KEY_SPACE) && cdpause>50){
            PlaySound(tirof);
            modo=true;
            menu=false;
            solo=true;
            cdpause=0;
            opt=1;
        }
        if(menu==true && opt==2 && IsKeyPressed(KEY_SPACE) && cdpause>50){
            PlaySound(tirof);
            colocarnomes=true;
            menu=false;
            solo=false;
            cdpause=0;
            opt=1;
        }
        if(opt==3 && IsKeyPressed(KEY_SPACE)){
            PlaySound(tirof);
            creds=true;
        }
        if(creds==true && IsKeyPressed(KEY_BACKSPACE)){
            PlaySound(tirof);
            creds=false;
        }
        if(opt==4 && IsKeyPressed(KEY_SPACE)){
            PlaySound(tirof);
            quit=true;
        }
    }
    if(colocarnomes==true){
        cdpause++;
        if (!nomes_confirmados) {
            if (cdpause > 40) {
                if (IsKeyPressed(KEY_ENTER)) {
                    PlaySound(tirof);
                    if (jogador_atual == 1) {
                        jogador_atual = 2;
                    } else {
                        nomes_confirmados = true;
                    }
                    cdpause = 0;
                }
                else if (IsKeyPressed(KEY_BACKSPACE)) { 
                    if (jogador_atual == 1) {
                        if (!nome1.empty()) {
                            nome1.pop_back();
                        }
                    } 
                    else if (jogador_atual == 2) {
                        if (!nome2.empty()) {
                            nome2.pop_back();
                        }
                    }
                    cdpause = 0;
                }
                else if (IsKeyPressed(KEY_A)) { adicionar_caracter("A"); } else if (IsKeyPressed(KEY_B)) { adicionar_caracter("B"); }
                else if (IsKeyPressed(KEY_C)) { adicionar_caracter("C"); } else if (IsKeyPressed(KEY_D)) { adicionar_caracter("D"); }
                else if (IsKeyPressed(KEY_E)) { adicionar_caracter("E"); } else if (IsKeyPressed(KEY_F)) { adicionar_caracter("F"); }
                else if (IsKeyPressed(KEY_G)) { adicionar_caracter("G"); } else if (IsKeyPressed(KEY_H)) { adicionar_caracter("H"); }
                else if (IsKeyPressed(KEY_I)) { adicionar_caracter("I"); } else if (IsKeyPressed(KEY_J)) { adicionar_caracter("J"); }
                else if (IsKeyPressed(KEY_K)) { adicionar_caracter("K"); } else if (IsKeyPressed(KEY_L)) { adicionar_caracter("L"); }
                else if (IsKeyPressed(KEY_M)) { adicionar_caracter("M"); } else if (IsKeyPressed(KEY_N)) { adicionar_caracter("N"); }
                else if (IsKeyPressed(KEY_O)) { adicionar_caracter("O"); } else if (IsKeyPressed(KEY_P)) { adicionar_caracter("P"); }
                else if (IsKeyPressed(KEY_Q)) { adicionar_caracter("Q"); } else if (IsKeyPressed(KEY_R)) { adicionar_caracter("R"); }
                else if (IsKeyPressed(KEY_S)) { adicionar_caracter("S"); } else if (IsKeyPressed(KEY_T)) { adicionar_caracter("T"); }
                else if (IsKeyPressed(KEY_U)) { adicionar_caracter("U"); } else if (IsKeyPressed(KEY_V)) { adicionar_caracter("V"); }
                else if (IsKeyPressed(KEY_W)) { adicionar_caracter("W"); } else if (IsKeyPressed(KEY_X)) { adicionar_caracter("X"); }
                else if (IsKeyPressed(KEY_Y)) { adicionar_caracter("Y"); } else if (IsKeyPressed(KEY_Z)) { adicionar_caracter("Z"); }
                else if (IsKeyPressed(KEY_SPACE)) { adicionar_caracter(" "); } else if (IsKeyPressed(KEY_ZERO)) { adicionar_caracter("0"); }
                else if (IsKeyPressed(KEY_ONE)) { adicionar_caracter("1"); } else if (IsKeyPressed(KEY_TWO)) { adicionar_caracter("2"); }
                else if (IsKeyPressed(KEY_THREE)) { adicionar_caracter("3"); } else if (IsKeyPressed(KEY_FOUR)) { adicionar_caracter("4"); }
                else if (IsKeyPressed(KEY_FIVE)) { adicionar_caracter("5"); } else if (IsKeyPressed(KEY_SIX)) { adicionar_caracter("6"); }
                else if (IsKeyPressed(KEY_SEVEN)) { adicionar_caracter("7"); } else if (IsKeyPressed(KEY_EIGHT)) { adicionar_caracter("8"); }
                else if (IsKeyPressed(KEY_NINE)) { adicionar_caracter("9"); }
            }
        }
        if(nomes_confirmados==true){
            colocarnomes=false;
            modo=true;
        }
    }
    if(modo==true){
        cdpause++;
        if(IsKeyPressed(KEY_BACKSPACE)){
            PlaySound(tirof);
            modo=false;
            colocarnomes=false;
            menu=true;
        }
        if(IsKeyPressed(KEY_S) && cdpause>50){
            TocarSomMenuAleatorio();
            opt++;
            cdpause=0;
        }
        if(opt>2){
            opt=1;
        }
        if(IsKeyPressed(KEY_W) && cdpause>50){
            TocarSomMenuAleatorio();
            opt--;
            cdpause=0;
        }
        if(opt<1){
            opt=2;
        }
        if(opt==1 && IsKeyPressed(KEY_SPACE) && cdpause>50){
            PlaySound(tirof);
            menu=false;
            modo=false;
            bangmenu=true;
            oneshot=false;
            cdpause=0;
        }
        if(opt==2 && IsKeyPressed(KEY_SPACE) && cdpause>50){
            PlaySound(tirof);
            menu=false;
            modo=false;
            oneshotmenu=true;
            bangbang=false;
            cdpause=0;
            os_estado = 0;
        }
    }
    if(bangmenu==true){
        if(IsKeyPressed(KEY_SPACE) && cdpause>50){
            PlaySound(tirof);
            bangmenu=false;
            bangbang=true;
            timer_inicio = 300;
            PlaySound(contagen);
            tem_chapeu1 = true;
            tem_chapeu2 = true;
            dead1 = 0;
            dead2 = 0;
            fall = 0;
            fall2 = 0;
            win1 = 0;
            win2 = 0;
            reload1 = 0;
            reload2 = 0;
            mun = 6;
            mun2 = 6;
        }
        if(IsKeyPressed(KEY_BACKSPACE)){
            PlaySound(tirof);
            bangmenu=false;
            modo=true;
        }
    }
    if(oneshotmenu==true){
        if(IsKeyPressed(KEY_SPACE) && cdpause>50){
            PlaySound(tirof);
            oneshotmenu=false;
            oneshot=true;
        }
        if(IsKeyPressed(KEY_BACKSPACE)){
            PlaySound(tirof);
            oneshotmenu=false;
            modo=true;
        }
    }
    if(IsKeyPressed(KEY_P) && menu==false && cdpause>100 && modo==false && bangmenu==false && oneshotmenu==false){
        PlaySound(tirof);
        pause=true;
        timer_inicio=300;
        cdpause=0;
    }
    if(IsKeyPressed(KEY_P) && menu==true && cdpause>100 && modo==false){
        PlaySound(tirof);
        pause=false;
        cdpause=0;
    }
    if(pause==true){
        StopSound(contagen);
        if(IsKeyPressed(KEY_S) && cdpause>50){
            TocarSomMenuAleatorio();
            opt++;
            cdpause=0;
        }
        if(opt>2){
            opt=1;
            cdpause=0;
        }
        if(IsKeyPressed(KEY_W) && cdpause>50){
            TocarSomMenuAleatorio();
            opt--;
            cdpause=0;
        }
        if(opt<1){
            opt=2;
            cdpause=0;
        }
        if(opt==1 && IsKeyPressed(KEY_SPACE) && cdpause>50){
            PlaySound(tirof);
            pause=false;
            cdpause=0;
        }
        if(opt==2 && IsKeyPressed(KEY_SPACE) && cdpause>50){
            PlaySound(tirof);
            pause=false;
            menu=true;
            cdpause=0;
            opt=1;
            nomes_confirmados=false;
            jogador_atual=1;
            cb_x=100; 
            cb_y=560; 
            mun=6; 
            bala_x=cb_x+53; 
            hb1x=cb_x+10; 
            r1c=600; 
            r1=false;
            vida=100; 
            chapeu1_x=cb_x+2;
            chapeu1_y=cb_y+5;
            tem_chapeu1=true;
            nome1="";
            cb2_x=1100; 
            cb2_y=563; 
            mun2=6; 
            bala2_x=cb2_x+53; 
            hb2x=cb2_x+10; 
            r2c=600; 
            r2=false;
            vida2=100; 
            tem_chapeu2=true;
            chapeu2_x=cb2_x+29;
            chapeu2_y=cb2_y;
            nome2="";
            reload1=0;
            reload2=0;
            for (int i = 0; i < MAX_BALAS; i++) {
                bala1_ativo[i] = 0;
                bala2_ativo[i] = 0;
            }
        }
    }
    cdpause++;
    pisca++;
    
    if(pause==false && modo==false && menu==false && bangmenu==false && oneshotmenu==false && bangbang==true){
        if(timer_inicio>0 && colocarnomes==false){
            timer_inicio--;
        }
        if(IsKeyDown(KEY_Q)){
            emote1=true;
            PlaySound(emot1);
        }
        if(emote1==true){
            contemt1++;
            if(contemt1>60){
                contemt1=0;
            }
        }
        if(IsKeyDown(KEY_O)){
            emote2=true;
        }
        if(emote2==true){
            contemt2++;
            if(contemt2>60){
                contemt2=20;
            }
        }
        if(timer_inicio<1 && colocarnomes==false){
            if(IsKeyDown(KEY_A) || IsKeyDown(KEY_D) && dead1==0 && abx==0){
                passos++; emote1=false; contemt1=0; StopSound(emot1);
                if(IsKeyDown(KEY_A) && dead1==0 && abx==0){
                    cb_x-=3; hb1x-=3; 
                }
                 if(IsKeyDown(KEY_D) && dead1==0 && abx==0){
                    cb_x+=3; hb1x+=3;
                 }
            }
            else{
                passos=0;
            }
            
            if(IsKeyDown(KEY_S) && dead1==0){
                if (agachado1 == false) {
                    PlaySound(agach);
                }
                StopSound(emot1); emote1=false; contemt1=0; agachado1 = true; abx = 1; if(sang1==false){ sangy1=cb_y+70; }
                for (int i = 0; i < MAX_BALAS; i++) {
                    if (bala2_ativo[i] == 1 && tem_chapeu1) {
                        int dist = fabsf(bala2v_x[i] - cb_x);
                        if (dist < 150 && bala2v_y[i]<630) { 
                            tem_chapeu1 = false; chapeu1_caindo = true;
                            chapeu1_vel_x = GetRandomValue(2, 15) * (direcao_bala2[i]*3);
                            chapeu1_vel_y = GetRandomValue(-2, 2)*GRAVIDADE_CHAPEU;
                            break;
                        }
                    }
                }
            }
            else { agachado1 = false; abx = 0; if(sang1==false){ sangy1=cb_y+40; } }
            if(mun < 1 && dead1==0){ r1 = true; }
            if(r1 == true){ r1c--; }
            if(r1c <= 0){ r1 = false; mun = 6; r1c = 600; }
            if(cb_x>1150){ cb_x=1150; hb1x=cb_x+10; sangx1=cb_x-30; }
            if(cb_x<0){ cb_x=0; hb1x=cb_x+10; sangx1=cb_x-30; }
            if(cb_y+3>=cb2_y && cb_y<=cb2_y+100 && cb_x>cb2_x && cb_x<cb2_x+10){ cb_x=cb2_x; hb1x=cb_x+10; sangx1=cb_x-30; }
            if(cb_y+3>=cb2_y && cb_y<=cb2_y+100 && cb_x+50>cb2_x+50 && cb_x<cb2_x+50){ cb_x=cb2_x+50; hb1x=cb_x+10; sangx1=cb_x-30; }
            if(IsKeyDown(KEY_W) && !pulando1 && cb_y >= CHAO && dead1==0){ PlaySound(pulo); pulando1 = true; vel_y1 = -FORCA_PULO_INICIAL; }
            if(pulando1 && pause==false){
                emote1=false; contemt1=0;
                if(IsKeyDown(KEY_W) && vel_y1 < 0){ vel_y1 -= FORCA_PULO_SUSTENTADA; }
                cb_y += vel_y1;
                vel_y1 += GRAVIDADE;
                if(cb_y >= CHAO){ cb_y = CHAO; vel_y1 = 0.0; pulando1 = false; }
            }
            if(agachado1){ hb1y = cb_y + 10 + 60; } else { hb1y = cb_y + 10; }

            if(solo==false){
                if(IsKeyDown(KEY_J) || IsKeyDown(KEY_L) && dead2==0 && abx2==0){
                    passos2++; emote2=false; contemt2=0;
                    if(IsKeyDown(KEY_J) && dead2==0 && abx2==0){
                        cb2_x-=3; hb2x-=3; 
                    }
                     if(IsKeyDown(KEY_L) && dead2==0 && abx2==0){
                        cb2_x+=3; hb2x+=3;
                     }
                }
                else{
                    passos2=0;
                }
                
                if(IsKeyDown(KEY_K) && dead2==0){
                   if (agachado2 == false) {
                        PlaySound(agach);
                    }
                emote2=false; contemt2=0; agachado2 = true; abx2 = 1;
                    for (int i = 0; i < MAX_BALAS; i++) {
                        if (bala1_ativo[i] == 1 && tem_chapeu2) {
                            int dist = fabsf(bala1v_x[i] - cb2_x);
                            if (dist < 150 && bala1v_y[i]<630) {
                                tem_chapeu2 = false; chapeu2_caindo = true;
                                chapeu2_vel_x = GetRandomValue(2, 5) * (direcao_bala1[i]*3);
                                chapeu2_vel_y = GetRandomValue(-2, 2);
                                break;
                            }
                        }
                    }
                }
                else { agachado2 = false; abx2 = 0; }
                if(IsKeyDown(KEY_I) && !pulando2 && cb2_y >= CHAO && pause==false && dead2==0){ PlaySound(pulo); emote2=false; contemt2=0; pulando2 = true; vel_y2 = -FORCA_PULO_INICIAL; }
            }
            else { 
                if (dead2 == 0 && pause==false) {
                    if (agachado1 && !ia_alvo_agachado) { ia_alvo_agachado = true; ia_timer_reacao = GetRandomValue(20, 50); }
                    else if (!agachado1 && ia_alvo_agachado) { ia_alvo_agachado = false; ia_timer_reacao = GetRandomValue(20, 50); }
                    if (ia_timer_reacao > 0) { ia_timer_reacao--; }
                    else if (ia_alvo_agachado) { agachado2 = true; abx2 = 1; atirar_bot(); }
                    else {
                        agachado2 = false; abx2 = 0;
                        bool deve_esquivar = false;
                        for (int i = 0; i < MAX_BALAS; i++) {
                            if (bala1_ativo[i] == 1) {
                                bool bala_vindo = (direcao_bala1[i] == 1 && bala1v_x[i] < cb2_x) || (direcao_bala1[i] == -1 && bala1v_x[i] > cb2_x);
                                if (bala_vindo) {
                                    int distancia_bala = fabsf(bala1v_x[i] - (cb2_x + 25));
                                    if (distancia_bala <= ia_distancia_reacao) { deve_esquivar = true; break; }
                                }
                            }
                        }
                        if (deve_esquivar) {
                            if (GetRandomValue(0, 1) == 0 && !pulando2) { pulando2 = true; vel_y2 = -FORCA_PULO_INICIAL; ia_pulando_alto = true; ia_timer_pulo_alto = 20; } 
                            else { agachado2 = true; abx2 = 1; }
                        }
                        else {
                            ia_timer--;
                            if (ia_timer <= 0) {
                                ia_acao = GetRandomValue(0, 12);
                                ia_timer = GetRandomValue(40, 100);
                                if (ia_acao >= 3 && ia_acao <= 6) { ia_direcao = GetRandomValue(0, 1) * 2 - 1; }
                            }
                            if ((ia_acao >= 3 && ia_acao <= 6)) {
                                if (cb2_x <= 0) { ia_direcao = 1; } else if (cb2_x >= 1150) { ia_direcao = -1; }
                                cb2_x += (3 * ia_direcao);
                                passos2++;
                            }
                            if (ia_acao >= 9) {
                                int distancia = cb_x - cb2_x;
                                bool na_mira = (distancia < 0 && inv2 == false) || (distancia > 0 && inv2 == true);
                                if (na_mira) { atirar_bot(); }
                            }
                        }
                    }
                    hb2x = cb2_x + 40;
                }
            }

            if(mun2 < 1 && dead2==0){ r2 = true; }
            if(r2 == true && pause==false){ r2c--; }
            if(r2c <= 0){ r2 = false; mun2 = 6; r2c = 600; }
            if(cb2_x>1150){ cb2_x=1150; hb2x=cb2_x+40; }
            if(cb2_x<0){ cb2_x=0; hb2x=cb2_x+40; }
            if(cb2_y+3>=cb_y && cb2_y<=cb_y+100 && cb2_x+50>cb_x && cb2_x+50<cb_x+10){ cb2_x=cb_x-50; hb2x=cb2_x+40; }
            if(cb2_y+3>=cb_y && cb2_y<=cb_y+100 && cb2_x-3<=cb_x+50 && cb2_x+50>cb_x+50){ cb2_x = cb_x + 50; hb2x = cb2_x + 40; }
            
            if(pulando2 && pause==false){
                if (solo) {
                    if (ia_pulando_alto && ia_timer_pulo_alto > 0) { vel_y2 -= FORCA_PULO_SUSTENTADA; ia_timer_pulo_alto--; } 
                    else { ia_pulando_alto = false; }
                } else {
                    if (IsKeyDown(KEY_I) && vel_y2 < 0) { vel_y2 -= FORCA_PULO_SUSTENTADA; }
                }
                cb2_y += vel_y2;
                vel_y2 += GRAVIDADE;
                if(cb2_y >= CHAO){ cb2_y = CHAO; vel_y2 = 0.0; pulando2 = false; ia_pulando_alto = false; }
            }
            if(agachado2){ hb2y = cb2_y + 10 + 60; } else { hb2y = cb2_y + 10; }
    
            if(bangbang==true){
                bool espaco_atual = IsKeyDown(KEY_SPACE);
                bool m_atual = IsKeyDown(KEY_M);
                if(espaco_atual && !espaco_pressionado && mun > 0 && cooldown1 == 0 && r1 == false && pause==false && dead1==0){
                    emote1=false;
                    for (int i = 0; i < MAX_BALAS; i++){
                        if(bala1_ativo[i] == 0){
                            bala1v_x[i] = cb_x + 53;
                            if(abx==1){ bala1v_y[i] = cb_y + 70; }
                            else{ bala1v_y[i] = cb_y + 48; }
                            y_inicial_bala1[i] = bala1v_y[i];
                            bala1_ativo[i] = 1; mun--; cooldown1 = 60;
                            if(inv1==false){ direcao_bala1[i] = 1; }
                            else{ direcao_bala1[i] = -1; }
                            ia_distancia_reacao = GetRandomValue(50, 450); 
                             bala1_lifetime[i] = 240;
                             PlaySound(tiro1);
                            break;
                        }
                    }
                }
                if(solo == false) {
                    if(m_atual && !m_pressionado && mun2 > 0 && cooldown2 == 0 && r2 == false && pause==false && dead2==0){
                        emote2=false; contemt2=0;
                        for (int i = 0; i < MAX_BALAS; i++){
                            if(bala2_ativo[i] == 0){
                                bala2v_x[i] = cb2_x - 10;
                                if(abx2==1){ bala2v_y[i] = cb2_y + 70; }
                                else{ bala2v_y[i] = cb2_y + 42; }
                                y_inicial_bala2[i] = bala2v_y[i];
                                bala2_ativo[i] = 1; mun2--;
                                if(inv2==false){ direcao_bala2[i]=-1; }
                                else{ direcao_bala2[i]=1; }
                                cooldown2 = 60;
                                bala2_lifetime[i] = 240;
                                PlaySound(tiro2);
                                break;
                            }
                        }
                    }
                }
                espaco_pressionado = espaco_atual;
                m_pressionado = m_atual;
            }
        }
    }
}

void bangbanger(){
    hb1x = cb_x + 10;
    if(agachado1){ hb1y = cb_y + 10 + 60; } else { hb1y = cb_y + 10; }
    hb2x = cb2_x + 40;
    if(agachado2){ hb2y = cb2_y + 10 + 60; } else { hb2y = cb2_y + 10; }
    atualizar_chapeus();
    if(cooldown1 > 0){ cooldown1--; }
    if(cooldown2 > 0){ cooldown2--; }

    for (auto& cluster : cloudLayer) {
            cluster.Draw();
    }

    for (int i = 0; i < MAX_BALAS; i++){
        if(bala1_ativo[i] == 1){
            if(pause==false && timer_inicio<1){
                bala1v_x[i] = bala1v_x[i] + (VELOCIDADE_BALA * direcao_bala1[i]);
                bala1_lifetime[i]--;
            }
            Rectangle recBala1 = { (float)bala1v_x[i], (float)bala1v_y[i], 20, 3 }; // Retângulo da bala
            Rectangle recBot = { hb2x, hb2y, 30, 120 }; // Hitbox do bot

            // Usa a função do Raylib para checar a colisão entre os dois retângulos
            if (CheckCollisionRecs(recBala1, recBot)) {
                vida2 -= DANOO; qntsang2 = GetRandomValue(3,5);
                TocarSomHitAleatorio();
                if(qntsang2 >= 1){ sang21 = true; if(inv2==false){sang2x1=cb2_x+80;}else{sang2x1=cb2_x-15;} sang2y1 = cb2_y + 50; tamsang2x1 = GetRandomValue(5, 20)/3.0f; tamsang2y1 = tamsang2x1; cont2sang1 = GetRandomValue(30, 60); sang2_vel_x1 = GetRandomValue(-5, 1); sang2_vel_y1 = GetRandomValue(-2, 2); }
                if(qntsang2 >= 2){ sang22 = true; if(inv2==false){sang2x2=cb2_x+80;}else{sang2x2=cb2_x-15;} sang2y2 = cb2_y + 50; tamsang2x2 = GetRandomValue(5, 20)/3.0f; tamsang2y2 = tamsang2x2; cont2sang2 = GetRandomValue(30, 60); sang2_vel_x2 = GetRandomValue(-5, 1); sang2_vel_y2 = GetRandomValue(-2, 2); }
                if(qntsang2 >= 3){ sang23 = true; if(inv2==false){sang2x3=cb2_x+80;}else{sang2x3=cb2_x-15;} sang2y3 = cb2_y + 50; tamsang2x3 = GetRandomValue(5, 20)/3.0f; tamsang2y3 = tamsang2x3; cont2sang3 = GetRandomValue(30, 60); sang2_vel_x3 = GetRandomValue(-5, 1); sang2_vel_y3 = GetRandomValue(-2, 2); }
                if(qntsang2 >= 4){ sang24 = true; if(inv2==false){sang2x4=cb2_x+80;}else{sang2x4=cb2_x-15;} sang2y4 = cb2_y + 50; tamsang2x4 = GetRandomValue(5, 20)/3.0f; tamsang2y4 = tamsang2x4; cont2sang4 = GetRandomValue(30, 60); sang2_vel_x4 = GetRandomValue(-5, 1); sang2_vel_y4 = GetRandomValue(-2, 2); }
                if(qntsang2 == 5){ sang25 = true; if(inv2==false){sang2x5=cb2_x+80;}else{sang2x5=cb2_x-15;} sang2y5 = cb2_y + 50; tamsang2x5 = GetRandomValue(5, 20)/3.0f; tamsang2y5 = tamsang2x5; cont2sang5 = GetRandomValue(30, 60); sang2_vel_x5 = GetRandomValue(-5, 1); sang2_vel_y5 = GetRandomValue(-2,2); }
                if(inv1==false){ vel_x_knock2 = -KNOCKBACK_FORCA; } else{ vel_x_knock2 = KNOCKBACK_FORCA; }
                bala1_ativo[i] = 0;
            } else if(bala1_lifetime[i] <= 0 || bala1v_x[i] > 1200 || bala1v_x[i] < 0){ 
                 if(bala1_ativo[i] == 1) { 
                    TocarSomRicocheteAleatorio();
                 }
                bala1_ativo[i] = 0; 
            }
        }
        if(bala2_ativo[i] == 1 && pause==false && timer_inicio<1){
            if(bala2_ativo[i] == 1){ bala2v_x[i] = bala2v_x[i] + (VELOCIDADE_BALA * direcao_bala2[i]); bala2_lifetime[i]--;}
            Rectangle recBala2 = { (float)bala2v_x[i], (float)bala2v_y[i], 20, 3 }; // Retângulo da bala 2
            Rectangle recJogador = { hb1x, hb1y, 30, 120 }; // Hitbox do jogador

            if (CheckCollisionRecs(recBala2, recJogador)) {
                vida -= DANOO; qntsang = GetRandomValue(3,5);
                TocarSomHitAleatorio();
                if(qntsang >= 1){ sang1 = true; if(inv1==false){sangx1=cb_x-20;}else{sangx1=cb_x+70;} sangy1 = cb_y + 50; tamsangx1 = GetRandomValue(5, 20)/3.0f; tamsangy1 = tamsangx1; contsang1 = GetRandomValue(30, 60); sang_vel_x1 = GetRandomValue(-5, 1); sang_vel_y1 = GetRandomValue(-2, 2); }
                if(qntsang >= 2){ sang2 = true; if(inv1==false){sangx2=cb_x-20;}else{sangx2=cb_x+70;} sangy2 = cb_y + 50; tamsangx2 = GetRandomValue(5, 20)/3.0f; tamsangy2 = tamsangx2; contsang2 = GetRandomValue(30, 60); sang_vel_x2 = GetRandomValue(-5, 1); sang_vel_y2 = GetRandomValue(-2, 2); }
                if(qntsang >= 3){ sang3 = true; if(inv1==false){sangx3=cb_x-20;}else{sangx3=cb_x+70;} sangy3 = cb_y + 50; tamsangx3 = GetRandomValue(5, 20)/3.0f; tamsangy3 = tamsangx3; contsang3 = GetRandomValue(30, 60); sang_vel_x3 = GetRandomValue(-5, 1); sang_vel_y3 = GetRandomValue(-2, 2); }
                if(qntsang >= 4){ sang4 = true; if(inv1==false){sangx4=cb_x-20;}else{sangx4=cb_x+70;} sangy4 = cb_y + 50; tamsangx4 = GetRandomValue(5, 20)/3.0f; tamsangy4 = tamsangx4; contsang4 = GetRandomValue(30, 60); sang_vel_x4 = GetRandomValue(-5, 1); sang_vel_y4 = GetRandomValue(-2, 2); }
                if(qntsang == 5){ sang5 = true; if(inv1==false){sangx5=cb_x-20;}else{sangx5=cb_x+70;} sangy5 = cb_y + 50; tamsangx5 = GetRandomValue(5, 20)/3.0f; tamsangy5 = tamsangx5; contsang5 = GetRandomValue(30, 60); sang_vel_x5 = GetRandomValue(-5, 1); sang_vel_y5 = GetRandomValue(-2, 2); }
                if(inv2==false){ vel_x_knock1 = KNOCKBACK_FORCA; } else{ vel_x_knock1 = -KNOCKBACK_FORCA; }
                bala2_ativo[i] = 0;
            } else if(bala2_lifetime[i] <= 0 || bala2v_x[i] > 1200 ||bala2v_x[i] < 0){ 
                if(bala2_ativo[i] == 1) {
                    TocarSomRicocheteAleatorio();
                }
                bala2_ativo[i] = 0; 
            }
        }
    }

    if(vida <= 0 && dead1 == 0){ dead1 = 1; morrendo1 = true; PlaySound(mort1); if(cb_y >= CHAO){ vel_x_morte1 = EMPURRAO_CHAO; vel_y_morte1 = 0.0; } else { vel_x_morte1 = EMPURRAO_AR_X; vel_y_morte1 = 0.0; } }
    if(vida2 <= 0 && dead2 == 0){ dead2 = 1; morrendo2 = true; PlaySound(mort2); if(cb2_y >= CHAO){ vel_x_morte2 = -EMPURRAO_CHAO; vel_y_morte2 = 0.0; } else { vel_x_morte2 = -EMPURRAO_AR_X; vel_y_morte2 = 0.0; } }
    if(vel_x_knock1 != 0){ cb_x -= vel_x_knock1; hb1x -= vel_x_knock1; if(vel_x_knock1 < 0){ vel_x_knock1 += DESACELERACAO_KNOCK; if(vel_x_knock1 > 0) vel_x_knock1 = 0; } else { vel_x_knock1 -= DESACELERACAO_KNOCK; if(vel_x_knock1 < 0) vel_x_knock1 = 0; } }
    if(vel_x_knock2 != 0){ cb2_x -= vel_x_knock2; hb2x -= vel_x_knock2; if(vel_x_knock2 < 0){ vel_x_knock2 += DESACELERACAO_KNOCK; if(vel_x_knock2 > 0) vel_x_knock2 = 0; } else { vel_x_knock2 -= DESACELERACAO_KNOCK; if(vel_x_knock2 < 0) vel_x_knock2 = 0; } }
    if(morrendo1){ cb_x -= vel_x_morte1; cb_y += vel_y_morte1; hb1x -= vel_x_morte1; vel_y_morte1 += GRAVIDADE; if(vel_x_morte1 < 0){ vel_x_morte1 += DESACELERACAO_X; if(vel_x_morte1 > 0) vel_x_morte1 = 0; } else { vel_x_morte1 -= DESACELERACAO_X; if(vel_x_morte1 < 0) vel_x_morte1 = 0; } if(cb_y >= CHAO){ cb_y = CHAO; vel_y_morte1 = 0.0; morrendo1 = false; } }
    if(morrendo2){ cb2_x -= vel_x_morte2; cb2_y += vel_y_morte2; hb2x -= vel_x_morte2; vel_y_morte2 += GRAVIDADE; if(vel_x_morte2 < 0){ vel_x_morte2 += DESACELERACAO_X; if(vel_x_morte2 > 0) vel_x_morte2 = 0; } else { vel_x_morte2 -= DESACELERACAO_X; if(vel_x_morte2 < 0) vel_x_morte2 = 0; } if(cb2_y >= CHAO){ cb2_y = CHAO; vel_y_morte2 = 0.0; morrendo2 = false; } }
    if(dead1 > 0){ fall++; }
    if(dead2 > 0){ fall2++; }
    if(cb_x>cb2_x+49){ inv1=true; } else{ inv1=false; }
    
    if(dead1 == 0){
        if(sang1){ if(inv1==false){ sangx1 += sang_vel_x1; } else{ sangx1 -= sang_vel_x1; } sangy1 += sang_vel_y1; sang_vel_y1 += GRAVIDADE_PARTICULA; tamsangx1--; tamsangy1--; contsang1--; if(contsang1 > 0 && tamsangx1 > 0){ DrawEllipse(sangx1, sangy1, tamsangx1, tamsangy1, RED); } else { sang1 = false; } }
        if(sang2){ if(inv1==false){ sangx2 += sang_vel_x2; } else{ sangx2 -= sang_vel_x2; } sangy2 += sang_vel_y2; sang_vel_y2 += GRAVIDADE_PARTICULA; tamsangx2--; tamsangy2--; contsang2--; if(contsang2 > 0 && tamsangx2 > 0){ DrawEllipse(sangx2, sangy2, tamsangx2, tamsangy2, RED); } else { sang2 = false; } }
        if(sang3){ if(inv1==false){ sangx3 += sang_vel_x3; } else{ sangx3 -= sang_vel_x3; } sangy3 += sang_vel_y3; sang_vel_y3 += GRAVIDADE_PARTICULA; tamsangx3--; tamsangy3--; contsang3--; if(contsang3 > 0 && tamsangx3 > 0){ DrawEllipse(sangx3, sangy3, tamsangx3, tamsangy3, RED); } else { sang3 = false; } }
        if(sang4){ if(inv1==false){ sangx4 += sang_vel_x4; } else{ sangx4 -= sang_vel_x4; } sangy4 += sang_vel_y4; sang_vel_y4 += GRAVIDADE_PARTICULA; tamsangx4--; tamsangy4--; contsang4--; if(contsang4 > 0 && tamsangx4 > 0){ DrawEllipse(sangx4, sangy4, tamsangx4, tamsangy4, RED); } else { sang4 = false; } }
        if(sang5){ if(inv1==false){ sangx5 += sang_vel_x5; } else{ sangx5 -= sang_vel_x5; } sangy5 += sang_vel_y5; sang_vel_y5 += GRAVIDADE_PARTICULA; tamsangx5--; tamsangy5--; contsang5--; if(contsang5 > 0 && tamsangx5 > 0){ DrawEllipse(sangx5, sangy5, tamsangx5, tamsangy5, RED); } else { sang5 = false; } }
        if(abx == 0){
            if(passos>30){ passos=0; }
            if(passos>=0 && passos<15){ if(pulando1==false){ if(inv1 == false && emote1==false){ DrawTextureRec(cb1, {0, 0, 74, 119}, {cb_x, cb_y}, WHITE); } if(inv1 == true && emote1==false){ DrawTextureRec(cb1i, {0, 0, 74, 119}, {cb_x, cb_y}, WHITE); } } }
            else { if(pulando1==false){ if(inv1 == false && emote1==false){ DrawTextureRec(cb1, {80, 0, 74, 119}, {cb_x, cb_y}, WHITE); } if(inv1 == true && emote1==false){ DrawTextureRec(cb1i, {80, 0, 74, 119}, {cb_x, cb_y}, WHITE); } } }
            if(pulando1==true){ if(inv1==false){ DrawTextureRec(cb1, {154, 0, 73, 114}, {cb_x, cb_y}, WHITE); } else{ DrawTextureRec(cb1i, {154, 0, 73, 114}, {cb_x, cb_y}, WHITE); } }
            if(emote1==true){
                if(contemt1>=0 && contemt1<20){ if(inv1==false){ DrawTextureRec(cb1, {709, 0, 57, 125}, {cb_x, cb_y}, WHITE); } else{ DrawTextureRec(cb1i, {717, 0, 58, 137}, {cb_x, cb_y}, WHITE); } }
                if(contemt1>=20 && contemt1<40){ if(inv1==false){ DrawTextureRec(cb1, {851, 0, 59, 125}, {cb_x, cb_y}, WHITE); } else{ DrawTextureRec(cb1i, {797, 0, 56, 136}, {cb_x, cb_y}, WHITE); } }
                if(contemt1>=40 && contemt1<=60){ if(inv1==false){ DrawTextureRec(cb1, {783, 0, 54, 125}, {cb_x, cb_y}, WHITE); } else{ DrawTextureRec(cb1i, {868, 0, 53, 134}, {cb_x, cb_y}, WHITE); } }
            }
        } else { if(inv1==false){ DrawTextureRec(cb1, {610, 0, 89, 120}, {cb_x, cb_y}, WHITE); } else{ DrawTextureRec(cb1i, {610, 0, 89, 120}, {cb_x, cb_y}, WHITE); } }
    } else {
        if(fall > 0 && fall < 25){ if(inv1==false){ DrawTextureRec(cb1, {230, 0, 88, 120}, {cb_x, cb_y}, WHITE); } else{ DrawTextureRec(cb1i, {230, 0, 88, 120}, {cb_x, cb_y}, WHITE); } }
        if(fall > 25 && fall < 50){ if(inv1==false){ DrawTextureRec(cb1, {333, 0, 119, 120}, {cb_x-30, cb_y}, WHITE); } else{ DrawTextureRec(cb1i, {333, 0, 119, 120}, {cb_x-30, cb_y}, WHITE); } }
        if(fall > 50){ if(inv1==false){ DrawTextureRec(cb1, {470, 0, 126, 120}, {cb_x-40, cb_y}, WHITE); } else{ DrawTextureRec(cb1i, {470, 0, 126, 120}, {cb_x-40, cb_y}, WHITE); } }
    }

    if(cb2_x<cb_x){ inv2=true; } else{ inv2=false; }
    if(dead2 == 0){
        if(sang21){ if(inv2==false){ sang2x1 -= sang2_vel_x1; } else{ sang2x1 += sang2_vel_x1; } sang2y1 += sang2_vel_y1; sang2_vel_y1 += GRAVIDADE_PARTICULA; tamsang2x1--; tamsang2y1--; cont2sang1--; if(cont2sang1 > 0 && tamsang2x1 > 0){ DrawEllipse(sang2x1, sang2y1, tamsang2x1, tamsang2y1, RED); } else { sang21 = false; } }
        if(sang22){ if(inv2==false){ sang2x2 -= sang2_vel_x2; } else{ sang2x2 += sang2_vel_x2; } sang2y2 += sang2_vel_y2; sang2_vel_y2 += GRAVIDADE_PARTICULA; tamsang2x2--; tamsang2y2--; cont2sang2--; if(cont2sang2 > 0 && tamsang2x2 > 0){ DrawEllipse(sang2x2, sang2y2, tamsang2x2, tamsang2y2, RED); } else { sang22 = false; } }
        if(sang23){ if(inv2==false){ sang2x3 -= sang2_vel_x3; } else{ sang2x3 += sang2_vel_x3; } sang2y3 += sang2_vel_y3; sang2_vel_y3 += GRAVIDADE_PARTICULA; tamsang2x3--; tamsang2y3--; cont2sang3--; if(cont2sang3 > 0 && tamsang2x3 > 0){ DrawEllipse(sang2x3, sang2y3, tamsang2x3, tamsang2y3, RED); } else { sang23 = false; } }
        if(sang24){ if(inv2==false){ sang2x4 -= sang2_vel_x4; } else{ sang2x4 += sang2_vel_x4; } sang2y4 += sang2_vel_y4; sang2_vel_y4 += GRAVIDADE_PARTICULA; tamsang2x4--; tamsang2y4--; cont2sang4--; if(cont2sang4 > 0 && tamsang2x4 > 0){ DrawEllipse(sang2x4, sang2y4, tamsang2x4, tamsang2y4, RED); } else { sang24 = false; } }
        if(sang25){ if(inv2==false){ sang2x5 -= sang2_vel_x5; } else{ sang2x5 += sang2_vel_x5; } sang2y5 += sang2_vel_y5; sang2_vel_y5 += GRAVIDADE_PARTICULA; tamsang2x5--; tamsang2y5--; cont2sang5--; if(cont2sang5 > 0 && tamsang2x5 > 0){ DrawEllipse(sang2x5, sang2y5, tamsang2x5, tamsang2y5, RED); } else { sang25 = false; } }
        if(abx2 == 0){
            if(passos2>30){ passos2=0; }
            if(passos2>=0 && passos2<15){ if(pulando2==false){ if(inv2==false && emote2==false){ DrawTextureRec(cb2, {0, 0, 74, 119}, {cb2_x, cb2_y}, WHITE); } if(inv2==true && emote2==false){ DrawTextureRec(cb2i, {0, 0, 74, 119}, {cb2_x, cb2_y}, WHITE); } } }
            else { if(pulando2==false){ if(inv2==false && emote2==false){ DrawTextureRec(cb2, {73, 0, 74, 119}, {cb2_x, cb2_y}, WHITE); } if(inv2==true && emote2==false){ DrawTextureRec(cb2i, {73, 0, 74, 119}, {cb2_x, cb2_y}, WHITE); } } }
            if(pulando2==true){ if(inv2==false){ DrawTextureRec(cb2, {147, 0, 73, 114}, {cb2_x+5, cb2_y}, WHITE); } else{ DrawTextureRec(cb2i, {147, 0, 73, 114}, {cb2_x, cb2_y}, WHITE); } }
            if(emote2==true){
                if(contemt2>=0 && contemt2<20){ if(inv2==false){ DrawTextureRec(cb2, {721, 0, 61, 125}, {cb2_x, cb2_y}, WHITE); } else{ DrawTextureRec(cb2i, {716, 0, 61, 125}, {cb2_x, cb2_y}, WHITE); } }
                if(contemt2>=20 && contemt2<40){ if(inv2==false){ DrawTextureRec(cb2, {812, 0, 53, 125}, {cb2_x, cb2_y}, WHITE); } else{ DrawTextureRec(cb2i, {787, 0, 56, 125}, {cb2_x, cb2_y}, WHITE); } }
                if(contemt2>=40 && contemt2<=60){ if(inv2==false){ DrawTextureRec(cb2, {879, 0, 53, 125}, {cb2_x, cb2_y}, WHITE); } else{ DrawTextureRec(cb2i, {862, 0, 54, 125}, {cb2_x, cb2_y}, WHITE); } }
            }
        } else { if(inv2==false){ DrawTextureRec(cb2, {610, 0, 89, 120}, {cb2_x, cb2_y}, WHITE); } else{ DrawTextureRec(cb2i, {610, 0, 89, 120}, {cb2_x, cb2_y}, WHITE); } }
    } else {
        if(fall2 > 0 && fall2 < 25){ if(inv2==false){ DrawTextureRec(cb2, {225, 0, 79, 120}, {cb2_x, cb2_y}, WHITE); } else{ DrawTextureRec(cb2i, {225, 0, 79, 120}, {cb2_x, cb2_y}, WHITE); } }
        if(fall2 > 25 && fall2 < 50){ if(inv2==false){ DrawTextureRec(cb2, {315, 0, 110, 150}, {cb2_x+10, cb2_y}, WHITE); } else{ DrawTextureRec(cb2i, {315, 0, 110, 150}, {cb2_x-30, cb2_y}, WHITE); } }
        if(fall2 > 50){ if(inv2==false){ DrawTextureRec(cb2, {442, 0, 143, 118}, {cb2_x+10, cb2_y+4}, WHITE); } else{ DrawTextureRec(cb2i, {442, 0, 143, 118}, {cb2_x-50, cb2_y+4}, WHITE); } }
    }
    DrawTexture(chapeu1, chapeu1_x, chapeu1_y, WHITE);
    DrawTexture(chapeu2, chapeu2_x, chapeu2_y, WHITE);

    for (int i = 0; i < MAX_BALAS; i++){
        if(bala1_ativo[i] == 1){ DrawEllipse(bala1v_x[i], bala1v_y[i], 3, 2, BLACK); }
        if(bala2_ativo[i] == 1){ DrawEllipse(bala2v_x[i], bala2v_y[i], 3, 2, BLACK); }
    }

    if(bangbang==true){
        DrawRectangleRec({100, 100, (float)vida * 3, 50}, GREEN);
        DrawRectangleLines(100, 100, 300, 50, BLACK);
        DrawRectangleRec({800, 100, (float)vida2 * 3, 50}, GREEN);
        DrawRectangleLines(800, 100, 300, 50, BLACK);
    }
    
    if(pause==true){
        DrawRectangle(514, 435, 108, 35, WHITE);
        DrawRectangle(525, 455, 72, 45, WHITE);
        if(opt==1){ DrawRectangle(514, 435, 108, 35, RED); }
        if(opt==2){ DrawRectangle(525, 475, 72, 25, RED); }
        DrawTexture(pauser, 500, 350, WHITE);
    }

    if(bangbang==true){
        DrawTexture(roleta, 100, 200, WHITE);
        DrawTexture(roleta, 1000, 200, WHITE);
        if(mun==6){ DrawTexture(bala, 114, 224, WHITE); DrawTexture(bala, 113, 257, WHITE); DrawTexture(bala, 144, 273, WHITE); DrawTexture(bala, 172, 257, WHITE); DrawTexture(bala, 173, 224, WHITE); DrawTexture(bala, 144, 209, WHITE); }
        if(mun==5){ DrawTexture(bala, 114, 224, WHITE); DrawTexture(bala, 113, 257, WHITE); DrawTexture(bala, 144, 273, WHITE); DrawTexture(bala, 172, 257, WHITE); DrawTexture(bala, 173, 224, WHITE); }
        if(mun==4){ DrawTexture(bala, 114, 224, WHITE); DrawTexture(bala, 113, 257, WHITE); DrawTexture(bala, 144, 273, WHITE); DrawTexture(bala, 172, 257, WHITE); }
        if(mun==3){ DrawTexture(bala, 114, 224, WHITE); DrawTexture(bala, 113, 257, WHITE); DrawTexture(bala, 144, 273, WHITE); }
        if(mun==2){ DrawTexture(bala, 114, 224, WHITE); DrawTexture(bala, 113, 257, WHITE); }
        if(mun==1){ DrawTexture(bala, 114, 224, WHITE); }
        if(mun2==6){ DrawTexture(bala, 1014, 224, WHITE); DrawTexture(bala, 1013, 257, WHITE); DrawTexture(bala, 1044, 273, WHITE); DrawTexture(bala, 1072, 257, WHITE); DrawTexture(bala, 1073, 224, WHITE); DrawTexture(bala, 1044, 209, WHITE); }
        if(mun2==5){ DrawTexture(bala, 1014, 224, WHITE); DrawTexture(bala, 1013, 257, WHITE); DrawTexture(bala, 1044, 273, WHITE); DrawTexture(bala, 1072, 257, WHITE); DrawTexture(bala, 1073, 224, WHITE); }
        if(mun2==4){ DrawTexture(bala, 1014, 224, WHITE); DrawTexture(bala, 1013, 257, WHITE); DrawTexture(bala, 1044, 273, WHITE); DrawTexture(bala, 1072, 257, WHITE); }
        if(mun2==3){ DrawTexture(bala, 1014, 224, WHITE); DrawTexture(bala, 1013, 257, WHITE); DrawTexture(bala, 1044, 273, WHITE); }
        if(mun2==2){ DrawTexture(bala, 1014, 224, WHITE); DrawTexture(bala, 1013, 257, WHITE); }
        if(mun2==1){ DrawTexture(bala, 1014, 224, WHITE); }
    }
    if(r1c>0 && r1c<600){ DrawTextEx(fnt, "RELOADING...", {80, 320}, 30, 2.0, BLACK); }
    if(r2c>0 && r2c<600){ DrawTextEx(fnt, "RELOADING...", {980, 320}, 30, 2.0, BLACK); }
    if(r1c>0 && r1c<=100 && mun==0){ DrawTexture(bala, 114, 224, WHITE); DrawTexture(bala, 113, 257, WHITE); DrawTexture(bala, 144, 273, WHITE); DrawTexture(bala, 172, 257, WHITE); DrawTexture(bala, 173, 224, WHITE); }
    if(r1c>100 && r1c<=200 && mun==0){ DrawTexture(bala, 114, 224, WHITE); DrawTexture(bala, 113, 257, WHITE); DrawTexture(bala, 144, 273, WHITE); DrawTexture(bala, 172, 257, WHITE); }
    if(r1c>200 && r1c<=300 && mun==0){ DrawTexture(bala, 114, 224, WHITE); DrawTexture(bala, 113, 257, WHITE); DrawTexture(bala, 144, 273, WHITE); }
    if(r1c>300 && r1c<=400 && mun==0){ DrawTexture(bala, 114, 224, WHITE); DrawTexture(bala, 113, 257, WHITE); }
    if(r1c>400 && r1c<=500 && mun==0){ DrawTexture(bala, 114, 224, WHITE); }
    if(r2c>0 && r2c<=100 && mun2==0){ DrawTexture(bala, 1014, 224, WHITE); DrawTexture(bala, 1013, 257, WHITE); DrawTexture(bala, 1044, 273, WHITE); DrawTexture(bala, 1072, 257, WHITE); DrawTexture(bala, 1073, 224, WHITE); }
    if(r2c>100 && r2c<=200 && mun2==0){ DrawTexture(bala, 1014, 224, WHITE); DrawTexture(bala, 1013, 257, WHITE); DrawTexture(bala, 1044, 273, WHITE); DrawTexture(bala, 1072, 257, WHITE); }
    if(r2c>200 && r2c<=300 && mun2==0){ DrawTexture(bala, 1014, 224, WHITE); DrawTexture(bala, 1013, 257, WHITE); DrawTexture(bala, 1044, 273, WHITE); }
    if(r2c>300 && r2c<=400 && mun2==0){ DrawTexture(bala, 1014, 224, WHITE); DrawTexture(bala, 1013, 257, WHITE); }
    if(r2c>400 && r2c<=500 && mun2==0){ DrawTexture(bala, 1014, 224, WHITE); }
        
    if(timer_inicio>200 && timer_inicio<300 && oneshot==false){
        if (timer_inicio > 120){ DrawTextureRec(contag, {110, 0, 40, 75}, {550, 300}, WHITE); }
    }
    if(timer_inicio>100 && timer_inicio<=200 && oneshot==false){
        if (timer_inicio > 60){ DrawTextureRec(contag, {48, 0, 40, 75}, {555, 300}, WHITE); }
    }
    if(timer_inicio<=100 && timer_inicio>0 && oneshot==false){
        if (timer_inicio > 0){ DrawTextureRec(contag, {0, 0, 26, 75}, {560, 300}, WHITE); }
    }
}
void oneshoter() {
    cb_x = 100;
    cb2_x = 1100;
    if (os_estado == 0 && oneshotmenu==false) {
        tem_chapeu1 = true;
        tem_chapeu2 = true;
        os_timer = 300;
        os_p1_escolha = 0;
        os_p2_escolha = 0;
        os_acao_texto1 = "";
        os_acao_texto2 = "";
        dead1 = 0;
        dead2 = 0;
        fall = 0;
        fall2 = 0;
        os_estado = 1;
        PlaySound(contagen);
    }

    if (os_estado == 1 && oneshotmenu==false) {
        if (os_timer > 0) {
            os_timer--;

            if (IsKeyPressed(KEY_A)) os_p1_escolha = 1;
            if (IsKeyPressed(KEY_S)) os_p1_escolha = 2;
            if (IsKeyPressed(KEY_D) && os_p1_mun > 0) os_p1_escolha = 3;

            if (solo == false) {
                if (IsKeyPressed(KEY_J)) os_p2_escolha = 1;
                if (IsKeyPressed(KEY_K)) os_p2_escolha = 2;
                if (IsKeyPressed(KEY_L) && os_p2_mun > 0) os_p2_escolha = 3;
            } else {
                if (os_p1_mun == 0 && os_p2_mun == 0) {
                    os_p2_escolha = 1;
                } else {
                    if (os_p2_mun > 0) {
                        os_p2_escolha = GetRandomValue(1, 3);
                    } else {
                        os_p2_escolha = GetRandomValue(1, 2);
                    }
                }
            }
        } else {
            os_estado = 2;
        }
    }

    if (os_estado == 2) {
        if (os_p1_escolha == 3 && os_p2_escolha == 1) { dead2 = 1; PlaySound(mort2); }
        if (os_p2_escolha == 3 && os_p1_escolha == 1) { dead1 = 1; PlaySound(mort1); }
        if (os_p1_escolha == 3 && os_p2_escolha == 3) { dead1=1; dead2=1; PlaySound(mort1); PlaySound(mort2);PlaySound(tiro1);PlaySound(tiro2);}
        if (os_p1_escolha == 3 && os_p2_escolha == 0) { dead2 = 1; PlaySound(mort2); }
        if (os_p2_escolha == 3 && os_p1_escolha == 0) { dead1 = 1; PlaySound(mort1); }
        if (os_p1_escolha == 1 && dead1 == 0) { os_p1_mun++; }
        if (os_p2_escolha == 1 && dead2 == 0) { os_p2_mun++; }
        if (os_p1_escolha == 3 && dead1 == 0) { os_p1_mun--; PlaySound(tiro1);}
        if (os_p2_escolha == 3 && dead2 == 0) { os_p2_mun--; PlaySound(tiro2);}
        os_estado = 3;
        if (dead1 == 0 && dead2 == 0) {
            os_timer_mensagem = 120;
        }
    }

    if (os_estado == 3) {
        if (dead1 == 1) fall++;
        if (dead2 == 1) fall2++;

        if (dead1 == 1 || dead2 == 1) {
            if (IsKeyPressed(KEY_R)) {
                if (dead1 == 1 && dead2 == 0) win2++;
                if (dead2 == 1 && dead1 == 0) win1++;
                os_p1_mun = 0;
                os_p2_mun = 0;
                os_estado = 0;
            }
        } else {
            if (os_timer_mensagem > 0) {
                os_timer_mensagem--;
            }
            if (IsKeyPressed(KEY_SPACE)) {
                os_estado = 0;
            }
        }
    }
}

void desenhar(){
    BeginDrawing();
    ClearBackground(WHITE);
    DrawTexture(cenario, 0, 0, WHITE);
    if(menu==true || modo==true || bangmenu==true || bangbang==true || oneshot==true || pause==false){
        for (auto& cluster : cloudLayer) {
            cluster.Draw();
        }
    }
    
    if(menu==true){
        DrawRectangle(520, 410, 130, 30, WHITE);
        DrawRectangle(500, 440, 167, 35, WHITE);
        DrawRectangle(534, 480, 100, 30, WHITE);
        DrawRectangle(556, 520, 57, 35, WHITE);
        if(opt==1){ DrawRectangle(520, 410, 130, 30, RED); }
        if(opt==2){ DrawRectangle(500, 440, 167, 35, RED); }
        if(opt==3){ DrawRectangle(534, 480, 100, 32, RED); }
        if(opt==4){ DrawRectangle(556, 520, 55, 32, RED); }
        
        if(creds==false){
            DrawTexture(menui, 494, 402, WHITE);
            DrawEllipse(0,0, 20/3.0f, 3/3.0f, BLACK);
            DrawEllipse(0,0,20/3.0f, 3/3.0f, BLACK);
            DrawTexture(logo, 310, 60, WHITE);
            DrawTextureRec(cb1, {0, 0, 74, 119}, {cb_x, cb_y}, WHITE);
            DrawTextureRec(cb2, {0, 0, 74, 119}, {cb2_x, cb2_y}, WHITE);
            DrawTexture(chapeu1, chapeu1_x, chapeu1_y, WHITE);
            DrawTexture(chapeu2, chapeu2_x, chapeu2_y, WHITE);
        }
        if(creds==true){ DrawTexture(credits, 0, 0, WHITE); }
    }
    
    if(modo==true){
        DrawRectangle(483, 433, 202, 30, WHITE);
        DrawRectangle(495, 473, 181, 28, WHITE);
        if(opt==1){ DrawRectangle(483, 433, 202, 30, RED); }
        if(opt==2){ DrawRectangle(495, 473, 181, 28, RED); }
        DrawTexture(modoi, 470, 350, WHITE);
        DrawTexture(back, 950, 100, WHITE);
        DrawTextureRec(cb1, {0, 0, 74, 119}, {cb_x, cb_y}, WHITE);
        DrawTextureRec(cb2, {0, 0, 74, 119}, {cb2_x, cb2_y}, WHITE);
        DrawTexture(chapeu1, chapeu1_x, chapeu1_y, WHITE);
        DrawTexture(chapeu2, chapeu2_x, chapeu2_y, WHITE);
    }
    if(bangmenu==true){
        pisca++;
        if(pisca>800){ pisca=0; }
        DrawTexture(bangbangcontrols, 0, 0, WHITE);
        if(pisca>0 && pisca<400){ DrawTexture(start, 500, 400, WHITE); }
        DrawTexture(back, 950, 100, WHITE);
    }
    if(menu==false && modo==false && quit==false && bangmenu==false){
        DrawTexture(cenario, cenario_x, cenario_y, WHITE);
        
        if(bangbang==true){
            bangbanger();
            DrawTextEx(fnt,TextFormat("%d", win1), {570, 100}, 40, 3.0, BLACK);
            DrawTextEx(fnt,TextFormat("   X %d", win2), {570, 100}, 40, 3.0, BLACK);
            DrawTextEx(fnt,nome1.c_str(), {105, 110}, 40, 3.0, BLACK);
            if(solo == false) {
                DrawTextEx(fnt,nome2.c_str(), {980, 110}, 40, 3.0, BLACK);
            } else {
                DrawTextEx(fnt,"BOT", {1025, 110}, 40, 3.0, BLACK);
            }
        }
        if (oneshot == true) {
            oneshoter();
            bangbanger();
            DrawTexture(p1controls, 30, 200, WHITE);
            DrawTexture(p2controls, 950, 200, WHITE);
            DrawTextEx(fnt,nome1.c_str(), {50, 100},40, 3.0, BLACK);
            DrawTextEx(fnt,nome2.c_str(), {950, 100},40, 3.0, BLACK);
            DrawTextEx(fnt,TextFormat("%d", win1), {530, 100},40, 3.0, BLACK);
            DrawTextEx(fnt,TextFormat(" X %d", win2), {550, 100},40, 3.0, BLACK);
            if (os_estado == 1 && pause==false) {
                if (os_timer > 200){ DrawTextureRec(contag, {110, 0, 40, 75}, {550, 300}, WHITE); }
                else if (os_timer > 100){ DrawTextureRec(contag, {48, 0, 40, 75}, {555, 300}, WHITE); }
                else if (os_timer > 0){ DrawTextureRec(contag, {0, 0, 26, 75}, {560, 300}, WHITE); }
            }
            if (os_estado == 3) {
                if(os_p1_escolha == 1){ DrawTextureRec(p2controls, {45, 31, 89, 42}, {90, 500}, WHITE); }
                if(os_p1_escolha == 2){ DrawTextureRec(p2controls, {37, 90, 105, 39}, {90, 500}, WHITE); }
                if(os_p1_escolha == 3){ DrawTextureRec(p2controls, {35, 147, 113, 40}, {90, 500}, WHITE); }
                if(os_p2_escolha == 1){ DrawTextureRec(p2controls, {45, 31, 89, 42}, {1090, 500}, WHITE); }
                if(os_p2_escolha == 2){ DrawTextureRec(p2controls, {37, 90, 105, 39}, {1090, 500}, WHITE); }
                if(os_p2_escolha == 3){ DrawTextureRec(p2controls, {35, 147, 113, 40}, {1090, 500}, WHITE); }
                if (dead1 == 0 && dead2 > 0 && pause==false) DrawTexture(p1wins, 320, 200, WHITE);
                if (dead2 == 0 && dead1 > 0 && pause==false) DrawTexture(p2wins, 270, 200, WHITE);
                if (dead1 > 0 && dead2 > 0 && pause==false){ DrawEllipse(760, 400, 150, 50, WHITE); DrawEllipse(630, 420, 30, 10, WHITE); DrawTexture(neg, 400,340, WHITE); DrawTextEx(fnt,"Press R to restart!", {660, 390}, 20, 3.0, BLACK); }
                if ((dead1 == 1 && dead2==0 && pause==false) || (dead2 == 1 && dead1==0 && pause==false)) { DrawTextEx(fnt,"'R' Para Reiniciar", {450, 400}, 30, 3.0, BLACK); }
                if(dead1==0 && dead2==0) { if (os_timer_mensagem <= 0) { pisca++; if(pisca>500){ pisca=0; } if(pisca>0 && pisca<250 && pause==false){ DrawTexture(start, 450, 300, WHITE); } } }
            }
            if (dead1 == 1){
                if(tem_chapeu1==true && dead1==1 && pause==false){
                    if(!inv1){ chapeu1_x=cb_x+30; } else{ chapeu1_x=cb_x+20; }
                    tem_chapeu1=false;
                    chapeu1_caindo=true;
                }
                if(chapeu1_y<=315){
                    chapeu1_y=315;
                }
            }
            if (dead2 == 1){
                if(tem_chapeu2==true && dead2==1 && pause==false){
                    if(!inv2){ chapeu2_x=cb2_x+45; } else{ chapeu2_x=cb2_x-15; }
                    tem_chapeu2=false;
                    chapeu2_caindo=true;
                }
                if(chapeu2_y<=315){
                    chapeu2_y=315;
                }
            }
        }
        if(colocarnomes==true){
            pisca++;
            if (nomes_confirmados) { DrawTextEx(fnt,TextFormat("PLAYER 1: %s", nome1.c_str()), {400, 300}, 40, 3.0, WHITE); DrawTextEx(fnt,TextFormat("PLAYER 2: %s", nome2.c_str()), {400, 400}, 40, 3.0, WHITE); } 
            else {
                DrawTextEx(fnt,"PLAYER 1:", {300, 200}, 40, 3.0, RED); DrawRectangleLines(300, 250, 600, 50, RED);
                DrawTextEx(fnt,"PLAYER 2:", {300, 400}, 40, 3.0, RED); DrawRectangleLines(300, 450, 600, 50, RED);
                DrawTextEx(fnt,"CONFIRM", {500, 600}, 40, 3.0, RED); DrawRectangleLines(490, 590, 220, 60, RED);
                DrawTextEx(fnt,nome1.c_str(), {310, 260}, 40, 3.0, WHITE);
                if (jogador_atual == 1 && pisca < 30) { DrawTextEx(fnt,"_", {(float)(310 + MeasureText(nome1.c_str(), 33.0)), 260.0f}, 30, 30.0, WHITE); }
                DrawTextEx(fnt,nome2.c_str(), {310, 460}, 40, 3.0, WHITE);
                if (jogador_atual == 2 && pisca < 30) { DrawTextEx(fnt,"_", {(float)(310 + MeasureText(nome2.c_str(), 33.0)), 460.0f}, 30, 30.0, WHITE); }
                if (pisca > 60) { pisca = 0; }
            }
        }
        if(oneshotmenu==true){
            DrawTexture(oneshotcontrols, 0, 0, WHITE); DrawTexture(back, 950, 100, WHITE);
            pisca++; if(pisca>800){ pisca=0; }
            if(pisca>0 && pisca<400){ DrawTexture(start, 500, 500, WHITE); }
        }
        if(dead1==0 && dead2>0 && bangbang==true){ 
            DrawTexture(p1wins, 320, 200, WHITE); 
            DrawTextEx(fnt,"'R' Para Reiniciar", {450, 400}, 30, 3.0, BLACK); 
            dnv=1; 
            if(IsKeyPressed(KEY_R)){ 
                win1++; vida=100; vida2=100; dnv=0; dead1=0; dead2=0; mun=6; mun2=6; fall=0; fall2=0; bala_x=cb_x+53; bala2_x=cb2_x-10; cb_x=100; cb2_x=1100; cb_y=560; cb2_y=560; hb1x=cb_x+10; hb1y=cb_y+10; hb2x=cb2_x+40; hb2y=cb2_y+10; 
                for (int i=0; i<MAX_BALAS; i++){ bala1_ativo[i] = 0; bala2_ativo[i] = 0; } 
                cooldown1 = 0; cooldown2 = 0; vel_x_knock1 = 0.0; vel_x_knock2 = 0.0; vel_x_morte1 = 0.0; vel_y_morte1 = 0.0; morrendo1 = false; vel_x_morte2 = 0.0; vel_y_morte2 = 0.0; morrendo2 = false; 
                vel_y1 = 0.0; vel_y2 = 0.0; pulando1 = false; pulando2 = false; sangx1=cb_x-30; sangy1=cb_y+40; tem_chapeu1 = true; tem_chapeu2 = true; r1=false; r2=false; r1c=600; r2c=600;
            } 
        }
        if(dead2==0 && dead1>0 && bangbang==true){ 
            DrawTexture(p2wins, 270, 200, WHITE); 
            DrawTextEx(fnt,"'R' Para Reiniciar", {450, 400}, 30, 3.0, BLACK); 
            dnv=1; 
            if(IsKeyPressed(KEY_R)){ 
                win2++; vida=100; vida2=100; dnv=0; dead1=0; dead2=0; mun=6; mun2=6; fall=0; fall2=0; bala_x=cb_x+53; bala2_x=cb2_x-10; cb_x=100; cb2_x=1100; cb_y=560; cb2_y=560; hb1x=cb_x+10; hb1y=cb_y+10; hb2x=cb2_x+40; hb2y=cb2_y+10; 
                for (int i=0; i<MAX_BALAS; i++){ bala1_ativo[i] = 0; bala2_ativo[i] = 0; } 
                cooldown1 = 0; cooldown2 = 0; vel_x_knock1 = 0.0; vel_x_knock2 = 0.0; vel_x_morte1 = 0.0; vel_y_morte1 = 0.0; morrendo1 = false; vel_x_morte2 = 0.0; vel_y_morte2 = 0.0; morrendo2 = false; 
                vel_y1 = 0.0; vel_y2 = 0.0; pulando1 = false; pulando2 = false; sangx1=cb_x-30; sangy1=cb_y+40; tem_chapeu1 = true; tem_chapeu2 = true; 
            } 
        }
        if(dead2>0 && dead1>0 && bangbang==true && pause==false){ 
            DrawEllipse(760, 400, 150, 50, WHITE); DrawEllipse(630, 420, 30, 10, WHITE); DrawTexture(neg, 400,340, WHITE); DrawTextEx(fnt,"Press R to restart!", {660, 390}, 20, 3.0, BLACK);
            dnv=1; 
            if(IsKeyPressed(KEY_R)){ 
                vida=100; vida2=100; dnv=0; dead1=0; dead2=0; mun=6; mun2=6; fall=0; fall2=0; bala_x=cb_x+53; bala2_x=cb2_x-10; cb_x=100; cb2_x=1100; cb_y=560; cb2_y=560; hb1x=cb_x+10; hb1y=cb_y+10; hb2x=cb2_x+40; hb2y=cb2_y+10; 
                for (int i=0; i<MAX_BALAS; i++){ bala1_ativo[i] = 0; bala2_ativo[i] = 0; } 
                cooldown1 = 0; cooldown2 = 0; vel_x_knock1 = 0.0; vel_x_knock2 = 0.0; vel_x_morte1 = 0.0; vel_y_morte1 = 0.0; morrendo1 = false; vel_x_morte2 = 0.0; vel_y_morte2 = 0.0; morrendo2 = false; 
                vel_y1 = 0.0; vel_y2 = 0.0; pulando1 = false; pulando2 = false; sangx1=cb_x-30; sangy1=cb_y+40; tem_chapeu1 = true; tem_chapeu2 = true; 
            } 
        }
    }
    EndDrawing();
}