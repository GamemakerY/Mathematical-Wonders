#define RAYGUI_IMPLEMENTATION
#include "raylib.h"
#include "raymath.h"
#include "raygui.h"
#include <iostream>
#include <random>
#include <vector>

const int screenWidth = 800;
const int panelHeight = 100;
const int screenHeight = 450+panelHeight;

int n = 3;
int i = 0;
bool start = false;
std::vector<Vector2> red_dots;
std::vector<Vector2> blue_dots = {};
Vector2 random_pos = {static_cast<float>(rand() % (screenWidth)), static_cast<float>(rand() % (screenHeight-panelHeight))};


Vector2 generate(int n, std::vector<Vector2> red_dots, Vector2 vec1){
        int pick = (rand() % n);
        Vector2 vec2 = red_dots[pick];
        Vector2 new_pos = Vector2Add(vec2, vec1)/2;
        return new_pos;
    };


void generate_dots(int n, std::vector<Vector2>& dots){
    dots.clear();
        for(int index=0; index<n; index++){
            Vector2 random_pos2 = {static_cast<float>(rand() % (GetScreenWidth())), static_cast<float>(rand() % (GetScreenHeight()-100))}; //panelHeight --> Manually used
            dots.push_back(random_pos2);
    };
}



int main(){


    InitWindow(screenWidth, screenHeight, "Chaos Game");
    //SetTargetFPS(60);

    srand(time(NULL));

    Rectangle uiBar = { 0, (float)GetScreenHeight() - panelHeight, (float)GetScreenWidth(), panelHeight};

    while (!WindowShouldClose()){

        BeginDrawing();

        if (GuiButton(Rectangle{20, uiBar.y+60, 100, 25 }, "Start")) {
            
            if(start==true) start=false;
            else start=true;
            generate_dots(n, red_dots);
            blue_dots.clear();
            
        }

        if(start){
            for (int j=0; j<=10; j++){
                    blue_dots.push_back(random_pos);
                    random_pos = generate(n, red_dots, random_pos);
            };
            for (const auto& pos : red_dots) {
                DrawCircleV(pos, 5, RED);
            }


        }

            DrawText("The Chaos Game!", (screenHeight/2) + 30, 0, 30, WHITE);

            ClearBackground(BLACK);


            DrawText(TextFormat("Points: %i", (int)blue_dots.size()), 10, 0, 30, GREEN);
            for (const auto&vec : blue_dots){
                DrawPixelV(vec, BLUE);
            }

            static float n_f = 3.0f;

            GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
            GuiGroupBox(uiBar, "CONTROLS");
            GuiDrawText("Initial Red Dots: ", Rectangle{150, uiBar.y+30, 200, 30}, TEXT_ALIGN_LEFT, WHITE);
            GuiSlider(Rectangle{ 150, uiBar.y + 60, (float)GetScreenWidth()-200, 20 }, "0", TextFormat("%i", n), &n_f, 2, 20);

            n = static_cast<int>(n_f);

            EndDrawing();}
        
        
        CloseWindow();
    return 0;
}
