#pragma once

#include "raylib.h"
#include <vector>

// --- ESTRUTURA  DA ELIPSE ---
struct CloudEllipse {
    Vector2 relativePos;
    float radiusX;
    float radiusY;
};

// --- CLASSE PARA O AGLOMERADO DE NUVENS ---
class CloudCluster {
public:
    Vector2 position;
    float speed;
    std::vector<CloudEllipse> ellipses;

    // --- CONSTRUTOR ---
    CloudCluster() {
        float startX = (float)GetRandomValue(0, GetScreenWidth());
        float startY = (float)GetRandomValue(30, 200);
        this->position = {startX, startY};

        // --- VELOCIDADE ---
        // Pega um valor entre 5 e 20 e divide por 10.0
        // para conseguir um float (ex: 0.5, 0.6, ..., 2.0)
        this->speed = (float)GetRandomValue(5, 20) / 10.0f;

        int ellipseCount = GetRandomValue(3, 8);

        for (int i = 0; i < ellipseCount; i++) {
            CloudEllipse ellipse;

            // --- TAMANHO ---
            ellipse.relativePos = {
                (float)GetRandomValue(-75, 75),
                (float)GetRandomValue(-20, 20) 
            };

            // --- TAMANHO  ---
            ellipse.radiusX = (float)GetRandomValue(25, 150) / 2.0f;
            ellipse.radiusY = (float)GetRandomValue(15, 50) / 2.0f;

            this->ellipses.push_back(ellipse);
        }
    }

    // --- ATUALIZAÇÃO ---
    void Update() {
        position.x += speed;

        if (position.x > GetScreenWidth() + 250) {
            position.x = -250;
            position.y = (float)GetRandomValue(30, 200);
            
            // --- VELOCIDADE ---
            // Sorteia nova velocidade ao dar a volta
            this->speed = (float)GetRandomValue(2, 12) / 10.0f;
        }
    }

    // --- DESENHO ---
    void Draw() {
        for (const auto& ellipse : ellipses) {
            float drawX = position.x + ellipse.relativePos.x;
            float drawY = position.y + ellipse.relativePos.y;

            DrawEllipse(drawX, drawY, ellipse.radiusX, ellipse.radiusY, CLITERAL(Color){ 255, 255, 255, 240 });
        }
    }
};